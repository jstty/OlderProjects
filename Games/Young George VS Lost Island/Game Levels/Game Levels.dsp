# Microsoft Developer Studio Project File - Name="Game Levels" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Game Levels - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Game Levels.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Game Levels.mak" CFG="Game Levels - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Game Levels - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Game Levels - Win32 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Game Levels - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "Game Levels - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Game Levels - Win32 Release"
# Name "Game Levels - Win32 Debug"
# Begin Group "C++ File(s)"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=..\AI.cpp
# End Source File
# Begin Source File

SOURCE=..\CDPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\DialogUtils.cpp
# End Source File
# Begin Source File

SOURCE=..\DxSnd.cpp
# End Source File
# Begin Source File

SOURCE=..\FileUtils.cpp
# End Source File
# Begin Source File

SOURCE=..\Graphics.cpp
# End Source File
# Begin Source File

SOURCE=.\Level01.cpp
# End Source File
# Begin Source File

SOURCE=.\Level02.cpp
# End Source File
# Begin Source File

SOURCE=.\MainLevels.cpp
# End Source File
# Begin Source File

SOURCE=..\Midi.cpp
# End Source File
# End Group
# Begin Group "Header File(s)"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=..\AI.h
# End Source File
# Begin Source File

SOURCE=..\CDPlayer.h
# End Source File
# Begin Source File

SOURCE=..\DialogUtils.h
# End Source File
# Begin Source File

SOURCE=..\DxSnd.h
# End Source File
# Begin Source File

SOURCE=..\FileUtils.h
# End Source File
# Begin Source File

SOURCE=..\Graphics.h
# End Source File
# Begin Source File

SOURCE=.\Level01.h
# End Source File
# Begin Source File

SOURCE=.\Level02.h
# End Source File
# Begin Source File

SOURCE=.\MainLevels.h
# End Source File
# Begin Source File

SOURCE=..\Midi.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=..\YoungGeroge.h
# End Source File
# End Group
# Begin Group "Imported Lib(s)"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE=..\..\..\Msvc\Vc\lib\Comctl32.lib
# End Source File
# Begin Source File

SOURCE=..\..\..\Msvc\Vc\lib\Dsound.lib
# End Source File
# Begin Source File

SOURCE=..\..\..\Msvc\Vc\lib\Winmm.lib
# End Source File
# End Group
# Begin Group "Resource File"

# PROP Default_Filter "rc"
# Begin Source File

SOURCE=.\sound\end1.wav
# End Source File
# Begin Source File

SOURCE=.\sound\end2a.wav
# End Source File
# Begin Source File

SOURCE=.\GameLevels.rc

!IF  "$(CFG)" == "Game Levels - Win32 Release"

!ELSEIF  "$(CFG)" == "Game Levels - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\graphics\GeorgeB.BMP
# End Source File
# Begin Source File

SOURCE=.\graphics\GEORGEM.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level02.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level03.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level04.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level05.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level06.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level07.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level08.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path02.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path03.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path04.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path05.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path06.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path07.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path08.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\TITLEB.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\TitleBkg.BMP
# End Source File
# Begin Source File

SOURCE=.\graphics\TITLEM.bmp
# End Source File
# End Group
# End Target
# End Project
