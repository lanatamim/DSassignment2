all:
	g++ -c *.cpp
	g++ *.o -o assgn2.out

clean:
	rm *.out
	rm *.o