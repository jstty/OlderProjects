/* //////////////////////////////////////////////////////////////////////
 Program Name:  cTextFileReader.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-29
 Updated:       
 Version:       1.00
 Description:
   Text File Reader Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __TEXT_FILE_READER__
#define __TEXT_FILE_READER__

#define TEXT_BLANK "    \n\r"

class cTextFileReader
{
   public:
      cTextFileReader();
      ~cTextFileReader();

      int Load(const char *filename);

      int ReadInt(uInt8 &i);
      int ReadInt(uInt16 &i);
      int ReadInt(uInt32 &i);
      int ReadInt(Int8 &i);
      int ReadInt(Int16 &i);
      int ReadInt(Int32 &i);

      int ReadString(char *s);

      int ReadFloat(float &f);

      uInt32 GetPos();
      void   SetPos(uInt32 p);

      bool AtEnd();

   protected:
      FILE  *m_fp;
      uInt32 m_pos;

      char  *m_str;

      uInt32 FindFirstChar(const char *needle);

};

#endif // __TEXT_FILE_READER__