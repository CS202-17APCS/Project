test: ./threadTest.cpp
	g++ -std=c++11 -Wall -pthread ./threadTest.cpp -o test
clean:
	rm -f main *.o

