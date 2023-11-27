all :
	g++ -o exe *.cpp

run :
	./exe

clean :
	rm *.o
	rm exe
	clear

zip :
	zip exe *.cpp *.hpp Makefile