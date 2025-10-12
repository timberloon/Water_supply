all:
	g++ graph.cpp main.cpp program.cpp texmanager.cpp map.cpp -o main.exe -Isdl/src/include -Lsdl\src\lib -lSDL3 -lSDL3_image -static-libstdc++ -static-libgcc