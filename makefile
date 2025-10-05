all:
	g++ graph.cpp render.cpp program.cpp -o render.exe -Isdl/src/include -Lsdl\src\lib -lSDL3 -lSDL3_image -static-libstdc++ -static-libgcc