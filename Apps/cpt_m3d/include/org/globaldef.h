#if ! defined(_GLOBALDEF_)
#define _GLOBALDEF_


// initial window size ratios over the whole display size
// when the window resolution is less than 1000 pixels
const float INIT_WINDOW_XRATIO	= 0.75;
const float INIT_WINDOW_YRATIO	= 0.75;

// initial window size of the main frame
const int MAIN_FRAME_X	=	1000;
const int MAIN_FRAME_Y	=	638;

// initial window size of the main simulation view
const int SIM_VIEW_X	=	615;
const int SIM_VIEW_Y	=	428;

// initila window size of the odor view 
const int ODOR_VIEW_X	=	615;
const int ODOR_VIEW_Y	=	210;

// the statusbar properties
const int sbar_height	= 18;

// the behavior rectangle size, ratio proportion to the window size
// adjust this ratio to adapt to any changes
const double WIDTHRATIO	= 0.19;
const double HEIGHTRATIO	= 0.10;

// behavior sub level number
//const int MAXCHILDREN  = 3;
const int MAXCHILDREN  = 4;

// current behavior possibilities
const int CURRENTPOSS	= 7;

// first behavior definition
const char FIRST_BEHAVIOR	= 'G';

/////////////////////////////////////////////////

// if slow down the thread, specify the millsec to sleep
const int SLOW_MILLISEC	= 10;

// if computation speed is above normal(see above), you may need yield
// some time to the user interface thread

// after yield_interval times of computation, the thread yields.
const int yield_interval = 30;
// how many millisec to yield
const int yield_time	 = 1;


// definition for queue in behavior drawing
const int queue_max	= 3;

// definition for queue in vehicle status recording
const int max_points = 100;


#endif // _GLOBALDEF_