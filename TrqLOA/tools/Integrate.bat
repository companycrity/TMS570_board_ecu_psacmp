@Echo Off
setlocal



set SWC=TrqLOA

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_TRQLOA=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_TRQLOA=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_TRQLOA%
mkdir %GENDEFDIR_TRQLOA%



copy ..\generate\Ap_TrqLOA_*.arxml	%BSWMDDIR_TRQLOA%
copy ..\generate\Ap_TrqLOA_*.tt	%GENDEFDIR_TRQLOA%
copy ..\generate\Ap_TrqLOA_*.bat	%GENDEFDIR_TRQLOA%


pause
:end

endlocal

