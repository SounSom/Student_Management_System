@echo off

IF /I "%~1"=="clean" (
    echo del /Q sms.exe
    del /Q sms.exe
    goto :eof
)

echo gcc -Wall *.c -o sms.exe
gcc -Wall *.c -o sms.exe