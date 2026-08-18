#!/bin/bash

mkdir -p executable/command

gcc src/main.c -o executable/jo-shell
gcc src/command/echo.c -o executable/command/echo
gcc src/command/ls.c -o executable/command/ls
gcc src/command/mkdir.c -o executable/command/mkdir
gcc src/command/pwd.c -o executable/command/pwd
gcc src/command/rmdir.c -o executable/command/rmdir