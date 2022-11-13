flags = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11


all: program.o Alfabets.o Alfabet.o Missatges.o Encriptacions.o
	g++ -o program.exe *.o

program: program.cc
	g++ -c program.cc $(flags)

Alfabets: Alfabets.cc
	g++ -c Alfabets.cc $(flags)

Missatges: Missatges.cc
	g++ -c Missatges.cc $(flags)

Encriptacions: Encriptacions.cc
	g++ -c Encriptacions.cc $(flags)

Alfabet: Alfabet.cc
	g++ -c Alfabet.cc $(flags)

clean:
	rm -f *.o
	rm -f *.exe
