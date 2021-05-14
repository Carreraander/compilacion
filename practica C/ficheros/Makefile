CFLAGS=-Wall
FUENTES=parser.cpp main.cpp tokens.cpp Codigo.cpp TablaSimbolos.cpp PilaTablaSimbolos.cpp

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser tokens.cpp *~

parser.cpp parser.hpp: parser.y 
	bison -d -o $@ $<

tokens.cpp: tokens.l parser.hpp 
	lex -o $@ $<

parser: $(FUENTES) Codigo.hpp Exp.hpp
	g++ $(CFLAGS) -o $@ $(FUENTES) 

prueba: parser ./Pruebas
	./parser <./Pruebas/PruebaBuena1.in
	./parser <./Pruebas/PruebaBuena2.in
	./parser <./Pruebas/PruebaMala1.in
	./parser <./Pruebas/PruebaMala2.in

