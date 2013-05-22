# Microsoft Developer Studio Project File - Name="cpts" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=cpts - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cpts.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cpts.mak" CFG="cpts - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cpts - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "cpts - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cpts - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "msvc"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../../include" /I "../../windows/include/glib-2.0" /I "../../windows/lib/glib-2.0/include" /I "../../windows/include/gtk-2.0" /I "../../windows/lib/gtk-2.0/include" /I "../../windows/include/pango-1.0" /I "../../windows/include/atk-1.0" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"debug/cpts.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 glib-2.0.lib gobject-2.0.lib gtk-win32-2.0.lib GtkController.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /pdb:"debug/cpts.pdb" /machine:I386 /libpath:"../../lib" /libpath:"../../windows/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "cpts - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "cpts___Win32_Debug"
# PROP BASE Intermediate_Dir "cpts___Win32_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "../../include" /I "../../windows/include/glib-2.0" /I "../../windows/lib/glib-2.0/include" /I "../../windows/include/gtk-2.0" /I "../../windows/lib/gtk-2.0/include" /I "../../windows/include/pango-1.0" /I "../../windows/include/atk-1.0" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "../../include" /I "../../windows/include/glib-2.0" /I "../../windows/lib/glib-2.0/include" /I "../../windows/include/gtk-2.0" /I "../../windows/lib/gtk-2.0/include" /I "../../windows/include/pango-1.0" /I "../../windows/include/atk-1.0" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo /o"debug/cpts.bsc"
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 glib-2.0.lib gobject-2.0.lib gtk-win32-2.0.lib GtkController.lib /nologo /subsystem:console /pdb:"debug/cpts.pdb" /machine:I386 /libpath:"../../lib" /libpath:"../../windows/lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 opengl32.lib glu32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /map /debug /machine:I386 /force /out:"../../out/cpts.exe" /pdbtype:sept /libpath:"../../lib" /libpath:"../../windows/lib"
# SUBTRACT LINK32 /profile /pdb:none

!ENDIF 

# Begin Target

# Name "cpts - Win32 Release"
# Name "cpts - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "view"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\source_view\c_cpts_gl_view.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_color.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_grid.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_info.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_plume.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_sensor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_text.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_vehicle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\gl_wind.cpp
# End Source File
# End Group
# Begin Group "settings"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\source_view\c_cpts_settings.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\c_settings.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\source_view\cpts.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source_view\main.cpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "libs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\lib\cpts_env.lib
# End Source File
# Begin Source File

SOURCE=..\..\lib\cpts_veh.lib
# End Source File
# Begin Source File

SOURCE=..\..\dep\libs\glu32.lib
# End Source File
# Begin Source File

SOURCE=..\..\dep\libs\glut32.lib
# End Source File
# Begin Source File

SOURCE=..\..\dep\libs\opengl32.lib
# End Source File
# Begin Source File

SOURCE=..\..\dep\libs\glut.lib
# End Source File
# End Group
# Begin Group "files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\out\settings.ini
# End Source File
# End Group
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "env"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\c_chemical_trail.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_chemical_trail_manager.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_cpts_env.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_cpts_env_data.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_webots_sensor.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_wind.h
# End Source File
# Begin Source File

SOURCE=..\..\include\cpts_env_dll.h
# End Source File
# Begin Source File

SOURCE=..\..\include\i_chem_sensor.h
# End Source File
# Begin Source File

SOURCE=..\..\include\i_env.h
# End Source File
# Begin Source File

SOURCE=..\..\include\i_env_data.h
# End Source File
# End Group
# Begin Group "settings No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\c_cpts_settings.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_settings.h
# End Source File
# End Group
# Begin Group "veh"

# PROP Default_Filter ""
# Begin Group "org No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\org\actfunction.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\biobehavior.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\constants.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\desbehavior.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\globaldef.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\inisearch.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\list.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\listnd.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\mapbehavior.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\odor.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\point.h
# End Source File
# Begin Source File

SOURCE=..\..\include\org\strats.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\include\c_cpts_vehicle.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_cpts_vehicle_data.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_vehicle.h
# End Source File
# Begin Source File

SOURCE=..\..\include\c_webots_controller.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\include\cpts.h
# End Source File
# Begin Source File

SOURCE=..\..\include\types_structs.h
# End Source File
# End Group
# End Target
# End Project
