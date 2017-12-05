rem ========================================
rem === root platform                    ===
rem ----------------------------------------
adb root
adb remount

rem ========================================
rem === Local environment setting        ===
rem ----------------------------------------
if "%WORKPATH%"=="" (
call cls
set WORKPATH=%~dp0%
)

rem ========================================
rem === push data                        ===
rem ----------------------------------------
REM adb shell "mkdir /data/sammychen"
adb push %WORKPATH%libs/armeabi-v7a/Time_Profiling_Verification /data
adb shell "chmod 777 /data/Time_Profiling_Verification"