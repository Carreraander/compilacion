CFLAGS=-Wall

all: tokens prueba

clean:
	rm tokens tokens.cpp *~

tokens.cpp: tokens.l tokens.hpp
	lex -o $@ tokens.l

tokens: tokens.cpp 
	g++ $(CFLAGS) -o $@ *.cpp -ll

prueba:  tokens  prueba2.in
	./tokens <prueba2.in
