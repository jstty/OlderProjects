//////////////////////////////////////////////////////////////////////////////
// Program Name:  level_title.cpp
// Programmer:    Joseph E. Sutton
// Description:	Level Title
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "level_title.h"
#include "sds.h"
extern SuperShooter *sds;

LevelTitle::LevelTitle()
{
   bkg_offset = new float[STAR_MAX_LEVEL];
   bkg_pt_size = new uInt8[STAR_MAX_LEVEL];
   bkg_ln_length = new uInt8[STAR_MAX_LEVEL];
}

LevelTitle::~LevelTitle()
{
   if(bkg_offset != NULL)     delete bkg_offset;
   if(bkg_pt_size != NULL)    delete bkg_pt_size;
   if(bkg_ln_length != NULL)  delete bkg_ln_length;
}

void LevelTitle::Init(uInt32 data)
{
   lScore = 0;

   bkg_offset[0] = 0;
   bkg_offset[1] = 0;
   bkg_offset[2] = 0;

   bkg_pt_size[0] = 1;
   bkg_pt_size[1] = 2;
   bkg_pt_size[2] = 3;
   bkg_ln_length[0] = 10;
   bkg_ln_length[1] = 15;
   bkg_ln_length[2] = 30;
   UpdateStars(0, 0);
   UpdateStars(0, 1);
   UpdateStars(0, 2);
   UpdateStars(1, 0);
   UpdateStars(1, 1);
   UpdateStars(1, 2);

   level_over = false;
   DisplayLoading = false;
   DoneDisplayLoading = false;

   music.LoadMidi("sound\\title.mid", 0);

   info.SetFont(GLUT_BITMAP_9_BY_15, 15);
   info.SetJustify(GLUT_TEXT_RIGHT | GLUT_TEXT_TOP);
   info.SetColor(1.0, 0.0, 0.0);
}

void LevelTitle::Exit(uInt32 data)
{
   music.Close();
}


void LevelTitle::Draw()
{
   if( !DisplayLoading )
   {
      DrawShootingStars();

      y = 260;
      x = 140;
      info.SetColor(1.0, 1.0, 0.0);
      info.SetText("You mission is to destroy as many enemy");
      info.SetPos(x, y);
      info.Draw();

      y -= 15;
      info.SetText("UFO's as possible. ");
      info.SetPos(x, y);
      info.Draw();


      y -= 30;
      info.SetColor(0.0, 1.0, 0.0);
      info.SetText("SPACEBAR Key or Left Mouse Button - Laser");
      info.SetPos(x, y);
      info.Draw();

      y -= 15;
      info.SetColor(0.0, 1.0, 0.0);
      info.SetText("M Key or Right Mouse Button - Missle");
      info.SetPos(x, y);
      info.Draw();

      y -= 30;
      info.SetColor(1.0, 0.0, 0.0);
      info.SetText("Press ESC to Quit to Windows.");
      info.SetPos(x, y);
      info.Draw();

      y -= 30;
      info.SetColor(1.0, 0.0, 1.0);
      info.SetText("Press ENTER to start.");
      info.SetPos(x, y);
      info.Draw();


      DrawTitle();
   }
   else
   {
      info.SetText("Loading Level...");
      info.SetPos(320, 260);
      info.SetFont(GLUT_BITMAP_9_BY_15, 15);
      info.SetJustify(GLUT_TEXT_CENTER | GLUT_TEXT_MID);
      info.SetColor(1.0, 1.0, 0.0);
      info.Draw();

      DoneDisplayLoading = true;
   }
}


void LevelTitle::Idle()
{
   if(DoneDisplayLoading)
      level_over = true;
   else
      MoveStars();
}

void LevelTitle::PlayMusic()
{
   music.Play();
}

void LevelTitle::StopMusic()
{
   music.Stop();
}

void LevelTitle::KeyPressed(bool down,  bool skey, int key, int x, int y)
{
   if( down )
   {
      if( key == 13)
      {
         DisplayLoading = true;
      }
   }
}


void LevelTitle::MouseClick(bool down, int button, int x, int y)
{
}


void LevelTitle::MouseMoved(int x, int y)
{
   
}

#define TITLE_POINT(P1, P2) glVertex2i(x + P1*seg_length, y + P2*seg_length);
void LevelTitle::DrawTitle()
{
   glColor3f(1.0, 0.0, 0.0);
   glLineWidth(2);

   int seg_length = 10;
   int xc = 140;
   int yc = 380;

   x = xc;
   y = yc;
   // SUPER SHOOTER

   // S
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(2, 0);
      TITLE_POINT(2, 2);
      TITLE_POINT(0, 2);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
   glEnd();

   // U
   x += 3*seg_length;
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 4);
      TITLE_POINT(0, 0);
      TITLE_POINT(2, 0);
      TITLE_POINT(2, 4);
   glEnd();
   
   x += 3*seg_length;
   // P
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
      TITLE_POINT(2, 2);
      TITLE_POINT(0, 2);
   glEnd();


   x += 3*seg_length;
   // E
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(2, 4);
      TITLE_POINT(0, 4);
      TITLE_POINT(0, 0);
      TITLE_POINT(2, 0);
   glEnd();

   x += 3*seg_length;
   // R
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
      TITLE_POINT(2, 2);
      TITLE_POINT(0, 2);
      TITLE_POINT(2, 0);
   glEnd();
   

   // S
   x += 5*seg_length;
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(2, 0);
      TITLE_POINT(2, 2);
      TITLE_POINT(0, 2);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
   glEnd();

   // H
   x += 3*seg_length;
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(0, 4);
   glEnd();
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(2, 0);
      TITLE_POINT(2, 4);
   glEnd();

   x += 3*seg_length;
   // O
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
      TITLE_POINT(2, 0);
      TITLE_POINT(0, 0);
   glEnd();

   x += 3*seg_length;
   // O
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
      TITLE_POINT(2, 0);
      TITLE_POINT(0, 0);
   glEnd();

   // T
   x += 3*seg_length;
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(1, 0);
      TITLE_POINT(1, 4);
   glEnd();
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
   glEnd();

   x += 3*seg_length;
   // E
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(2, 4);
      TITLE_POINT(0, 4);
      TITLE_POINT(0, 0);
      TITLE_POINT(2, 0);
   glEnd();

   x += 3*seg_length;
   // R
   glBegin(GL_LINE_STRIP);
      TITLE_POINT(0, 0);
      TITLE_POINT(0, 4);
      TITLE_POINT(2, 4);
      TITLE_POINT(2, 2);
      TITLE_POINT(0, 2);
      TITLE_POINT(2, 0);
   glEnd();
}

void LevelTitle::DrawShootingStars()
{
   for(level=0; level < STAR_MAX_LEVEL; level++)
   {
      glLineWidth(bkg_pt_size[level]);

      glBegin(GL_LINES);
      for(i=0; i < STAR_MAX_PTS; i++)
      {
         glColor4f(0.5, 0.5, 0.5, 0.0);
         glVertex2i(bkg_offset[level] + bkg[0][level][i][0], bkg[0][level][i][1]);
         glColor4f(0.0, 0.0, 0.0, 1.0);
         glVertex2i(bkg_ln_length[level] + bkg_offset[level] + bkg[0][level][i][0], bkg[0][level][i][1]);

         glColor4f(0.5, 0.5, 0.5, 0.0);
         glVertex2i(MAX_WIDTH + bkg_offset[level] + bkg[1][level][i][0], bkg[1][level][i][1]);
         glColor4f(0.0, 0.0, 0.0, 1.0);
         glVertex2i(bkg_ln_length[level] + MAX_WIDTH + bkg_offset[level] + bkg[1][level][i][0], bkg[1][level][i][1]);
      }
      glEnd();
   }
}

void LevelTitle::MoveStars()
{
   bkg_offset[0] -= BACKGROUND_OFFSET1_SPEED;
   bkg_offset[1] -= BACKGROUND_OFFSET2_SPEED;
   bkg_offset[2] -= BACKGROUND_OFFSET3_SPEED;

   for(level=0; level < STAR_MAX_LEVEL; level++)
   {
      if( bkg_offset[level] <= -(MAX_WIDTH + bkg_ln_length[2]) )
      {
         bkg_offset[level] += MAX_WIDTH;
         memcpy(bkg[0][level], bkg[1][level], sizeof(uInt16)*STAR_MAX_PTS*2);
         UpdateStars(1, level);
      }
   }
}

void LevelTitle::UpdateStars(uInt8 bkgn, uInt8 ln)
{
   if(bkgn == 0 || bkgn == 1)
   {
      x = MAX_WIDTH;
      y = MAX_HEIGHT;
      
      for(i=0; i < STAR_MAX_PTS; i++)
      {
         bkg[bkgn][ln][i][0] = rand()%x;
         bkg[bkgn][ln][i][1] = rand()%y;
      }
   }
}