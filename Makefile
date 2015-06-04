main: main.o hashtable.o
	g++ main.o hashtable.o -o main

main.o: main.cpp hashtable.h 
	g++ main.cpp -c 

hashtable.o: hashtable.cpp hashtable.h
	g++ hashtable.cpp -c

clean:
	rm *.o main
