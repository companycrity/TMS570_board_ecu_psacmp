@Echo Off
setlocal



set SWC=TranlDampg

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_TRANLDAMPG=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_TRANLDAMPG=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_TRANLDAMPG%
mkdir %GENDEFDIR_TRANLDAMPG%



copy ..\generate\Ap_TranlDampg_*.arxml	%BSWMDDIR_TRANLDAMPG%
copy ..\generate\Ap_TranlDampg_*.tt	%GENDEFDIR_TRANLDAMPG%
copy ..\generate\Ap_TranlDampg_*.bat	%GENDEFDIR_TRANLDAMPG%


pause
:end

endlocal

