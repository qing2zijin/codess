#learn from : https://blog.csdn.net/weixin_38391755/article/details/80380786

#edit: main.o 
#	cc -o edit main.o
#main.o: main.c  
#	cc -c main.c
#clean: 
#	rm edit main.o 
#

object_1 = main_extern.o support.o

extern: $(object_1)
	g++ -o extern $(object_1)
main_extern.o: main_extern.cpp  
	g++ -c main_extern.cpp
support.o: support.cpp
	g++ -c support.cpp
clean:
	rm extern $(object_1)


