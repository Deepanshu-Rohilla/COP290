run:
	g++ code.cpp -o video -pthread -w -std=c++11 `pkg-config --cflags --libs opencv`

