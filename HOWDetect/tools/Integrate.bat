@Echo Off
setlocal



set SWC=HOWDetect

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_HOWDETECT=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_HOWDETECT=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_HOWDETECT%
mkdir %GENDEFDIR_HOWDETECT%



copy ..\generate\Ap_HOWDetect_*.arxml	%BSWMDDIR_HOWDETECT%
copy ..\generate\Ap_HOWDetect_*.tt	%GENDEFDIR_HOWDETECT%
copy ..\generate\Ap_HOWDetect_*.bat	%GENDEFDIR_HOWDETECT%


pause
:end

endlocal

