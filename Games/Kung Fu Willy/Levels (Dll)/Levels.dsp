# Microsoft Developer Studio Project File - Name="Levels" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Levels - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Levels.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Levels.mak" CFG="Levels - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Levels - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Levels - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Levels - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Levels - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /FD /c
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

# Name "Levels - Win32 Release"
# Name "Levels - Win32 Debug"
# Begin Group "C++ Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LevelsDll.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Controls.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Msvc\Vc\include\Game.h
# End Source File
# Begin Source File

SOURCE=.\Graphics.h
# End Source File
# Begin Source File

SOURCE=.\LevelsDll.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\Sound.h
# End Source File
# End Group
# Begin Group "Libary Files"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE="..\Controls (Dll)\Debug\Controls.lib"
# End Source File
# Begin Source File

SOURCE="..\Graphics (Dll)\Debug\Graphics.lib"
# End Source File
# Begin Source File

SOURCE="..\Debug\Kung Fu Willy.lib"
# End Source File
# Begin Source File

SOURCE="..\Sound (Dll)\Debug\Sound.lib"
# End Source File
# Begin Source File

SOURCE=..\..\..\Msvc\Vc\lib\Winmm.lib
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Levels.rc

!IF  "$(CFG)" == "Levels - Win32 Release"

!ELSEIF  "$(CFG)" == "Levels - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "External Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bk_1.bmp
# End Source File
# Begin Source File

SOURCE=.\bk_1d.bmp
# End Source File
# Begin Source File

SOURCE=.\bk_2.bmp
# End Source File
# Begin Source File

SOURCE=.\bk_2d.bmp
# End Source File
# Begin Source File

SOURCE=.\bk_3.bmp
# End Source File
# Begin Source File

SOURCE=.\bk_3d.bmp
# End Source File
# Begin Source File

SOURCE=.\Cm_mainm.bmp
# End Source File
# Begin Source File

SOURCE=.\COMb1.bmp
# End Source File
# Begin Source File

SOURCE=.\ebm.bmp
# End Source File
# Begin Source File

SOURCE=.\end1.wav
# End Source File
# Begin Source File

SOURCE=.\end2a.wav
# End Source File
# Begin Source File

SOURCE=.\end2b.wav
# End Source File
# Begin Source File

SOURCE=.\endani2.bmp
# End Source File
# Begin Source File

SOURCE=.\endani2m.bmp
# End Source File
# Begin Source File

SOURCE=.\endanim.bmp
# End Source File
# Begin Source File

SOURCE=.\endanimm.bmp
# End Source File
# Begin Source File

SOURCE=".\Energy Bar.bmp"
# End Source File
# Begin Source File

SOURCE=.\Floor.bmp
# End Source File
# Begin Source File

SOURCE=.\hit1.wav
# End Source File
# Begin Source File

SOURCE=.\hit2.wav
# End Source File
# Begin Source File

SOURCE=.\hit3.wav
# End Source File
# Begin Source File

SOURCE=.\P1_mainb.bmp
# End Source File
# Begin Source File

SOURCE=.\p1_mainm.bmp
# End Source File
# Begin Source File

SOURCE=.\P1b1.bmp
# End Source File
# Begin Source File

SOURCE=.\P1m1.bmp
# End Source File
# Begin Source File

SOURCE=.\P2_mainb.bmp
# End Source File
# Begin Source File

SOURCE=.\p2_mainm.bmp
# End Source File
# Begin Source File

SOURCE=.\P2b1.bmp
# End Source File
# Begin Source File

SOURCE=.\P2m1.bmp
# End Source File
# Begin Source File

SOURCE=".\Status Bar.bmp"
# End Source File
# Begin Source File

SOURCE=".\Text COM.bmp"
# End Source File
# Begin Source File

SOURCE=".\Text P1.bmp"
# End Source File
# Begin Source File

SOURCE=".\Text P2.bmp"
# End Source File
# Begin Source File

SOURCE=.\textco~1.bmp
# End Source File
# Begin Source File

SOURCE=.\textp1~1.bmp
# End Source File
# Begin Source File

SOURCE=.\textp2~1.bmp
# End Source File
# Begin Source File

SOURCE=.\Title.bmp
# End Source File
# Begin Source File

SOURCE=.\Title1.wav
# End Source File
# Begin Source File

SOURCE=.\Title2.wav
# End Source File
# End Group
# End Target
# End Project
