@echo OFF

echo Compiling Main.cpp
g++ -std=gnu++11 -O3 -o bin\PhotonMapper.exe src\Main.cpp src\*\*.cpp -lglu32 -lopengl32 -lfreeglut