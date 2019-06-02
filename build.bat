@echo off

set CURRENT_DIR_PATH=%~dp0
set CURRENT_DIR_PATH=%CURRENT_DIR_PATH:~0,-1%
for %%a in ("%CURRENT_DIR_PATH%") do set PROJECT_NAME=%%~na

set OUT_DIR_NAME=build
set OUT_PROJECT_PATH=%OUT_DIR_NAME%\%PROJECT_NAME%

set COMPILER=avr-gcc
set PROGRAMMER=usbasp
set MCU=atmega8

cd /d "%CURRENT_DIR_PATH%"
rmdir /s /q "%OUT_DIR_NAME%" 2>nul
mkdir "%OUT_PROJECT_PATH%"

cd /d "%CURRENT_DIR_PATH%\src\libcharlcd"
%COMPILER% --std=c99 -mmcu=%MCU% -g -Os -c ./charlcd.c -o "%CURRENT_DIR_PATH%"\src\char-lcd\libcharlcd.o

cd /d "%CURRENT_DIR_PATH%\src\char-lcd"
%COMPILER% --std=c99 -g -mmcu=%MCU% libcharlcd.o ./main.c -o "%CURRENT_DIR_PATH%\%OUT_PROJECT_PATH%"\char-lcd.elf
del /q libcharlcd.o >nul

cd /d "%CURRENT_DIR_PATH%\%OUT_PROJECT_PATH%"
avr-objcopy -j .text -j .data -O ihex char-lcd.elf char-lcd.hex
del /q char-lcd.elf >nul

:choice
set /P c="flash[Y/N]: "
if /I "%c%" EQU "Y" goto :flash
if /I "%c%" EQU "N" goto :no_flash
goto :choice

:flash
avrdude -c %PROGRAMMER% -p %MCU% -U flash:w:char-lcd.hex:i
pause
exit

:no_flash
pause
exit
