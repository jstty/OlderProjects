//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_gl_view.cpp
// Programmer:		Joseph E. Sutton
// Description:	CPTS OpenGL View Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/cpts.h"
extern CPTS *cpts;
extern CptsSettings *settings;


CptsGlView::CptsGlView()
{
   width  = 1024;
   height = 768;
   mTopViewHeight = 170;
   mRightViewWidth = 170;
   
   g = NULL;
   i = NULL;
      
   w = NULL;
   p = NULL;
   
   v = NULL;
   s = NULL;
}

CptsGlView::~CptsGlView()
{
   if(g != NULL)     delete g;
   if(i != NULL)     delete i;
      
   if(w != NULL)     delete w;
   if(p != NULL)     delete p;
   
   if(v != NULL)     delete v;
   if(s != NULL)     delete s;
}

void CptsGlView::Init()
{
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   glutInitWindowSize(width, height);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("CPTS");
   
   //
   glClearColor(
      settings->color.main_bkg[0]/255.0f,
      settings->color.main_bkg[1]/255.0f,
      settings->color.main_bkg[2]/255.0f,
      0.0f);
      
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_SCISSOR_TEST);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   //
   
   SetMainView();
   
   // grid
   g = new GlGrid();
   g->Init();
   g->SetColor(settings->color.grid_front, 
               settings->color.grid_mid, 
               settings->color.grid_back);
   
   // info
   i = new GlInfo();
   i->Init();
   i->SetSize(mRightViewWidth, height - mTopViewHeight);
   
   // wind
   w = new GlWind();
   w->Init();
   w->SetMax(settings->max);
   w->SetColor(settings->color.wind);
   
   // plume
   p = new GlPlume();
   p->Init();
   p->SetMax(settings->max);
   p->SetColor(settings->color.chem);
   
   // vehicle
   v = new GlVehicle();
   v->Init();
   v->SetMax(settings->max);
   
   // sensor
   s = new GlSensor();
   s->Init();
   s->SetTimeRate(settings->loop_rate);
   s->SetSize(width, mTopViewHeight);
}

void CptsGlView::Loop()
{
   w->Loop(); // wind
   p->Loop(); // plume
   
   v->Loop(); // vehicle
   s->Loop(); // sensor
   
   g->Loop(); // grid
   i->Loop(); // info
}

void CptsGlView::SetMainView()
{
   //
   glViewport(0,0, width - mRightViewWidth, height - mTopViewHeight);
   glScissor (0,0, width - mRightViewWidth, height - mTopViewHeight);
   glLoadIdentity();
   
   // 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
   gluPerspective(
      40.0f,
      (GLfloat)(width - mRightViewWidth)/(GLfloat)(height - mTopViewHeight),
      0.5f,
      1000.0f);
   //
   
   //
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   gluLookAt(0, 0, 1, 
             0, 0, 0,
             0, 1, 0);
   
   glClearColor(
      settings->color.main_bkg[0]/255.0f,
      settings->color.main_bkg[1]/255.0f,
      settings->color.main_bkg[2]/255.0f,
      0.0f);
   
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void CptsGlView::SetTopView()
{
   //
   glViewport(0, height - mTopViewHeight, width, mTopViewHeight);
   glScissor (0, height - mTopViewHeight, width, mTopViewHeight);
   glLoadIdentity();
   
   //
   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
   glOrtho(0, width, mTopViewHeight, 0, 0, 1000);

   //
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   gluLookAt(0, 0, 1, 
             0, 0, 0,
             0, 1, 0);
   
   glClearColor(
      settings->color.top_bkg[0]/255.0f,
      settings->color.top_bkg[1]/255.0f,
      settings->color.top_bkg[2]/255.0f,
      0.0f);
   
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void CptsGlView::SetRightView()
{
   //
   glViewport(width - mRightViewWidth, 0, mRightViewWidth, height - mTopViewHeight);
   glScissor (width - mRightViewWidth, 0, mRightViewWidth, height - mTopViewHeight);
   glLoadIdentity();
   
   //
   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
   glOrtho(0, mRightViewWidth, height - mTopViewHeight, 0, 0, 1000);

   //
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   gluLookAt(0, 0, 1, 
             0, 0, 0,
             0, 1, 0);
   
   glClearColor(
      settings->color.right_bkg[0]/255.0f,
      settings->color.right_bkg[1]/255.0f,
      settings->color.right_bkg[2]/255.0f,
      0.0f);
   
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void CptsGlView::Display()
{
   glMatrixMode(GL_MODELVIEW);
   
   //
   cpts->UpdateCamVector(cam);
   
   // Main View
   SetMainView();
   /*
   glPushMatrix();
      cpts->GetInfo(info);
      glTranslatef(-240, 170, -500);
      text->SetText(info);
      text->Draw();
   glPopMatrix();
   */
   
	glPushMatrix();
      glTranslatef(cam.x, cam.y, cam.z - 200.0);

      glRotatef(-cam.xrot , 1.0, 0.0, 0.0);
      glRotatef(-cam.yrot , 0.0, 1.0, 0.0);
      glRotatef(-0.0 , 0.0, 0.0, 1.0);

      // display
      w->Display(); // wind
      p->Display(); // plume
      v->Display(); // vehicle
      g->Display(); // grid
   glPopMatrix();
   //

   // Top View
   SetTopView();
   glPushMatrix();
      // sensor
      s->Display();
      //
   glPopMatrix();
   
   // Right View
   SetRightView();
   glPushMatrix();
      // info
      i->Display();
      //
   glPopMatrix();

   //
   glFlush();
   glutSwapBuffers();
   glutPostRedisplay();
}

void CptsGlView::Refresh()
{
   glutPostRedisplay();
}

void CptsGlView::WindowResized(int w, int h)
{
   width = w;
   height = h;
   
   // update sensor size
   if(s != NULL) s->SetSize(width, mTopViewHeight);
   if(i != NULL) i->SetSize(mRightViewWidth, height - mTopViewHeight);
}

void CptsGlView::SetEnvData(iEnvData *edata)
{
   ed = edata;
   if(w != NULL)  w->SetEnvData(edata); // wind
   if(p != NULL)  p->SetEnvData(edata); // plume
   if(s != NULL)  s->SetEnvData(edata); // sensor
   if(i != NULL)  i->SetEnvData(edata); // info
}

void CptsGlView::SetVehicleData(iVehicleData *vdata)
{
   vd = vdata;   
   if(v != NULL)  v->SetVehicleData(vdata); // vehicle
   if(s != NULL)  s->SetVehicleData(vdata); // sensor
   if(i != NULL)  i->SetVehicleData(vdata); // info
}

