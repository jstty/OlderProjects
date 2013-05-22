# Microsoft Developer Studio Project File - Name="ss" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=ss - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ss.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ss.mak" CFG="ss - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ss - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "ss - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ss - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "ss - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "dep/allegro/include" /I "dep/js/include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "XP_WIN" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib alld.lib alleg.lib allp.lib js32.lib /nologo /subsystem:console /debug /machine:I386 /out:"out/ss.exe" /pdbtype:sept /libpath:"dep/allegro/lib" /libpath:"dep/js/lib/"

!ENDIF 

# Begin Target

# Name "ss - Win32 Release"
# Name "ss - Win32 Debug"
# Begin Group "Levels"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\cLvl_Intro.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cLvl_Intro.h
# End Source File
# Begin Source File

SOURCE=.\src\cLvl_Ring01.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cLvl_Ring01.h
# End Source File
# Begin Source File

SOURCE=.\out\data\level_scripts\ring.js
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\src\cActionPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cAnim.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cBaseWrestler.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cControls.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cDisplay.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cFontMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cFx.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cGfxNode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cGfxObj.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cGfxText.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cImage.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cLayer.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cLayerMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cLevel.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cLevelInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cLevelMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cPlayerMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cPlayerNode.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cPolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cRingCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cRingClock.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cRingStatusMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cScriptEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cScriptEnvCollision.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cScriptPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cSeq.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cSound.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cSprite.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cSuperStars.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cTextFileReader.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cTitantron.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cToggleAction.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cWrestler.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cWrestlerMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\src\cZones.cpp
# End Source File
# Begin Source File

SOURCE=.\src\main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\src\cActionPlayer.h
# End Source File
# Begin Source File

SOURCE=.\src\cAnim.h
# End Source File
# Begin Source File

SOURCE=.\src\cBaseWrestler.h
# End Source File
# Begin Source File

SOURCE=.\src\cControls.h
# End Source File
# Begin Source File

SOURCE=.\src\cDisplay.h
# End Source File
# Begin Source File

SOURCE=.\src\cFontMngr.h
# End Source File
# Begin Source File

SOURCE=.\src\cFrame.h
# End Source File
# Begin Source File

SOURCE=.\src\cFx.h
# End Source File
# Begin Source File

SOURCE=.\src\cGfxNode.h
# End Source File
# Begin Source File

SOURCE=.\src\cGfxObj.h
# End Source File
# Begin Source File

SOURCE=.\src\cGfxText.h
# End Source File
# Begin Source File

SOURCE=.\src\cImage.h
# End Source File
# Begin Source File

SOURCE=.\src\cLayer.h
# End Source File
# Begin Source File

SOURCE=.\src\cLayerMngr.h
# End Source File
# Begin Source File

SOURCE=.\src\cLevel.h
# End Source File
# Begin Source File

SOURCE=.\src\cLevelInfo.h
# End Source File
# Begin Source File

SOURCE=.\src\cLevelMngr.h
# End Source File
# Begin Source File

SOURCE=.\src\cPlayer.h
# End Source File
# Begin Source File

SOURCE=.\src\cPlayerMngr.h
# End Source File
# Begin Source File

SOURCE=.\src\cPlayerNode.h
# End Source File
# Begin Source File

SOURCE=.\src\cPolygon.h
# End Source File
# Begin Source File

SOURCE=.\src\cRingCamera.h
# End Source File
# Begin Source File

SOURCE=.\src\cRingClock.h
# End Source File
# Begin Source File

SOURCE=.\src\cRingStatusMenu.h
# End Source File
# Begin Source File

SOURCE=.\src\cScriptEngine.h
# End Source File
# Begin Source File

SOURCE=.\src\cScriptEnvCollision.h
# End Source File
# Begin Source File

SOURCE=.\src\cScriptPlayer.h
# End Source File
# Begin Source File

SOURCE=.\src\cSeq.h
# End Source File
# Begin Source File

SOURCE=.\src\cSound.h
# End Source File
# Begin Source File

SOURCE=.\src\cSprite.h
# End Source File
# Begin Source File

SOURCE=.\src\cSuperStars.h
# End Source File
# Begin Source File

SOURCE=.\src\cTextFileReader.h
# End Source File
# Begin Source File

SOURCE=.\src\cTitantron.h
# End Source File
# Begin Source File

SOURCE=.\src\cToggleAction.h
# End Source File
# Begin Source File

SOURCE=.\src\cWrestler.h
# End Source File
# Begin Source File

SOURCE=.\src\cWrestlerMngr.h
# End Source File
# Begin Source File

SOURCE=.\src\cZones.h
# End Source File
# Begin Source File

SOURCE=.\src\main.h
# End Source File
# Begin Source File

SOURCE=.\todo.txt
# End Source File
# Begin Source File

SOURCE=.\src\types.h
# End Source File
# End Group
# Begin Group "stl"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\stl\cLList.cpp

!IF  "$(CFG)" == "ss - Win32 Release"

!ELSEIF  "$(CFG)" == "ss - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\stl\cLList.h
# End Source File
# Begin Source File

SOURCE=.\src\stl\cSList.cpp

!IF  "$(CFG)" == "ss - Win32 Release"

!ELSEIF  "$(CFG)" == "ss - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\stl\cSList.h
# End Source File
# Begin Source File

SOURCE=.\src\stl\cSTree.cpp

!IF  "$(CFG)" == "ss - Win32 Release"

!ELSEIF  "$(CFG)" == "ss - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\stl\cSTree.h
# End Source File
# End Group
# End Target
# End Project
