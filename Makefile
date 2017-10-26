all:
	g++ -std=c++17 main.cpp Label.cpp Annotate.cpp -lstdc++fs -o annotate `pkg-config --cflags --libs opencv`
