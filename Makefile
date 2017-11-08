all:
	g++ -std=c++17 main.cpp Annotate.cpp Controller.cpp -lstdc++fs -o annotate `pkg-config --cflags --libs opencv`
