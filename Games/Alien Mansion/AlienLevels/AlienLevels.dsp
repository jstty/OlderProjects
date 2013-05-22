# Microsoft Developer Studio Project File - Name="AlienLevels" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=AlienLevels - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AlienLevels.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AlienLevels.mak" CFG="AlienLevels - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AlienLevels - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AlienLevels - Win32 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AlienLevels - Win32 Release"

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

!ELSEIF  "$(CFG)" == "AlienLevels - Win32 Debug"

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

# Name "AlienLevels - Win32 Release"
# Name "AlienLevels - Win32 Debug"
# Begin Group "C++ Files"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\Level01.cpp
# End Source File
# Begin Source File

SOURCE=.\Level02.cpp
# End Source File
# Begin Source File

SOURCE=.\Level03.cpp
# End Source File
# Begin Source File

SOURCE=.\Level04.cpp
# End Source File
# Begin Source File

SOURCE=.\MainLevels.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=..\AlienMansion.h
# End Source File
# Begin Source File

SOURCE=.\Level01.h
# End Source File
# Begin Source File

SOURCE=.\Level02.h
# End Source File
# Begin Source File

SOURCE=.\Level03.h
# End Source File
# Begin Source File

SOURCE=.\Level04.h
# End Source File
# Begin Source File

SOURCE=.\MainLevels.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "rc"
# Begin Source File

SOURCE=.\Alienlevels.rc

!IF  "$(CFG)" == "AlienLevels - Win32 Release"

!ELSEIF  "$(CFG)" == "AlienLevels - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Library Files"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE="..\Debug\Alien Mansion.lib"
# End Source File
# Begin Source File

SOURCE=..\..\..\Msvc\Vc\lib\Comctl32.lib
# End Source File
# End Group
# Begin Group "External Files"

# PROP Default_Filter "ico;bmp;wav"
# Begin Source File

SOURCE=.\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\end1.wav
# End Source File
# Begin Source File

SOURCE=.\sound\end1.wav
# End Source File
# Begin Source File

SOURCE=.\end2a.wav
# End Source File
# Begin Source File

SOURCE=.\sound\end2a.wav
# End Source File
# Begin Source File

SOURCE=.\FDOOR1B.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\FDOOR1B.bmp
# End Source File
# Begin Source File

SOURCE=.\FDOOR1M.bmp
# End Source File
# Begin Source File

SOURCE=.\FDOOR2B.bmp
# End Source File
# Begin Source File

SOURCE=.\FDOOR2M.bmp
# End Source File
# Begin Source File

SOURCE=.\GEORGEB.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\GeorgeB.BMP
# End Source File
# Begin Source File

SOURCE=.\GEORGEM.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\GEORGEM.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\KEYB.bmp
# End Source File
# Begin Source File

SOURCE=.\KEYB.bmp
# End Source File
# Begin Source File

SOURCE=.\KEYM.bmp
# End Source File
# Begin Source File

SOURCE=.\LADDER1.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level02.bmp
# End Source File
# Begin Source File

SOURCE=.\level02.bmp
# End Source File
# Begin Source File

SOURCE=.\LEVEL03.bmp
# End Source File
# Begin Source File

SOURCE=.\LEVEL04.bmp
# End Source File
# Begin Source File

SOURCE=.\LEVEL05.bmp
# End Source File
# Begin Source File

SOURCE=.\level06.bmp
# End Source File
# Begin Source File

SOURCE=.\level07.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\level08.bmp
# End Source File
# Begin Source File

SOURCE=.\level08.bmp
# End Source File
# Begin Source File

SOURCE=.\MBOX1B.bmp
# End Source File
# Begin Source File

SOURCE=.\MBOX1M.bmp
# End Source File
# Begin Source File

SOURCE=.\MBOX2B.bmp
# End Source File
# Begin Source File

SOURCE=.\MBOX2M.bmp
# End Source File
# Begin Source File

SOURCE=.\MBOXB.bmp
# End Source File
# Begin Source File

SOURCE=.\MBOXM.bmp
# End Source File
# Begin Source File

SOURCE=.\moon.bmp
# End Source File
# Begin Source File

SOURCE=.\MOONB.bmp
# End Source File
# Begin Source File

SOURCE=.\MOONM.bmp
# End Source File
# Begin Source File

SOURCE=.\MSIGNB.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\path02.bmp
# End Source File
# Begin Source File

SOURCE=.\path02.bmp
# End Source File
# Begin Source File

SOURCE=.\pic1.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\POSTB.bmp
# End Source File
# Begin Source File

SOURCE=.\POSTB.bmp
# End Source File
# Begin Source File

SOURCE=.\POSTM.bmp
# End Source File
# Begin Source File

SOURCE=.\RDOORB.bmp
# End Source File
# Begin Source File

SOURCE=.\RDOORM.bmp
# End Source File
# Begin Source File

SOURCE=.\SIGN.bmp
# End Source File
# Begin Source File

SOURCE=.\stairs.bmp
# End Source File
# Begin Source File

SOURCE=.\STAKEB.bmp
# End Source File
# Begin Source File

SOURCE=.\STAKEM.bmp
# End Source File
# Begin Source File

SOURCE=.\tempbk.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\TITLEB.bmp
# End Source File
# Begin Source File

SOURCE=.\TITLEB.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\TitleBkg.bmp
# End Source File
# Begin Source File

SOURCE=.\titlebkg.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\titlebkg2.bmp
# End Source File
# Begin Source File

SOURCE=.\titlebkg2.bmp
# End Source File
# Begin Source File

SOURCE=.\graphics\TITLEM.bmp
# End Source File
# Begin Source File

SOURCE=.\TITLEM.bmp
# End Source File
# Begin Source File

SOURCE=.\tree.bmp
# End Source File
# Begin Source File

SOURCE=.\window1.bmp
# End Source File
# End Group
# End Target
# End Project
