### Sample DevkitPro GBA CMAKE Project ###

Purpose of this template project is to be able to work with CLion while working on gba game.

in order to make it work you have to pass some parameters to cmake like below.

* -DCMAKE_LIBGBA=D:/Development/msys32/opt/devkitpro/libgba
* -DMGBA=d:/Development/mgba/mgba.exe 
* -DBASH=d:/Development/msys32/usr/bin/bash

MAKE_LIBGBA - should point to libgba directory

MGBA - should point to MGBA executable (required to run target)

BASH - should point to bash executable required to execute scripts