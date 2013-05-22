REM Delete Garbage Files
del *.aps
del *.ilk
del *.map
del *.ncb
del *.opt
del *.plg
del *.pbi
del *.pbo
del *.pbt
del *.pdb
del *.tmp
del *._xe
del *.exe

REM Delete hidden archived garbage files, first changing their attributes.
attrib -h -a *.gid
del *.gid

REM Optional: Delete Visual Studio Solution user options, which can be useful to keep.
attrib -h -a *.suo
del *.suo

REM Delete Garbage Directories
del enc_temp_folder\*.*
rmdir enc_temp_folder

del DEBUG\*.*
rmdir DEBUG
del RELEASE\*.*
rmdir RELEASE

REM Optional: delete the executables that the project has written to root.
REM del *.exe
