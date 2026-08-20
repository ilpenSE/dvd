main: main.cpp Makefile
	c++ -o main main.cpp `pkg-config --cflags --libs raylib`
