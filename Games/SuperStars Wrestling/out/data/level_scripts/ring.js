/*
///////////////////////////////////////////////////
Player Object:
 xpos      [int]  [rw]
 ypos      [int]  [rw]
 zpos      [int]  [rw]

 state     [int]  [rw]
 attack    [int]  [r]
 col_type  [int]  [r]

 vdir      [bool] [rw]
 hdir      [bool] [rw]

 joy_up    [bool] [r]
 joy_down  [bool] [r]
 joy_left  [bool] [r]
 joy_right [bool] [r]
 joy_b1	  [bool] [r]
 joy_b2	  [bool] [r]
 joy_b3    [bool] [r]

 is_slave  [bool] [r]

 walkspeed [int]  [r]
 runspeed  [int]  [r]
 drapspeed [int]  [r]

 target    [Player Object] [r]
  
 prev_state [int] [rw]
 prev_vdir  [int] [rw]
 prev_hdir  [int] [rw]

 anim       [string] [rw]             // name of animation sequence
 anim_done  [bool]   [r]              // Animation completed
 frame      [int]    [rw]
 frame_done [bool]   [r]

 function AnimStep()                  // move to next animation frame
 function AnimSelect([string], [int]) // change animation seq. and start frame
 function AnimPlay();
 function AnimPause();
 
 slave [Player Object] [rw]
 zone  [Zone Object]   [r]

 hp          [int] [rw]
 hp_max      [int] [rw]
 stamina     [int] [rw]
 stamina_max [int] [rw]

 ss      [int] [rw] super star
 flags   [int] [rw] move checks

 draw_order [int] [rw] Draw Order
								0(self,  slave),
								1(self,  slave, layer),
								2(layer, slave,  self)

 // TODO
 col     [Wrestler Collision Object] [r]

///////////////////////////////////////////////////

///////////////////////////////////////////////////
Zone Object:
	collidable     [bool] [rw]

	current        [int]  [rw]
	previous       [int]  [r]
	changed        [bool] [r]

	line_collided  [bool] [r]
	line_num       [int]  [r]
	line_threshold [int]  [rw]
///////////////////////////////////////////////////
*/


/*
// TODO
// Player Manager Class or array or players
// Level Class, load custom gfx
// called once
function RingInit()
{
}
*/


// called once
function PlayerInit(p)
{
	p.ts = 1;      // temp state
	p.pts = p.ts;  // temp prev state
	UpdateFocus(p);
   ProcessState(p);
}


// after collision detection
function PlayerPostUpdate(p)
{
}

// called by app
// before collision detection
function PlayerPreUpdate(p)
{
   p.prev_vdir = p.vdir;
   p.prev_hdir = p.hdir;

	p.pts = p.ts;
   // default STANDING
   p.ts = 1;

   if( p.joy_up )
   {
      p.vdir = false;
      p.ts = 2;

      p.zpos -= p.walkspeed;
   }
   else if( p.joy_down )
   {
      p.vdir = true;
      p.ts  = 2;

      p.zpos += p.walkspeed;
   }
   
   if( p.joy_left )
   {
      p.hdir = false;
      p.ts = 2;

      p.xpos -= p.walkspeed;
   }
   else if( p.joy_right )
   {
      p.hdir = true;
      p.ts = 2;

      p.xpos += p.walkspeed;
   }  

   UpdateFocus(p);
   ProcessState(p);
}


function UpdateFocus(p)
{
   if(p.xpos < p.target.xpos)
      p.hdir = true;
   else
      p.hdir = false;

   // prejeduce to facing down
   if(p.zpos < (p.target.zpos + 10))
      p.vdir = true;
   else
      p.vdir = false;
}

//
function ProcessState(p)
{
   // walking
   if(p.ts == 2)
   {
      if( (p.pts != p.ts) ||
          (p.prev_hdir != p.hdir) ||
          (p.prev_vdir != p.vdir)
        ) {
         Walk(p);
			p.AnimPlay();
      } else {
         p.AnimStep();
      }
   }
   // standing
   else if(p.ts == 1)
   {
      if( (p.pts != p.ts) ||
          (p.prev_hdir != p.hdir) ||
          (p.prev_vdir != p.vdir)
        ) {
         Stand(p);
      } else {
         //do nothing
      }
   }
}

function Walk(p)
{
   if(!p.hdir && !p.vdir) {  // up, left
      // p.AnimSelect("walk_u_l");
		p.anim = "walk_u_l";
   } else 
   if(!p.hdir && p.vdir) {  // down, left
      // p.AnimSelect("walk_d_l");
		p.anim = "walk_d_l";
   } else 
   if(p.hdir && !p.vdir) {  // up, right
      // p.AnimSelect("walk_u_r");
		p.anim = "walk_u_r";
   } else 
   if(p.hdir && p.vdir) {  // down, right
      // p.AnimSelect("walk_d_r");
		p.anim = "walk_d_r";
   }
}

function Stand(p)
{
   if(!p.hdir && !p.vdir) {  // up, left
      p.AnimSelect("stand_u_l");
   } else 
   if(!p.hdir && p.vdir) {  // down, left
      p.AnimSelect("stand_d_l");
   } else 
   if(p.hdir && !p.vdir) {  // up, right
      p.AnimSelect("stand_u_r");
   } else 
   if(p.hdir && p.vdir) {  // down, right
      p.AnimSelect("stand_d_r");
   }
}

