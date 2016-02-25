@echo OFF


SET "args="
:while2
IF NOT "%~1" == "" (
	SET args=%args% %1
	SHIFT
	goto :while2
)
IF defined args SET args=%args:~1%

call compile.bat %args%
call run.bat %args%