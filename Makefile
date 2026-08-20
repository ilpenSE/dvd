main: main.cpp Makefile
	g++ -std=c++23 -ggdb -O0 -o main main.cpp `pkg-config --cflags --libs raylib`
