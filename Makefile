main: main.c Makefile
	cc -o main main.c `pkg-config --cflags --libs raylib`
