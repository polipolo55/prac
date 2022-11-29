flags = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Alfabet.o Missatge.o Alfabets.o Missatges.o
	g++ -o program.exe program.o Alfabet.o Missatge.o Alfabets.o Missatges.o BinTree.hh
#
program.o: program.cc Alfabet.hh Missatge.hh Alfabets.hh Missatges.hh
	g++ -c program.cc $(flags) 
#
Alfabet.o: Alfabet.cc Alfabet.hh
	g++ -c Alfabet.cc $(flags) 
#
Missatge.o: Missatge.cc Missatge.hh
	g++ -c Missatge.cc $(flags) 
#
Alfabets.o: Alfabets.cc Alfabets.hh
	g++ -c Alfabets.cc $(flags) 
#
Missatges.o: Missatges.cc Missatges.hh 
	g++ -c Missatges.cc $(flags) 
#
tar: program.cc Alfabet.hh Missatge.hh Alfabets.hh Missatges.hh  Alfabet.cc Missatge.cc Alfabets.cc Missatges.cc BinTree.hh Makefile
	tar cvf practica.tar program.cc Alfabet.hh Missatge.hh Alfabets.hh Missatges.hh  Alfabet.cc Missatge.cc Alfabets.cc Missatges.cc BinTree.hh Makefile
#
clean:
	rm -f *.o
	rm -f *.exe