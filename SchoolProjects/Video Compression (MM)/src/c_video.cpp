/****************************************
 filename:    c_video.cpp
 description: Video class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/
#include "global_include.h"

Video::Video(uInt16 w, uInt16 h, uInt16 f)
{
	ct2 = new Ct2();
	ct2->type = 0; // fast
   
   width = w;
   height = h;
   fps = f;
   
   uQ[0] = 1.0;
   uQ[1] = 1.0;

	numFrames = 0;
	Frames = NULL;
   
   seg = NULL;
   dct = NULL;
   
   numTextures = 4;
   displayTextures = NULL;
   currentFrame = 0;
   playState = 0;
   
   printEncoderInfo    = false;
   showMotionVectors   = false;
   showDDMotionVectors = false;
   showSegGrid         = false;
}

Video::~Video()
{
	Free();
}

void Video::Allocate()
{
	if(Frames == NULL)
   {
      Frames = new Frame[numFrames];

      seg = new Segmentation();
      seg->Allocate(numFrames);
      
      dct = new DCTEncoder();
      dct->Allocate(numFrames);
   }
}

void Video::Free()
{
	if(Frames != NULL) delete [] Frames;
   
	if(seg != NULL) delete seg;
   if(dct != NULL) delete dct;
   
   if(displayTextures != NULL) delete [] displayTextures;
}


void Video::SetQ(const float Q[NUM_LAYERS])
{
	uInt8  i;

	for(i = 0; i < NUM_LAYERS; ++i)
   {
   	rQ[i] = Q[i];
   	uQ[i] = pow(2, Q[i]);
   }
}

void Video::PrintInfo()
{
	printf("-----------------------------\n");
   printf("Video Info\n");
	printf("-----------------------------\n");
   printf("FileName: %s\n", filename);
	printf("Width:  %d\n", width);
   printf("Height: %d\n", height);
   printf("FPS:    %0.2f\n", fps);
   printf("Number of Frames: %d\n", numFrames);
   printf("Duration: %d sec\n", (uInt32)((float)numFrames/(float)fps));
   
   printf("Number of Layers: %d\n", NUM_LAYERS);
   
   uInt8 i;
   for(i = 0; i < NUM_LAYERS; ++i)
   {
   	printf("2^(%0.2f)[%d]: %0.2f\n", rQ[i], i, uQ[i]);
   }
   printf("-----------------------------\n");
   
}


int Video::LoadRaw(const char *fn)
{
	uInt16  i, c;
   uInt32  j, size, fileSize, frameSize;
   FILE   *fd;
   uInt8  *buffer, R,G,B,Y;
   
   strcpy(filename, fn);
   fd = fopen(filename, "rb");
   if(fd == NULL)
   {
   	printf("Could not load file: %s", filename);
      return 1;
   }
   
   // get file size
	fseek(fd , 0, SEEK_END);
	fileSize = ftell(fd);
	rewind(fd);

	//
   size = width*height;
   frameSize = size*NUM_COLORS*sizeof(uInt8);
	buffer = new uInt8[frameSize];
   
   //   
	numFrames = fileSize/frameSize;
   Allocate();
   
   printf("Loading Raw Video:\n ");
   for(i = 0; i < numFrames; i++)
   {
      Frames[i].Allocate(size);
         
      for(c = 0; c < NUM_COLORS; c++)
      {
         fread(buffer, sizeof(uInt8), size, fd);
         for(j = 0; j < size; ++j)
         {
            Frames[i].color[c].rawData[j] = buffer[j];
         }
      }
      
      // Create Y
      for(j = 0; j < size; ++j)
      {
      	R = Frames[i].color[0].rawData[j];
	      G = Frames[i].color[1].rawData[j];
         B = Frames[i].color[2].rawData[j];
         Y = (66*R + 129*G + 25*B) >> 8;
         Y += 16;
         
      	Frames[i].color[Y_INDEX].rawData[j] = Y;
      }
      
      printf(".");
   }
   /*
	for(i = 0; i < numFrames; i++)
   {
      Frames[i].Allocate(size);
		
      fread(buffer, sizeof(uInt8), frameSize, fd);
      for(j = 0; j < size; ++j)
  		{
      	for(c = 0; c < NUM_COLORS; c++)
   		{
   			Frames[i].color[c].rawData[j] = buffer[c*size + j];
			}
      }
      
      printf(".");
   }
   */
   
   printf("\n");

	delete [] buffer;
   fclose(fd);
   return 0;
}


int Video::Encode()
{
	int e = 0;
   printf("Encoding:\n");
   
	printf(" Initilize...\n");	
   //
   seg->SetFrameData(Frames);
   dct->SetFrameData(Frames);  // sets frame dqData for encoding

   printf(" Segment:\n  ");
   e = seg->Split();
   if(e) return e;
   
   // 1) copy segmintation data to dct size blocks
   // 2) convert blocks to DCT
   // 3) quantize DCT
   // 4) copies DCT/qdData to dqData
   printf(" Encode:\n  ");
   e = dct->Encode(seg->Frames);
   
	return e;
}

// decode data
int Video::Decode()
{
	int e = 0;
	printf("Decoding:\n ");
   e = dct->Decode();
   
	return e;
}


// save encoded data
int Video::SaveEncoded(const char *filename)
{
	int e = 0;
	FILE *fp;
   
	printf("Saving Encoding:\n ");

	//
	fp = fopen(filename, "wb");
	if(fp == NULL)
   {	
   	printf(" !!! Could not Create File: %s\n", filename);
   	return 1;
   }
   
	// width, height of each frame
   fwrite(&width, 1, sizeof(uInt16), fp);
   fwrite(&height, 1, sizeof(uInt16), fp);
   
   // number of frames
   fwrite(&numFrames, 1, sizeof(uInt16), fp);
   
   // Q's
   fwrite(uQ, NUM_LAYERS, sizeof(float), fp);
   
   // save DCT'd frames
	e = dct->Save(fp);
   
   fclose(fp);
   return e;
}

// load encoded data
int Video::LoadEncoded(const char *filename)
{
	int e = 0;
	FILE *fp;
   
	printf("Loading Encoding:\n ");

	//
	fp = fopen(filename, "rb");
	if(fp == NULL)
   {
   	printf(" !!! Could not Open File: %s\n", filename);
   	return 1;
   }

	// width, height of each frame
   fread(&width, 1, sizeof(uInt16), fp);
   fread(&height, 1, sizeof(uInt16), fp);
   
   // number of frames
   fread(&numFrames, 1, sizeof(uInt16), fp);

	// Allocate frame data
	Allocate();
   
   // sets frame dqData for decoding
   dct->SetFrameData(Frames);  
         
   // Q's
   fread(uQ, NUM_LAYERS, sizeof(float), fp);
   for(uInt8 i = 0; i < NUM_LAYERS; ++i)
   {
   	rQ[i] = log(uQ[i])/log(2);
   }
   

	// load DCT'd frames
	e = dct->Load(fp);
   
   fclose(fp);
   return e;
}


void Video::CreateDiff()
{
	uInt16 i;
   
	for(i = 0; i < numFrames; i++)
   {
      Frames[i].CreateDiff();
	}
}


void Video::DisplayInit(int argc, char *argv[])
{
	uInt8 i;

	glutInit(&argc, argv);
   glutInitWindowSize(width*2, height*2);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutCreateWindow("cs576: Project - Video Compression");
   
   glClearColor(0,0,0,0);
   gluOrtho2D(0, width*2, height*2, 0);
   
   // Init Textures
   displayTextures = new GLuint[numTextures];
   for(i = 0; i < numTextures; ++i)
   {
   	glGenTextures(1, &displayTextures[i]);
   }
   
   glMatrixMode(GL_MODELVIEW);
   
   glutDisplayFunc (Video::DisplayFunc);
   glutKeyboardFunc(Video::KeyboardFunc);
   glutTimerFunc(10, Video::TimerFunc, 0);
     
   // update Texture
   UpdateTextures();
   
   playState = 0;
   prevTime = glutGet(GLUT_ELAPSED_TIME);
}

void Video::DisplayLoop()
{
	glutMainLoop();
}

void Video::DisplayFunc()
{
	vid->Display();
}
void Video::KeyboardFunc(unsigned char key, int x, int y)
{
	vid->Keyboard(key, x, y);
}
void Video::TimerFunc(int extra)
{
	vid->Timer();
}

void Video::UpdateTextures()
{
	applyFrameToTexture(&(Frames[currentFrame]), 0, 0);
   applyFrameToTexture(&(Frames[currentFrame]), 1, 1);
   applyFrameToTexture(&(Frames[currentFrame]), 2, 2);
   applyFrameToTexture(&(Frames[currentFrame]), 3, 3);
}


void Video::Timer()
{
	currentTime = glutGet(GLUT_ELAPSED_TIME);
   
   if((currentTime - prevTime) > (1000.0/fps))
   {
   	prevTime = glutGet(GLUT_ELAPSED_TIME);
      
      if(playState == 1)
      {
      	// update Texture
      	UpdateTextures();
         
         currentFrame++;
         if(currentFrame >= numFrames) currentFrame = 0;
      }
      
      glutPostRedisplay();
   }
   
	glutTimerFunc(10, Video::TimerFunc, 0);
}


void Video::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

   // texture
   glEnable(GL_TEXTURE_2D);
   drawTextures();
   glDisable(GL_TEXTURE_2D);
   
   if(showMotionVectors)
   	drawMotionVectors();
      
   if(showDDMotionVectors)
   	drawDDMotionVectors();
   
   if(showSegGrid)
	   drawSegGrid();

	// draw text
	drawText();
   
   glFlush();
   glutSwapBuffers();
}


void Video::drawMotionVectors()
{
	glBegin(GL_LINES);
   	seg->DrawMotionVectors(currentFrame);
   glEnd();
}

void Video::drawDDMotionVectors()
{
	glBegin(GL_LINES);
   	seg->DrawDDMotionVectors(currentFrame);
   glEnd();
}


void Video::drawSegGrid()
{
	// gray grid
	glColor3f(0.3, 0.3, 0.3);	

	seg->DrawGrid();
}


void Video::drawText()
{
	char str[256], tmp[256];
	uInt16 y, startX, startY;
   startX = 25;
   startY = height + 25;
	y = 10;

	// white
   glColor3f(1, 1, 1);
   
   sprintf(str, "Q: %0.1f, %0.1f", rQ[0], rQ[1]);
   drawText(startX, startY + y, str);
   y += 20;
   
   sprintf(str, "Video: %d x %d, %0.1f fps, %d sec", width, height, fps, (uInt32)((float)numFrames/(float)fps));
   drawText(startX, startY + y, str);
   y += 20;
      
   sprintf(str, "Frame #: %d of %d (%0.1f sec)", currentFrame, numFrames, ((float)currentFrame/(float)fps));
   drawText(startX, startY + y, str);
   y += 20;
   
   if(playState)	sprintf(tmp, "Playing");
	else	         sprintf(tmp, "Paused");
   sprintf(str, "State: %s", tmp);
   drawText(startX, startY + y, str);
   y += 20;


	// ----------------------------------------------
	// Menu
	sprintf(str, "Menu:");
   drawText(startX, startY + y, str);
   y += 20;
   
   sprintf(str, "Space - Play/Pause");
   drawText(startX+20, startY + y, str);
   y += 20;
   
   sprintf(str, "> - Next Frame");
   drawText(startX+20, startY + y, str);
   y += 20;
   
   sprintf(str, "< - Prev Frame");
   drawText(startX+20, startY + y, str);
   y += 20;
   
   if(printEncoderInfo)
   {
      sprintf(str, "m - Show Motion Vectors");
      drawText(startX+20, startY + y, str);
      y += 20;
      
      sprintf(str, "d - Show Motion Vectors Difference");
      drawText(startX+20, startY + y, str);
      y += 20;
      
      sprintf(str, "g - Show Segmentation Grid");
      drawText(startX+20, startY + y, str);
      y += 20;
   }
   
   
   sprintf(str, "ESC - Exit/Close");
   drawText(startX+20, startY + y, str);
   y += 20;
	

   // ----------------------------------------------
}


void Video::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
   {
		case ASCII_ESC:
      {
         exit(0);
         break;
      }
      
      // toggle play, pause
      case ' ':
      {
         if(playState) playState = 0;
         else			  playState = 1;
         
         break;
      }
      
      // step next frame
      case '>':
      case '.':
      {
         currentFrame++;
         if(currentFrame >= numFrames) currentFrame = 0;
         
         // update Texture
      	UpdateTextures();
         
         break;
      }
      
      // step previous frame
      case '<':
      case ',':
      {
         currentFrame--;
         if(currentFrame < 0) currentFrame = numFrames - 1;
         
         // update Texture
      	UpdateTextures();
         
         break;
      }
      
      // show motion vectors
      case 'm':
      case 'M':
      {
      	if(showMotionVectors) showMotionVectors = false;
         else                  showMotionVectors = true;
         break;
      }
      
      // show diff motion vectors
      case 'd':
      case 'D':
      {
      	if(showDDMotionVectors) showDDMotionVectors = false;
         else                    showDDMotionVectors = true;
         break;
      }
      
      // show segmentation grid
      case 'g':
      case 'G':
      {
	      if(showSegGrid) showSegGrid = false;
         else            showSegGrid = true;
         break;
      }
      
      
	}
}


void Video::applyFrameToTexture(Frame *f, uInt8 textureID, uInt8 type)
{
   uInt8 *tmp, c;
	int x, y, j, pos;
   
   if(textureID >= numTextures) return; // error
   
   tmp = new uInt8[width*height*3];
   
   glBindTexture(GL_TEXTURE_2D, displayTextures[textureID]);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   
   j = 0;
	for(y = 0; y < height; ++y)
   {
      for(x = 0; x < width; ++x)
      {
         pos = y*width + x;
      	
         // Raw frames
         if(type == 0)
         {
            tmp[j+0] = f->color[0].rawData[pos];
            tmp[j+1] = f->color[1].rawData[pos];
            tmp[j+2] = f->color[2].rawData[pos];
         }
         // Quantized Data
         else if(type == 1)
         {
            tmp[j+0] = f->color[0].qdData[pos];
            tmp[j+1] = f->color[1].qdData[pos];
            tmp[j+2] = f->color[2].qdData[pos];
         }
         // info area
         else if(type == 2)
         {
         	c = 25;
            tmp[j+0] = c;
            tmp[j+1] = c;
            tmp[j+2] = c;
         }
         // diff
         else if(type == 3)
         {
         	c = (f->color[0].diffData[pos] + 
	              f->color[1].diffData[pos] + 
                 f->color[2].diffData[pos]);
            tmp[j+0] = c;
            tmp[j+1] = c;
            tmp[j+2] = c;
         }
         
        	j += 3;
      }
   }
   
   glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tmp);
   
   delete [] tmp;
}


void Video::drawTextures(uInt8 start)
{
   uInt16 x, y, i;
   uInt16 tw, th;
   
   //tw = 127;
   //th = 127;
   tw = int(width);
   th = int(height);
   
   glColor3f(1, 1, 1);
   
   i = start;
   for(y = 0; y < 2*th; y+=th)
   {
   	for(x = 0; x < 2*tw; x+=tw)
      {
         glBindTexture(GL_TEXTURE_2D, displayTextures[i]);
         glPushMatrix();
         
         glBegin(GL_QUADS);
            glTexCoord2f(0,1);
            glVertex2f(x, y + th);
            
            glTexCoord2f(1,1);
            glVertex2f(x + tw, y + th);
            
            glTexCoord2f(1,0);
            glVertex2f(x + tw, y);
            
            glTexCoord2f(0,0);
            glVertex2f(x, y);
         glEnd();
         
         glPopMatrix();
         i++;
      }
   }
}

void Video::drawText(uInt16 x, uInt16 y, char *str)
{
   uInt16 i, size;
   uInt32 sx;
   //void *font = GLUT_BITMAP_8_BY_13;
	void *font = GLUT_BITMAP_HELVETICA_12;
      
   sx = 0;
   size = strlen(str);
   for(i = 0; i < size; ++i)
   {
      glRasterPos2f(x + sx, y);
      
      glutBitmapCharacter(font, str[i]);
      
      sx += glutBitmapWidth(font, str[i]);
      //sx += 4;
   }
}
