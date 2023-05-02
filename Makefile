all: compile link
compile:
	g++ -Isrc/include -c main.cpp
link:
	g++ main.o -o sfml-app -L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system
