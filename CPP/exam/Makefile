main: main.o
	g++ main.o -o main

main.o: main.cpp build.hpp supplier.hpp materials.hpp receipt.hpp
	g++ -c main.cpp

clean:
	rm main *.o
