main: main.o
	g++ -o main main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp cards.hpp
clean:
	rm main main.o *.gch
