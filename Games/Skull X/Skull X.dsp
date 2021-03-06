# Microsoft Developer Studio Project File - Name="Skull X" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Skull X - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Skull X.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Skull X.mak" CFG="Skull X - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Skull X - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Skull X - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Skull X - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Skull X - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FAs /FR /YX /FD /c
# SUBTRACT CPP /WX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Skull X - Win32 Release"
# Name "Skull X - Win32 Debug"
# Begin Group "Main"

# PROP Default_Filter ""
# Begin Group "Debug"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\C++ Files\Debug.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\DebugClass.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\TestSpeed.h"
# End Source File
# Begin Source File

SOURCE=.\Comctl32.lib
# End Source File
# End Group
# Begin Group "Error"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Header Files\ErrorClass.h"
# End Source File
# End Group
# Begin Group "FileUtil"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\C++ Files\FileUtil.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\FileUtilClass.h"
# End Source File
# End Group
# Begin Group "LoadLevel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\C++ Files\Load.cpp"
# End Source File
# End Group
# Begin Source File

SOURCE=".\C++ Files\Main.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\Main.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\MainClass.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\MainVarClass.h"
# End Source File
# Begin Source File

SOURCE=".\C++ Files\Values.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\ValuesClass.h"
# End Source File
# End Group
# Begin Group "Controls"

# PROP Default_Filter ""
# Begin Group "DInput"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\DevStudio\Vc\include\dinput.h
# End Source File
# Begin Source File

SOURCE="Winmm.lib"
# End Source File
# End Group
# Begin Source File

SOURCE=".\C++ Files\Controls.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\ControlsClass.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\ControlVarClass.h"
# End Source File
# End Group
# Begin Group "Display"

# PROP Default_Filter ""
# Begin Group "DirectDraw"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\C++ Files\ddutil.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\ddutil.h"
# End Source File
# Begin Source File

SOURCE=DSETUP.lib
# End Source File
# Begin Source File

SOURCE="d3drm.lib"
# End Source File
# Begin Source File

SOURCE="dinput.lib"
# End Source File
# Begin Source File

SOURCE="dplayx.lib"
# End Source File
# Begin Source File

SOURCE="dsound.lib"
# End Source File
# Begin Source File

SOURCE="dxguid.lib"
# End Source File
# Begin Source File

SOURCE=Ddraw.lib
# End Source File
# End Group
# Begin Group "Resource"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\Resource Files\resource.h"
# End Source File
# Begin Source File

SOURCE=".\Resource Files\Skull v2.rc"
# End Source File
# Begin Source File

SOURCE=".\Resource Files\Skull.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=".\C++ Files\Display.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\DisplayClass.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\DisplayVarClass.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\gfx.h"
# End Source File
# Begin Source File

SOURCE=".\C++ Files\Gfx_to_DD.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\Gfx_to_DD.h"
# End Source File
# Begin Source File

SOURCE=".\C++ Files\LayerUtil.cpp"
# End Source File
# Begin Source File

SOURCE=".\C++ Files\LoadGfx.cpp"
# End Source File
# End Group
# Begin Group "Sound"

# PROP Default_Filter ""
# Begin Group "dsound"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\DevStudio\Vc\include\dls1.h
# End Source File
# Begin Source File

SOURCE=..\..\DevStudio\Vc\include\dmdls.h
# End Source File
# Begin Source File

SOURCE=..\..\DevStudio\Vc\include\dmerror.h
# End Source File
# Begin Source File

SOURCE=..\..\DevStudio\Vc\include\dmusicc.h
# End Source File
# Begin Source File

SOURCE=..\..\DevStudio\Vc\include\dmusici.h
# End Source File
# End Group
# Begin Source File

SOURCE=".\C++ Files\Sound.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\SoundClass.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\SoundVarClass.h"
# End Source File
# End Group
# Begin Group "Action"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\C++ Files\Action.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\ActionClass.h"
# End Source File
# Begin Source File

SOURCE=".\Header Files\ActionVarClass.h"
# End Source File
# End Group
# Begin Group "Game"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\C++ Files\Game.cpp"
# End Source File
# Begin Source File

SOURCE=".\Header Files\GameClass.h"
# End Source File
# End Group
# Begin Source File

SOURCE=".\Header Files\Program.h"
# End Source File
# End Target
# End Project
