//////////////////////////////////////////////////////////////////////////////
// Program Name:  sprite.cpp
// Programmer:    Joseph E. Sutton
// Description:	Sprint
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "sprite.h"

SpriteData::SpriteData()
{
   w = 0;
   h = 0;

   data = NULL;
   pts_num = NULL;
   pts_off[0] = NULL;
   pts_off[1] = NULL;
}

SpriteData::~SpriteData()
{
   if(data != NULL)
   {
      for(i = 0; i < size; i++)
      {
         if(data[i] != NULL)
         {
            tsize = 2*pts_num[i];
            for(k = 0; k < tsize; k++)
            {
               if(data[i][k] != NULL) delete [] data[i][k];
            }
            delete [] data[i];
         }
      }

      delete [] data;
   }

   if(pts_num != NULL) delete [] pts_num;
   if(pts_off[0] != NULL) delete [] pts_off[0];
   if(pts_off[1] != NULL) delete [] pts_off[1];
}

// copy data
SpriteData::SpriteData(const SpriteData & src)
{
   size = src.size;
   w = src.w;
   h = src.h;
   data = new void **[size];
   pts_num = new uInt16[size];
   pts_off[0] = new uInt16[size];
   pts_off[1] = new uInt16[size];
   memcpy(pts_num, src.pts_num, sizeof(uInt16)*size);
   memcpy(pts_off[0], src.pts_off[0], sizeof(uInt16)*size);
   memcpy(pts_off[1], src.pts_off[1], sizeof(uInt16)*size);

   for(i = 0; i < size; i++)
   {
      if(data[i] != NULL)
      {
         tpts_num = 2*pts_num[i];
         data[i] = new void *[tpts_num];
         for(k = 0; k < tpts_num; k++)
         {
            data[i][k] = new float[4];
            memcpy(data[i][k], src.data[i][k], sizeof(float)*4 );
            
            k++;
            data[i][k] = new uInt16[2];
            memcpy(data[i][k], src.data[i][k], sizeof(uInt16)*2 );
         }
      }
   }
}
//

int SpriteData::LoadFile(char *file)
{
   uInt16 j;
   char inChar, chpt[256];
   int inInt;
   float inFloat;
   ifstream inFs(file, ios::in );
   if( inFs.fail() )
   {
      cerr << "File could not be opened\n";
      return 100;
   }

   inFs.get(inChar);
   if( !inFs.fail() )
   {
      inFs.putback(inChar);

      inFs >> size;
      inFs >> inInt;
      w = inInt;
      inFs >> inInt;
      h = inInt;

      data = new void **[size];
      pts_num = new uInt16[size];
      pts_off[0] = new uInt16[size];
      pts_off[1] = new uInt16[size];

      i = 0;
      while( !inFs.fail() )
      {
         inFs.get(inChar);
         while(inChar == '#')
         {
            inFs.getline(chpt, 255);
            inFs.get(inChar);
         }

         if( (inChar != '\n') && (inChar != '\r') )
         {
            inFs.putback(inChar);
            inFs >> inInt;
            pts_num[i] = inInt;
            
            inFs >> inInt;
            pts_off[0][i] = inInt;
            inFs >> inInt;
            pts_off[1][i] = inInt;

            tpts_num = 2*pts_num[i];
            data[i] = new void *[tpts_num];

            for(k = 0; k < tpts_num; k++)
            {
               data[i][k++] = new float[4];
               data[i][k] = new uInt16[2];
            }

            for(k = 0; k < tpts_num; k++)
            {
               for(j = 0; j < 4; j++)
               {
                  inFs >> inFloat;
                  ((float *)data[i][k])[j] = inFloat;
               }
               k++;
               for(j = 0; j < 2; j++)
               {
                  inFs >> inInt;
                  ((uInt16 *)data[i][k])[j] = inInt;
               }
            }

            i++;
         }
      }
   }

   inFs.close();
   return 0;
}

void SpriteData::Draw(sInt16 x, sInt16 y)
{
   if(data != NULL)
   {
      for(i = 0; i < size; i++)  // group
      {
         if(data[i] != NULL)
         {
            tsize = 2*pts_num[i];
            glBegin(GL_POLYGON);
            for(k = 0; k < tsize; k++)
            {
               if(data[i][k] != NULL)
               {
                  // Set Color
                  glColor4fv( (float *)data[i][k++] );
                  // Add Point
                  tx = pts_off[0][i] + ((sInt16 *)data[i][k])[0] + x;
                  ty = pts_off[1][i] + ((sInt16 *)data[i][k])[1] + y;
                  glVertex2s(tx, ty);
               }
            }
            glEnd();
         }
      }
   }
}



Sprite::Sprite()
{
   current_anim = 0;
   num_anim = 0;
   anim = NULL;
}

Sprite::~Sprite()
{
   if(anim != NULL)
   {
      for(i = 0; i < num_anim; i++)
      {
         if(anim[i] != NULL) delete anim[i];
      }
   }
}

Sprite::Sprite(const Sprite & src)
{
   copy(src);
}

void Sprite::Draw(uInt16 an)
{
   if(anim != NULL)
   {
      if( an < num_anim)
      {
         current_anim = an;
         if(anim[current_anim] != NULL)
         {
            anim[current_anim]->Draw(x, y);
         }
      }
   }
}

int Sprite::Load(char **file, uInt16 num)
{
   if(file != NULL)
   {
      num_anim = num;
      anim = new SpriteData *[num_anim];
      for(i = 0; i < num_anim; i++)
      {
         if(file[i] != NULL)
         {
            anim[i] = new SpriteData();
            anim[i]->LoadFile(file[i]);
         }
      }
   }

   return 1;
}

sInt32 * Sprite::Rect()
{
   if(anim != NULL)
   {
      if(anim[current_anim] != NULL)
      {
         rect[0] = x;
         rect[1] = y;
         rect[2] = x + anim[current_anim]->GetWidth();
         rect[3] = y + anim[current_anim]->GetHeight();
      }
   }

   return rect;
}

void Sprite::copy(const Sprite & src)
{
   num_anim = src.num_anim;
   anim = new SpriteData *[num_anim];
   for(i = 0; i < num_anim; i++)
   {
      if(src.anim[i] != NULL)
      {
         anim[i] = new SpriteData(*src.anim[i]);
      }
   }
}

