all:
	gcc -Wno-int-to-void-pointer-cast -c main.c
	gcc -pthread -o primes main.o -lm
clean:
	rm primes main.o
