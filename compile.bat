@echo OFF

SET target=all

IF NOT "%1" == "-t" GOTO :endif
	SET target=%2
	SHIFT
	SHIFT
:endif

echo Compiling %target%


IF "%target%" == "all" GOTO :compileall
g++ -std=gnu++11 -O3 -o obj/%target%.o -c src/*/%target%.cpp -I./include -lglu32 -lopengl32 -lfreeglut

GOTO :end

:compileall

cd obj
g++ -std=gnu++11 -O3 -c ../src/*/*.cpp -I../include -lglu32 -lopengl32 -lfreeglut
cd ..

:end

g++ -std=gnu++11 -O3 -o bin/PhotonMapper.exe src/Main.cpp obj/*.o -I./include -lglu32 -lopengl32 -lfreeglut
