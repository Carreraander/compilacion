%{
   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
   }

%}

/* 
   qué atributos tienen los tokens 
*/
%union {
    string *str ; 
}
%left TMUL TDIV TPLUS TMINUS

/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/
%token <str> RINTEGER RFLOAT RIF RELSE RDO RWHILE RFOREVER RENDREPEAT RUNTIL RENDPROGRAM RPROGRAM RPROCEDURE RIN ROUT RREAD RPRINTLN
%token <str> TMUL TDIV TPLUS TMINUS TASSIG 
%token <str> TSEMIC TLBRACE TRBRACE TCOMMA TLPAREN TRPAREN
%token <str> TEQUAL TLESS TLESSEQ TGREATER TGREATEREQ TNOTEQ TLESSEQGREATER
%token <str> TINTEGER TDOUBLE TIDENTIFIER TCOMMENT


/* 
   declaración de no terminales. Por ej:
%type <str> expr
*/
      /*
      TODO:
            Linea 108: ¿El until debe tener un else o unicamente puede ser un until?
            Linea 111: ¿El Read deberia tener una unica variable o una expresion?
      */
%type <str> programa
%type <str> declaraciones
%type <str> lista_de_ident
%type <str> resto_lista_id
%type <str> tipo
%type <str> decl_de_subprogs
%type <str> decl_de_subprograma
%type <str> argumentos
%type <str> lista_de_param
%type <str> clase_par
%type <str> resto_lis_de_param
%type <str> lista_de_sentencias
%type <str> sentencia
%type <str> variable
%type <str> expresion

%start programa

%%

programa : RPROGRAM TIDENTIFIER declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE;

declaraciones :  tipo lista_de_ident TSEMIC declaraciones
      | %empty
      ;

lista_de_ident : TIDENTIFIER resto_lista_id;

resto_lista_id :  TCOMMA TIDENTIFIER resto_lista_id
      | %empty
      ;

tipo : RINTEGER
      | RFLOAT
      ;

decl_de_subprogs : decl_de_subprograma decl_de_subprogs
      | %empty
      ;

decl_de_subprograma : RPROCEDURE TIDENTIFIER argumentos declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE;

argumentos : TLPAREN lista_de_param TRPAREN
      | %empty
      ;

lista_de_param : tipo clase_par lista_de_ident resto_lis_de_param;

clase_par : TGREATEREQ
      | TLESSEQ
      | TLESSEQGREATER
      ;

resto_lis_de_param : TSEMIC tipo clase_par lista_de_ident resto_lis_de_param
      | %empty
      ;

lista_de_sentencias : lista_de_sentencias sentencia 
      | %empty
      ;

sentencia :  variable TASSIG expresion TSEMIC
      | RIF expresion TLBRACE lista_de_sentencias TRBRACE TSEMIC
      | RIF expresion TLBRACE lista_de_sentencias TRBRACE RELSE TLBRACE lista_de_sentencias TRBRACE TSEMIC
      | RWHILE RFOREVER TLBRACE lista_de_sentencias TRBRACE TSEMIC
      | RDO TLBRACE lista_de_sentencias TRBRACE RUNTIL expresion RELSE TLBRACE lista_de_sentencias TRBRACE TSEMIC
      | RENDREPEAT RIF expresion TSEMIC
      | RENDPROGRAM TSEMIC
      | RREAD TLPAREN expresion TRPAREN TSEMIC
      | RPRINTLN TLPAREN expresion TRPAREN TSEMIC
      | TCOMMENT
      | declaraciones
      | decl_de_subprogs
      ;

variable : TIDENTIFIER;

expresion : expresion TEQUAL expresion
      | expresion TGREATER expresion
      | expresion TLESS expresion
      | expresion TGREATEREQ expresion
      | expresion TLESSEQ expresion
      | expresion TNOTEQ expresion
      | expresion TPLUS expresion
      | expresion TMINUS expresion
      | expresion TMUL expresion
      | expresion TDIV expresion
      | variable
      | TINTEGER
      | TDOUBLE
      | TLPAREN expresion TRPAREN
      ;

