/****************************************
 filename:    astar.h
 description: 
 project:     astar
 created by:  Joseph E. Sutton
 version:   
 
 ****************************************/

#ifndef _ASTAR_
#define _ASTAR_

class Astar_State
{
public:
   unsigned long  search;     // search is used to know if a state has been expanded during the current search
   bool           inOpenList;
   bool           isPathToTarget; // only used when Verbose is enable, for printed output
   
   unsigned short mapXPos;
   unsigned short mapYPos;
   bool           isBlocked; // this is a blocked state
   
   // unsigned long F; // G + H
   unsigned long G; // distance from start to node, -1 == infinity
   unsigned long H; // Manhatten dististance to target

   Astar_State *nextClosest;
};

class Astar_Node {
public:
   Astar_State *state;
   
   unsigned long getF() { return state->G + state->H; }
   
   // used in priority queue sort
   bool operator>(const Astar_Node& o) const;
   bool operator<(const Astar_Node& o) const;
};

/*
// test priority_queue
class Astar_NodeList
{
private:
   vector<Astar_Node> *list;

public:
   Astar_OpenList()   { list = new vector<Astar_Open>; }
   bool       empty() { return list->empty(); }
   size_t     size()  { return list->size(); }
   Astar_Open top()   { return list->front(); }
   
   void push(Astar_Open item)
   {
      list->push_back(item);
      sort(list->begin(), list->end());
      
      //push_heap(list->begin(), list->end());
      //make_heap(list->begin(), list->end());
      //sort_heap(list->begin(), list->end());
   }
   
   void pop()
   {
      //pop_heap(list->begin(), list->end());
      list->erase(list->begin());
      
      //make_heap(list->begin(), list->end());
      //sort_heap(list->begin(), list->end());
   }
};
*/

typedef map<unsigned short, Astar_State * >   Astar_State_Map;
typedef map<unsigned short, Astar_State_Map > Astar_State_Grid;
typedef vector<Astar_Node >                   Astar_TieList;
typedef vector<Astar_State * >                Astar_Path;
typedef vector<Astar_Node >                   Astar_vNodeList;
typedef priority_queue<Astar_Node, Astar_vNodeList, greater<Astar_Node> > Astar_OpenList;
typedef priority_queue<Astar_Node, Astar_vNodeList, greater<Astar_Node> > Astar_ClosedList;

class Astar
{
protected:
   bool Adaptive, Backwards, useSmallerG, searchUpdate, Verbose, showTimeStep;

   int pathLoop;
   unsigned long  searchCount, timeStep, cellsExpanded, tmpH;
   unsigned short width, height;
   unsigned short tmpPos;
   unsigned short startX,  startY;  // agent
   unsigned short targetX, targetY; // target
   
   Astar_Node   openItem;
   Astar_State *tmpState;
   Astar_State *currentState;
   Astar_State *nextState;
   Astar_State *goalState;
   
   // openList is priority queue (use binary heap)
   Astar_OpenList   *openList;
   Astar_ClosedList *closedList;
   Astar_TieList    *tieList;
   
   // tree is a list of all the states that have been opened
   // also used as the knowladge base
   Astar_State_Grid *tree; 
   Astar_Path       *pathToTarget;
   
   // map of world, used for block detection
   Map *map;
   
   // does A* search
   // if return > 0, failed
   int ComputePath();
   
   // if not exist add it to tree
   void CheckAction(bool getMapInfo, unsigned short x, unsigned short y);
   // 
   Astar_State *ProcessAction(Astar_State *topState, unsigned short x, unsigned short y);
   
   // updates path to target
   void UpdatePathToTarget();
   // unmark path to target in tree
   void ClearPathToTarget();
   
   void UpdateH(Astar_State *s);
   
public:
   // Adaptive, Backwards, Verbose
   Astar(Map *m, bool a = true, bool b = false, bool sg = false, bool v = false, bool showts = false);
   
   ~Astar();
   
   // Num Of Searches
   unsigned long GetNumOfSearches()     { return searchCount; }
   unsigned long GetNumOfTimeSteps()    { return timeStep; }
   unsigned long GetNumOfCellsExpanded(){ return cellsExpanded; }
   
   // load configuration file
   int Load(const char *filename);
   // run whole search, stepping from start to goal
   int Run();
   void PrintStep();
   
   // move start posistion
   // call before Update()
   void Move(unsigned short x, unsigned short y);
   
   // runs A* for current step
   // returns if found path
   // call before GetNextStep()
   bool Update();
   
   // using tree gets next step should take
   // return is combined x, y. (x + y*width)
   // call after Update()
   void GetNextStep(unsigned short &x, unsigned short &y);
};

#endif // _ASTAR_
