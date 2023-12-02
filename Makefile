all :
	g++ -o exe *.cpp

run :
	./exe

clean :
	rm exe
	clear

debug:
	g++ -g -o exe *.cpp
zip :
	zip exe *.cpp *.hpp Makefile
