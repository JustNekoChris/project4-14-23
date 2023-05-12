all: compile link

compile:
	g++ -Isrc/include -c main.cpp Board.cpp

link:
	g++ main.o Board.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

