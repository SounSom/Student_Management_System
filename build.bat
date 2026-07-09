@echo off

IF /I "%~1"=="clean" (
    echo del /Q sms.exe
    del /Q sms.exe 2>nul
    echo del /Q *.obj
    del /Q *.obj 2>nul
    goto :eof
)

:: Check for gcc first
where gcc >nul 2>&1
IF %ERRORLEVEL% EQU 0 (
    set CC=gcc
    set CFLAGS=-Wall src\*.c -o sms.exe
    goto :compile
)

:: Fallback to clang
where clang >nul 2>&1
IF %ERRORLEVEL% EQU 0 (
    set CC=clang
    set CFLAGS=-Wall src\*.c -o sms.exe
    goto :compile
)

:: Fallback to MSVC
where cl >nul 2>&1
IF %ERRORLEVEL% EQU 0 (
    set CC=cl
    set CFLAGS=/W3 src\*.c /Fesms.exe
    goto :compile
)

:: If none are found, print error and exit with a failure code
echo Error: no C compiler found!
exit /B 1

:compile
echo %CC% %CFLAGS%
%CC% %CFLAGS%