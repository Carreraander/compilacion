CFLAGS=-Wall
FUENTES=parser.cpp main.cpp tokens.cpp Codigo.cpp

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser tokens.cpp *~

parser.cpp parser.hpp: parser.y Codigo.hpp Exp.hpp
	bison -d -o $@ $<

tokens.cpp: tokens.l parser.hpp Exp.hpp
	lex -o $@ $<

parser: $(FUENTES) Codigo.hpp Exp.hpp
	g++ $(CFLAGS) -o $@ $(FUENTES) 

prueba:  
	./parser <prueba1.in	
	./parser <prueba2.in
	./parser <prueba3.in
