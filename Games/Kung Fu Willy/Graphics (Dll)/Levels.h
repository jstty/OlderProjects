////////////////////////////////////////////////////////////////////////
//  Program Name: Levels.h
//  Programmer: Joseph Sutton
//  Description: DLL Levels Header File
//  Date:
////////////////////////////////////////////////////////////////////////

#define IDS_P1                          108
#define IDS_P1M                         109
#define IDS_P2                          120
#define IDS_P2M                         121
#define IDS_COM                         122
#define IDS_EB                          149
#define IDS_EBM                         151
#define IDS_P2DEAD                      158
#define IDS_P2MDEAD                     159
#define IDS_P1DEAD                      160
#define IDS_P1MDEAD                     161
#define MAXHIT		205

//DllImport GRAPHIC g;
DllImport PGRAPHIC pg;
DllImport LEVEL l;
DllImport int EnergyP1, EnergyP2;
DllImport double percent;
DllImport UINT ScreenW, ScreenH, MidX, MidY, GScreenW, GScreenH;
