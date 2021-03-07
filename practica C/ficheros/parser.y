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

/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/
%token <str> TIDENTIFIER TINTEGER TDOUBLE TCOMMENT
%token <str> TMUL TDIV TPLUS TMINUS
%token <str> TSEMIC TASSIG TLBRACE TRBRACE TCOMMA TLPAREN TRPAREN
%token <str> TEQUAL TCLT TCGT
%token <str> RINTEGER RFLOAT RIF RELSE RDO RENDREPEAT RUNTIL RENDPROGRAM
%token <str> RPROGRAM RPROCEDURE RIN ROUT

/* 
   declaración de no terminales. Por ej:
%type <str> expr
*/

%type <str> programa

%start programa

%%

programa : RPROGRAM  
           TIDENTIFIER 
	         TLBRACE
	         listasentencias
	         TRBRACE
          ;

listasentencias : listasentencias sentencia
      | %empty
      ;

sentencia : TIDENTIFIER TASSIG expr TSEMIC
          | TCOMMENT
          ;

expr : TIDENTIFIER
     | TINTEGER
     | TDOUBLE
     ;

