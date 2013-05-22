# Microsoft Developer Studio Project File - Name="cpts_veh_dll" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=cpts_veh_dll - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cpts_veh_dll.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cpts_veh_dll.mak" CFG="cpts_veh_dll - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cpts_veh_dll - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "cpts_veh_dll - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cpts_veh_dll - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CPTS_VEH_DLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CPTS_VEH_DLL_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "cpts_veh_dll - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../../lib/"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CPTS_VEH_DLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CPTS_VEH_DLL_EXPORTS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"../../../out/cpts_veh.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "cpts_veh_dll - Win32 Release"
# Name "cpts_veh_dll - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "cpts"

# PROP Default_Filter ""
# Begin Group "org"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\source_veh\org\biobehavior.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\source_veh\org\desbehavior.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\source_veh\org\mapbehavior.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\source_veh\org\strats.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\source_veh\c_cpts_vehicle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\source_veh\c_cpts_vehicle_data.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\source_veh\c_vehicle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\source_veh\c_webots_controller.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\cpts_veh_dll.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "cpts No. 1"

# PROP Default_Filter ""
# Begin Group "org No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\org\actfunction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\biobehavior.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\constants.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\desbehavior.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\globaldef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\inisearch.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\list.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\listnd.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\mapbehavior.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\odor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\point.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\org\strats.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\include\c_cpts_vehicle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\c_cpts_vehicle_data.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\c_vehicle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\c_webots_controller.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\i_vehicle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\i_vehicle_controller.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\i_vehicle_data.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\include\cpts_veh_dll.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
