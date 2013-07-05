/****************************************
 filename:    astar.cpp
 description: 
 project:     astar
 created by:  Joseph E. Sutton
 version:   
 
 ****************************************/

#include "global.h"

bool Astar_Node::operator>(const Astar_Node& o) const
{
   if((state->G + state->H) >
      (o.state->G + o.state->H)) return true;
   else                          return false;
}

bool Astar_Node::operator<(const Astar_Node& o) const
{
   if((state->G + state->H) <
      (o.state->G + o.state->H)) return true;
   else                          return false;
}

Astar::Astar(Map *m, bool a, bool b, bool sg, bool v, bool showts)
{
   map = m;
   
   Adaptive     = a;
   Backwards    = b;
   useSmallerG  = sg;
   Verbose      = v;
   showTimeStep = showts;
   
   searchUpdate = false;
   searchCount = 0;
   timeStep = 0;
   cellsExpanded = 0;
   
   width  = 0;
   height = 0;
   
   startX  = 0;
   startY  = 0;
   targetX = 0;
   targetY = 0;
   
   tmpState     = NULL;
   nextState    = NULL;
   currentState = new Astar_State();
   goalState    = new Astar_State();
   
   openList     = new Astar_OpenList;
   tieList      = new Astar_TieList;
   tree         = new Astar_State_Grid;
   pathToTarget = new Astar_Path;
   
   if(Adaptive)
      closedList = new Astar_ClosedList;
   else
      closedList = NULL;
}

Astar::~Astar()
{
   int i, j;
   
   // clear tree
   for(j = 0; j < height; ++j)
   {
      for(i = 0; i < width; ++i)
      {
         tmpState = (*tree)[i][j];
         if(tmpState != NULL)
         {
            delete tmpState;
            (*tree)[i][j] = NULL;
         }
      }
   }
   
   if(openList != NULL)     delete openList;
   if(tieList != NULL)      delete tieList;
   if(tree != NULL)         delete tree;
   if(pathToTarget != NULL) delete pathToTarget;
}

int Astar::Load(const char *filename)
{
   int d1, d2;
   FILE * fp = NULL;
   char *tmp = NULL;
   
      
   fp = fopen(filename, "r");
   if(fp == NULL)  return 1; // error could not load file
   
   fscanf(fp, "WIDTH = %d\n",     &d1);
   fscanf(fp, "HEIGHT = %d\n",    &d2);
   width  = (unsigned short)d1;
   height = (unsigned short)d2;
   
   fscanf(fp, "agent = %d,%d\n",  &d1, &d2);
   startX  = d1;
   startY  = d2;
   
   fscanf(fp, "target = %d,%d\n", &d1, &d2);
   targetX = d1;
   targetY = d2;
   
   if(tmp != NULL) delete tmp;
   if(fp  != NULL) fclose(fp);
   
   (*tree)[ startX][ startY] = currentState;
   currentState->mapXPos  = startX;
   currentState->mapYPos  = startY;
   currentState->H = Map::GetDistance(startX, startY, targetX, targetY);
   
   (*tree)[targetX][targetY] = goalState;
   goalState->mapXPos     = targetX;
   goalState->mapYPos     = targetY;
   goalState->H           = 0;
   
   return 0;
}

/*
 procedure ComputePath()
 while g(s_goal) > min_s' E OPEN(g(s') + h(s'))
   remove a state s with the smallest f-value g(s) + h(s) from OPEN;
   CLOSED := CLOSED U {s};
   for all actions a E A(s)
      if search(succ(s, a)) < counter
         g(succ(s, a)) := inf;
         search(succ(s, a)) := counter;
      if g(succ(s, a)) > g(s) + c(s, a)
         g(succ(s, a)) := g(s) + c(s, a);
         tree(succ(s, a)) := s;
         if succ(s, a) is in OPEN then remove it from OPEN;
         insert succ(s, a) into OPEN with f-value g(succ(s, a)) + h(succ(s, a));
*/
// does A* search
// if return > 0, failed
int Astar::ComputePath()
{
   pathLoop = 0;
   Astar_Node t1, t2;
   Astar_State *topState, *succState;
   
   // while g(s_goal) > min_s' E OPEN(g(s') + h(s'))
   // while not at goal or open list empty
   while(openList->size() > 0)
   {
      t1 = openList->top(); // peak at top
      openList->pop();      // remove t1
      
      tieList->clear();
      while(openList->size() > 0)
      {
         t2 = openList->top(); // peak at top
         openList->pop();      // remove t2
         
         if(t1.getF() == t2.getF())
         {
            // need to use tie breaker
            // set t1 to winner
            // set t2 to the looser 
            
            if(useSmallerG)
            {
               // infavor of lower G
               if(t2.state->G < t1.state->G)
               {
                  // swap
                  openItem = t1;
                  t1 = t2;
                  t2 = openItem;
               }
            } else {
               // infavor of higher G
               if(t2.state->G > t1.state->G)
               {
                  // swap
                  openItem = t1;
                  t1 = t2;
                  t2 = openItem;
               }
            }
            
            // push t2 onto tie list
            tieList->push_back(t2);
         } else {
            // push t2 onto tie list
            tieList->push_back(t2);
            // if not the same, then done check for tie breakers
            break;
         }
      }
      
      // push back all the ones taken out, except t1
      while(!tieList->empty())
      {
         t2 = tieList->front();
         tieList->erase(tieList->begin());
         
         // push tie item back onto open list
         openList->push(t2);
      }
      
      // CLOSED := CLOSED U {s};
      if(closedList != NULL)
      {
         closedList->push(t1);
      }
      // keep track of number of cells expanded
      ++cellsExpanded;
      
      // t1 not in OPEN any longer
      t1.state->inOpenList = false;
      // set topState
      topState  = t1.state;
      
      // for all actions a E A(s)
      succState = ProcessAction(topState, topState->mapXPos + 1, topState->mapYPos);
      if(succState == goalState) break;
      succState = ProcessAction(topState, topState->mapXPos - 1, topState->mapYPos);
      if(succState == goalState) break;
      
      succState = ProcessAction(topState, topState->mapXPos,     topState->mapYPos + 1);
      if(succState == goalState) break;
      succState = ProcessAction(topState, topState->mapXPos,     topState->mapYPos - 1);
      if(succState == goalState) break;
      // end foreach action
      
      pathLoop++;
   }
   // end while
   
   return 0;
}

Astar_State *Astar::ProcessAction(Astar_State *topState, unsigned short x, unsigned short y)
{
   Astar_State *succState;
   
   // make sure on map
   if(x >= width)  return NULL;
   if(y >= height) return NULL;
   
   // if not exist add it
   // do NOT getMapInfo
   CheckAction(0, x, y);
   succState = (*tree)[x][y];
      
   // if search(succ(s, a)) < counter
   //   g(succ(s, a)) := inf;
   //   search(succ(s, a)) := counter;
   // ensures has not touched this search
   if(succState->search < searchCount)
   {
      succState->G       = -1;
      succState->search  = searchCount;
   }
   
   // only is not blocked and
   // g(succ(s, a)) > g(s) + c(s, a)
   if( (!succState->isBlocked) && 
      (succState->G > (topState->G + 1)) )
   {
      // g(succ(s, a)) := g(s) + c(s, a);
      succState->G = topState->G + 1;
      
      // tree(succ(s, a)) := s;
      // link succState to topState
      succState->nextClosest = topState;
      
      // if succ(s, a) is in OPEN then remove it from OPEN;
      // insert succ(s, a) into OPEN with f-value g(succ(s, a)) + h(succ(s, a));
      // if not in OPEN then insert
      if(!succState->inOpenList)
      {
         /*
         if((timeStep == 25) && (pathLoop == 6))
         {
            // CRASH!!!
            // -i inputfile0.txt
            // large g, forwards
            openItem = openList->top();
            openList->pop(); // CRASH!!!
         }
         */
         
         openItem.state = succState;
         
         openList->push(openItem);
         succState->inOpenList = true;
      }
   }
   
   return succState;
}


/*
 procedure Main()
   counter := 0;
 
   for all states s in S
      search(s) := 0;
 
   while s_start != s_goal
      counter := counter + 1;
 
      g(s_start) := 0;
      search(s_start) := counter;
      g(s_goal) := inf;
      search(s_goal) := counter;
      
      OPEN := CLOSED := {empty};
      insert s_start into OPEN with f-value g(s_start) + h(s_start);
 
      ComputePath();
      
      if OPEN = {empty}
         print “I cannot reach the target.”; stop;
 
      follow the tree-pointers from s_goal to s_start and then move the agent along the resulting path 
         from s_start to s_goal until it reaches s_goal or one or more action costs on the path increase;
      set s_start to the current state of the agent (if it moved);
      update the increased action costs (if any);
   
   print “I reached the target.”;
   stop;
*/
int Astar::Run()
{
   while(currentState != goalState)
   {
      if( !Update() ){
         if(Verbose) printf("Could not find a path to target.\n");
         break;
      }
      
      //
      if( Verbose &&
          (searchUpdate || showTimeStep || (currentState == goalState))
        )
         PrintStep();
      
      //if(timeStep > 10) break;
      searchUpdate = false;
   }
   
   return 0;
}

/*
 counter := counter + 1;
 
 g(s_start) := 0;
 search(s_start) := counter;
 g(s_goal) := inf;
 search(s_goal) := counter;
 
 OPEN := CLOSED := {empty};
 insert s_start into OPEN with f-value g(s_start) + h(s_start);
 
 ComputePath();
 
 if OPEN = {empty}
 print “I cannot reach the target.”; stop;
 
 follow the tree-pointers from s_goal to s_start and then move the agent along the resulting path 
   from s_start to s_goal until it reaches s_goal or one or more action costs on the path increase;
 set s_start to the current state of the agent (if it moved);
 update the increased action costs (if any);
*/
bool Astar::Update()
{
   timeStep++;

   // move to next state
   if( (nextState != NULL) && (!nextState->isBlocked) )
   {
      // no longer on path
      currentState->isPathToTarget = false;
      
      // moves nextState to currentState, move next next to nextState
      currentState = nextState;
      
      if(pathToTarget->size() > 0)
      {
         nextState = pathToTarget->back();
         pathToTarget->pop_back();
      }
   }
   
   if(Backwards)
   {
      // swap current and goal state
      tmpState     = currentState;
      currentState = goalState;
      goalState    = tmpState;
      
      UpdateH(currentState);
      goalState->H    = 0;
      
      // add 4 actions to tree, if don't exist already
      // getMapInfo
      CheckAction(1, goalState->mapXPos + 1, goalState->mapYPos);
      CheckAction(1, goalState->mapXPos - 1, goalState->mapYPos);
      CheckAction(1, goalState->mapXPos,     goalState->mapYPos + 1);
      CheckAction(1, goalState->mapXPos,     goalState->mapYPos - 1);
   } else {
      // add 4 actions to tree, if don't exist already
      // getMapInfo
      CheckAction(1, currentState->mapXPos + 1, currentState->mapYPos);
      CheckAction(1, currentState->mapXPos - 1, currentState->mapYPos);
      CheckAction(1, currentState->mapXPos,     currentState->mapYPos + 1);
      CheckAction(1, currentState->mapXPos,     currentState->mapYPos - 1);
   }
   
   // if current state is blocked
   if( (nextState == NULL) || (nextState->isBlocked) )
   {
      searchUpdate = true;
      searchCount++;
      
      // unmark path to target in tree
      ClearPathToTarget();
      
      currentState->G      = 0;
      currentState->search = searchCount;
      goalState->G         = -1;
      goalState->search    = searchCount;
      
      // insert s_start into OPEN with f-value g(s_start) + h(s_start);
      openItem.state = currentState;
      openList->push(openItem);
      currentState->inOpenList = true;
      
      // Do A*
      ComputePath();
      
      // Could not find a path to target.
      if(openList->size() == 0) return false;
      
      // clear OPEN
      while(!openList->empty())
      {
         openItem = openList->top();
         openList->pop();
         openItem.state->inOpenList = false;
      }
      
      // updates path to target
      // mark path to target in tree
      UpdatePathToTarget();
      
      if(Backwards)
      {
         // swap current and goal state
         tmpState     = currentState;
         currentState = goalState;
         goalState    = tmpState;
         
         // UpdatePathToTarget addes current first so need to remove it
         pathToTarget->pop_back();
         // add goal at start
         pathToTarget->insert(pathToTarget->begin(), goalState);
      }
      
      // move current to next state
      // updates nextState
      nextState = pathToTarget->back();
      pathToTarget->pop_back();
      
      if(Adaptive && (closedList != NULL))
      {
         // update the increased h-values
         while(!closedList->empty())
         {
            openItem = closedList->top();
            closedList->pop();
            
            openItem.state->H = goalState->G - openItem.state->G;
         }
      }
   } else {
      if(Backwards)
      {
         // swap current and goal state
         tmpState     = currentState;
         currentState = goalState;
         goalState    = tmpState;
      }
   }   
   return true;
}

void Astar::CheckAction(bool getMapInfo, unsigned short x, unsigned short y)
{
   // add action points
   if( (x < width) && (y < height) )
   {
      tmpState = (*tree)[x][y];
      // if not exist add it
      if(tmpState == NULL)
      {
         tmpState =  new Astar_State();
         tmpState->mapXPos   = x;
         tmpState->mapYPos   = y;
         UpdateH(tmpState);
         
         if(getMapInfo)
            tmpState->isBlocked = map->isBlocked(x, y);
         
         (*tree)[x][y] = tmpState;
      } else {
         
         // if backwards, need to update H, because target(really current posistion) moved
         if(Backwards)
            UpdateH(tmpState);
         
         // exists but need to get map info
         if(getMapInfo)
            tmpState->isBlocked = map->isBlocked(x, y);
      }
   }
}

// updates path to target
void Astar::UpdatePathToTarget()
{
   for(tmpState = goalState;
       tmpState != currentState;
       tmpState = tmpState->nextClosest)
   {
      tmpState->isPathToTarget = true;
      
      if(Backwards)
      {
         // add state to stack
         pathToTarget->insert(pathToTarget->begin(), tmpState);
      } else {
         // add state to queue
         pathToTarget->push_back(tmpState); 
      }
   }
}

// unmark path to target in tree
void Astar::ClearPathToTarget()
{
   // clear stack
   pathToTarget->clear();
   
   for(tmpState = goalState->nextClosest; 
       tmpState != currentState;
       tmpState = tmpState->nextClosest)
   {
      if(tmpState == NULL) break;
      
      tmpState->isPathToTarget = false;
   }
}

void Astar::UpdateH(Astar_State *s)
{
   s->H = Map::GetDistance(s->mapXPos, s->mapYPos, goalState->mapXPos, goalState->mapYPos);
}

void Astar::PrintStep()
{
   int i, j;
   
   printf("The grid known to the agent with the shortest path after the search [%d] (time step: [%d]) is\n", 
          (int)searchCount, (int)timeStep);
   
   if((width > 9) || (height > 9))
   {
      printf("  ");
      for(i = 0; i < width; ++i)
      {
         printf("%.2d", i);
      }
      printf("\n");
      
      for(j = height-1; j >= 0; --j)
      {
         printf("%.2d", j);
         for(i = 0; i < width; ++i)
         {
            tmpState = (*tree)[i][j];
            if(tmpState != NULL)
            {
               if(tmpState == currentState) printf(" A");
               else if(tmpState == goalState   ) printf(" T");
               else if(tmpState->isBlocked     ) printf(" X");
               else if(tmpState->isPathToTarget) printf(" .");
               else                              printf("  "); 
            } else printf("  ");
         }
         printf("\n");
      }
      
   } else {
      printf(" ");
      for(i = 0; i < width; ++i)
      {
         printf("%d", i);
      }
      printf("\n");
      
      for(j = height-1; j >= 0; --j)
      {
         printf("%d", j);
         for(i = 0; i < width; ++i)
         {
            tmpState = (*tree)[i][j];
            if(tmpState != NULL)
            {
                    if(tmpState == currentState) printf("A");
               else if(tmpState == goalState   ) printf("T");
               else if(tmpState->isBlocked     ) printf("X");
               else if(tmpState->isPathToTarget) printf(".");
               else                              printf(" "); 
            } else printf(" ");
         }
         printf("\n");
      }
   }
   
   printf("\n");
   
}

// axuliry function
void Astar::GetNextStep(unsigned short &x, unsigned short &y)
{
   if(nextState != NULL)
   {
      x = nextState->mapXPos;
      y = nextState->mapYPos;
   }
}

// axuliry function
void Astar::Move(unsigned short x, unsigned short y)
{
   // TODO
}
