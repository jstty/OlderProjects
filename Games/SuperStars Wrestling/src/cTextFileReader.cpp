/* //////////////////////////////////////////////////////////////////////
 Program Name:  cTextFileReader.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-09
 Updated:       
 Version:       1.00
 Description:
   Text File Reader Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cTextFileReader::cTextFileReader()
{
   m_fp = NULL;
   m_str = NULL;
}

cTextFileReader::~cTextFileReader()
{
   DELETE_A(m_str);
}

int cTextFileReader::Load(const char *filename)
{
   m_fp = fopen(filename, "r+");
   if(m_fp == NULL) return 1;

   // get size
   long size;
   fseek(m_fp, 0, SEEK_END);
   size = ftell(m_fp);
   fseek(m_fp, 0, SEEK_SET);

   // allocat temp string
   char *stemp = new char[size + 1];
   memset(stemp, 0, sizeof(char)*size);

   // read emtire file to string
   fread(stemp, sizeof(char), size, m_fp);

   // close
   fclose(m_fp);
   m_fp = NULL;


   // remove comment lines
   // allocate perm string
   m_str = new char[size];
   memset(m_str, 0, sizeof(char)*size);

   uInt32 sp, ep, copied;
   char *fp;

   copied = 0;
   fp = strstr( stemp, "//");

   // no comments, need to copy
   if(fp == NULL) {
      strncpy(m_str, stemp, strlen(stemp) + 1);
   } else {
   // comment found
      // copy any string before first comment
      sp = fp - stemp;
      if(sp > 0)
      {
         strncpy(m_str, stemp, sp);
         copied += sp;
      }

      while(fp != NULL)
      {
         // find start of comment
         sp = fp - stemp;

         // find end of comment
         fp = strchr(&(stemp[sp]), '\n');
         ep = fp - stemp;
         if(stemp[ep + 1] == '\r') ++ep;

         // now find between comments
         sp = ep + 1;
         fp = strstr(&(stemp[sp]), "//");
         if(fp != NULL) {
            ep = fp - stemp;
         } else {
            ep = size - 1;
         }

         strncpy(&m_str[copied], &(stemp[sp]), ep - sp);
         copied += ep - sp;
      }
   } // comment found

   // delete temp string
   DELETE_A(stemp);

   m_pos = 0;
   return 0;
}

// find first blank char, then find first NONE blank char
// to find start of next data
uInt32 cTextFileReader::FindFirstChar(const char *needle)
{
   uInt32 i, j, ssize, nsize;
   bool  found_empty = 0;
   uInt8 count;
   ssize = strlen(m_str);
   nsize = strlen(needle);

   for(i = m_pos; i < ssize; ++i)
   {
      count = 0;
      for(j = 0; j < nsize; ++j)
      {
         if(found_empty == 0)
         {
            if(m_str[i] == needle[j]) {
               found_empty = 1;
               --i; // go back one to test again
               break;
            }
         } else {
            if(m_str[i] != needle[j]) ++count;
         }
      }

      if(count == nsize) {
         return i;
      }
   }

   return ssize - 1;
}

int cTextFileReader::ReadInt(uInt8 &i) {
   int e = sscanf(&(m_str[m_pos]), "%d", &i);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}


int cTextFileReader::ReadInt(uInt16 &i) {
   int e = sscanf(&(m_str[m_pos]), "%d", &i);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}

int cTextFileReader::ReadInt(uInt32 &i) {
   int e = sscanf(&(m_str[m_pos]), "%d", &i);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}

int cTextFileReader::ReadInt(Int8 &i) {
   int e = sscanf(&(m_str[m_pos]), "%d", &i);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}

int cTextFileReader::ReadInt(Int16 &i) {
   int e = sscanf(&(m_str[m_pos]), "%d", &i);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}

int cTextFileReader::ReadInt(Int32 &i) {
   int e = sscanf(&(m_str[m_pos]), "%d", &i);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}

int cTextFileReader::ReadString(char *s) {
   int e = sscanf(&(m_str[m_pos]), "%s", s);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}

int cTextFileReader::ReadFloat(float &f) {
   int e = sscanf(&(m_str[m_pos]), "%f", &f);

   if((e != 0) && (e != -1)) {
      m_pos = FindFirstChar(TEXT_BLANK);
      return 0;
   }
   return 1;
}

uInt32 cTextFileReader::GetPos()
{
   return m_pos;
}


void cTextFileReader::SetPos(uInt32 p)
{
   m_pos = p;
}


bool cTextFileReader::AtEnd()
{
   int e = 0;
   uInt32 i;
   float  f;
   char   s[256];

   uInt32 p = GetPos();

   e = ReadInt(i);
   e += ReadFloat(f);
   e += ReadString(s);

   SetPos(p);
 
   return (e == 3);
}

