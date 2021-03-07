CFLAGS=-Wall

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser tokens.cpp

parser.cpp: parser.y
	bison -d -o $@ $^

parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp
	lex -o $@ $^

parser: parser.cpp main.cpp tokens.cpp
	g++ $(CFLAGS) -o $@ *.cpp -ll

prueba: parser ./Pruebas
	./parser <./Pruebas/PruebaBuena1.in
	./parser <./Pruebas/PruebaBuena2.in
	./parser <./Pruebas/Error_en_el_println.in
	./parser <./Pruebas/Error_Comentario.in
	./parser <./Pruebas/Proc_sin_cerrar.in

