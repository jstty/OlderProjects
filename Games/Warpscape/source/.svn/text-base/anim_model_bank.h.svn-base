/****************************************
 filename:    anim_model_bank.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: 
 ****************************************/
#ifndef _ANIM_MODEL_BANK_
#define _ANIM_MODEL_BANK_

class cAnimModelBank
{
protected:
   vector<cAnimModelGfx *> mAnimModelGfxs;
   
   //
   uInt32         i;
   cAnimModelGfx *mTmpGfx;
   
public:
   cAnimModelBank();
   
   void Clear();
   int  Load(const char *filename);
   
   cAnimModelGfx *Find(const char *name);   
};

#endif // _ANIM_MODEL_BANK_
