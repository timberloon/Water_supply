all:
	g++ graph.cpp main.cpp program.cpp texmanager.cpp map.cpp house.cpp object.cpp vector2.cpp sampler.cpp background.cpp sprite.cpp algorithms.cpp supplier.cpp text.cpp -o main.exe -Isdl/src/include -Lsdl\src\lib -lSDL3 -lSDL3_image -lsdl3_ttf -static-libstdc++ -static-libgcc
run:
	./main