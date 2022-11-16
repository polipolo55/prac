flags = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11


all: program.o Alfabets.o Alfabet.o Missatges.o
	g++ -o program.exe program.o Alfabets.o Alfabet.o Missatges.o

program: program.cc
	g++ -c program.cc $(flags)

Alfabets: Alfabets.cc
	g++ -c Alfabets.cc $(flags)

Missatges: Missatges.cc
	g++ -c Missatges.cc $(flags)

Alfabet: Alfabet.cc
	g++ -c Alfabet.cc $(flags)

tar: Alfabet.cc Alfabet.hh Alfabets.cc Alfabets.hh Missatges.cc Missatges.hh program.cc
	tar -cvf practica.tar Alfabet.cc Alfabet.hh Alfabets.cc Alfabets.hh Missatges.cc Missatges.hh program.cc

clean:
	rm -f *.o
	rm -f *.exe
