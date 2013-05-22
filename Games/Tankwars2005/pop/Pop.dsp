# Microsoft Developer Studio Project File - Name="Pop" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Pop - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Pop.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Pop.mak" CFG="Pop - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Pop - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Pop - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Pop - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../Release"
# PROP Intermediate_Dir "../Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 opengl32.lib glu32.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\out\tws2005_(Release).exe"

!ELSEIF  "$(CFG)" == "Pop - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../Debug"
# PROP Intermediate_Dir "../Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib winmm.lib /nologo /subsystem:windows /profile /debug /machine:I386 /out:"..\out\tws2005_(Debug).exe"

!ENDIF 

# Begin Target

# Name "Pop - Win32 Release"
# Name "Pop - Win32 Debug"
# Begin Group "pop"

# PROP Default_Filter ""
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\biota.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\collider.cpp
# End Source File
# Begin Source File

SOURCE=.\colorstyle.cpp
# End Source File
# Begin Source File

SOURCE=.\controller.cpp
# End Source File
# Begin Source File

SOURCE=.\Critter.cpp
# End Source File
# Begin Source File

SOURCE=.\critterarmed.cpp
# End Source File
# Begin Source File

SOURCE=.\critterviewer.cpp
# End Source File
# Begin Source File

SOURCE=.\critterviewerstereo.cpp
# End Source File
# Begin Source File

SOURCE=.\critterwall.cpp
# End Source File
# Begin Source File

SOURCE=.\dialogopenglinfo.cpp
# End Source File
# Begin Source File

SOURCE=.\dialogspeed.cpp
# End Source File
# Begin Source File

SOURCE=.\dialogstereo.cpp
# End Source File
# Begin Source File

SOURCE=.\force.cpp
# End Source File
# Begin Source File

SOURCE=.\game.cpp
# End Source File
# Begin Source File

SOURCE=.\glshapes.cpp
# End Source File
# Begin Source File

SOURCE=.\graphics.cpp
# End Source File
# Begin Source File

SOURCE=.\graphicsMFC.cpp
# End Source File
# Begin Source File

SOURCE=.\graphicsOpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\listener.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MemoryDC.cpp
# End Source File
# Begin Source File

SOURCE=.\metric.cpp
# End Source File
# Begin Source File

SOURCE=.\Pop.cpp
# End Source File
# Begin Source File

SOURCE=.\Pop.rc
# End Source File
# Begin Source File

SOURCE=.\PopDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\popview.cpp
# End Source File
# Begin Source File

SOURCE=.\quakeMD2model.cpp
# End Source File
# Begin Source File

SOURCE=.\Randomizer.cpp
# End Source File
# Begin Source File

SOURCE=.\RealBox.cpp
# End Source File
# Begin Source File

SOURCE=.\RealPixelConverter.cpp
# End Source File
# Begin Source File

SOURCE=.\Sprite.cpp
# End Source File
# Begin Source File

SOURCE=.\sprite3d.cpp
# End Source File
# Begin Source File

SOURCE=.\spritebubble.cpp
# End Source File
# Begin Source File

SOURCE=.\spriteicon.cpp
# End Source File
# Begin Source File

SOURCE=.\spritemultiIcon.cpp
# End Source File
# Begin Source File

SOURCE=.\spritepolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\spritequake.cpp
# End Source File
# Begin Source File

SOURCE=.\spritetexturebox.cpp
# End Source File
# Begin Source File

SOURCE=.\static.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Texture.cpp
# End Source File
# Begin Source File

SOURCE=.\Timer.cpp
# End Source File
# Begin Source File

SOURCE=.\VectorTransformation.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="C:\Program Files\Microsoft Visual Studio\VC98\Include\BASETSD.H"
# End Source File
# Begin Source File

SOURCE=.\biota.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\collider.h
# End Source File
# Begin Source File

SOURCE=.\colorstyle.h
# End Source File
# Begin Source File

SOURCE=.\controller.h
# End Source File
# Begin Source File

SOURCE=.\Critter.h
# End Source File
# Begin Source File

SOURCE=.\critterarmed.h
# End Source File
# Begin Source File

SOURCE=.\critterviewer.h
# End Source File
# Begin Source File

SOURCE=.\critterviewerstereo.h
# End Source File
# Begin Source File

SOURCE=.\critterwall.h
# End Source File
# Begin Source File

SOURCE=.\dialogopenglinfo.h
# End Source File
# Begin Source File

SOURCE=.\dialogspeed.h
# End Source File
# Begin Source File

SOURCE=.\dialogstereo.h
# End Source File
# Begin Source File

SOURCE=.\force.h
# End Source File
# Begin Source File

SOURCE=.\game.h
# End Source File
# Begin Source File

SOURCE=.\graphics.h
# End Source File
# Begin Source File

SOURCE=.\graphicsMFC.h
# End Source File
# Begin Source File

SOURCE=.\graphicsOpenGL.h
# End Source File
# Begin Source File

SOURCE=.\listener.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MemoryDC.h
# End Source File
# Begin Source File

SOURCE=.\metric.h
# End Source File
# Begin Source File

SOURCE=.\Pop.h
# End Source File
# Begin Source File

SOURCE=.\PopDoc.h
# End Source File
# Begin Source File

SOURCE=.\PopView.h
# End Source File
# Begin Source File

SOURCE=.\quakeMD2model.h
# End Source File
# Begin Source File

SOURCE=.\Randomizer.h
# End Source File
# Begin Source File

SOURCE=.\RealBox.h
# End Source File
# Begin Source File

SOURCE=.\RealNumber.h
# End Source File
# Begin Source File

SOURCE=.\RealPixelConverter.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Sprite.h
# End Source File
# Begin Source File

SOURCE=.\sprite3d.h
# End Source File
# Begin Source File

SOURCE=.\spritebubble.h
# End Source File
# Begin Source File

SOURCE=.\spriteicon.h
# End Source File
# Begin Source File

SOURCE=.\spritemultiIcon.h
# End Source File
# Begin Source File

SOURCE=.\spritepolygon.h
# End Source File
# Begin Source File

SOURCE=.\spritequake.h
# End Source File
# Begin Source File

SOURCE=.\spritetexturebox.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Texture.h
# End Source File
# Begin Source File

SOURCE=.\Timer.h
# End Source File
# Begin Source File

SOURCE=.\VectorTransformation.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\about.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bigsky.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cur00001.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00002.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=.\res\earth.bmp
# End Source File
# Begin Source File

SOURCE=.\res\equals.cur
# End Source File
# Begin Source File

SOURCE=.\res\Flatland.ico
# End Source File
# Begin Source File

SOURCE=.\res\Hand.cur
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\pin.cur
# End Source File
# Begin Source File

SOURCE=.\res\Pop.ico
# End Source File
# Begin Source File

SOURCE=.\res\Pop.rc2
# End Source File
# Begin Source File

SOURCE=.\res\pop.wav
# End Source File
# Begin Source File

SOURCE=.\res\pop1.bin
# End Source File
# Begin Source File

SOURCE=.\res\PopDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\spawn.cur
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\zap.cur
# End Source File
# End Group
# Begin Source File

SOURCE=.\directx\Include\basetsd.h
# End Source File
# End Group
# Begin Group "OpenGL"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\glext.h
# End Source File
# Begin Source File

SOURCE=.\glshapes.h
# End Source File
# End Group
# Begin Group "TankWars2005"

# PROP Default_Filter ""
# Begin Group "level"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\code\level.cpp
# End Source File
# Begin Source File

SOURCE=..\code\level.h
# End Source File
# Begin Source File

SOURCE=..\code\levelselector.cpp
# End Source File
# Begin Source File

SOURCE=..\code\levelselector.h
# End Source File
# Begin Source File

SOURCE=..\code\slist.h
# End Source File
# End Group
# Begin Group "title"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\code\actionbutton.cpp
# End Source File
# Begin Source File

SOURCE=..\code\actionbutton.h
# End Source File
# Begin Source File

SOURCE=..\code\title_level.cpp
# End Source File
# Begin Source File

SOURCE=..\code\title_level.h
# End Source File
# End Group
# Begin Group "battle"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\code\battle_level.cpp
# End Source File
# Begin Source File

SOURCE=..\code\battle_level.h
# End Source File
# End Group
# Begin Group "end"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\code\end_level.cpp
# End Source File
# Begin Source File

SOURCE=..\code\end_level.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\code\tankwars2005.cpp
# End Source File
# Begin Source File

SOURCE=..\code\tankwars2005.h
# End Source File
# End Group
# End Target
# End Project
