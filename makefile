CPPFLAGS=-std=c++11 -g -O3
EXECUTABLE=prog

all: mymain.o	
	g++ mymain.o -o $(EXECUTABLE)

mymain.o: mymain.cpp LinkedList.h Node.h
	g++ $(CPPFLAGS) -c mymain.cpp

clean: 
	rm -f *.o
	rm -f $(EXECUTABLE)
