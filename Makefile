run:
	g++ code.cpp -o video -pthread -std=c++11 `pkg-config --cflags --libs opencv`

