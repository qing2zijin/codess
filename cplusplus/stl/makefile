
#appout: vector.o 	\
	g++ -o appout vector.o 	

#vector.o: vector.cpp 	\
	g++ -c  vector.cpp 

#clean:  \
	rm appout vector.o

main: list.o
	g++ -o main list.o
list.o: list.cpp
	g++ -c list.cpp
clean:
	rm main list.o
