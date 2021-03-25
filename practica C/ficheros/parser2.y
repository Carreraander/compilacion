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
%left TMUL TDIV

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
%type <str> listasentencias
%type <str> definicionparametro
%type <str> tipovar
%type <str> listavars
%type <str> inout
%type <str> listasentenciassinproc
%type <str> sentencia
%type <str> if
%type <str> else
%type <str> do
%type <str> listasentenciasdo
%type <str> llamada
%type <str> pasodeparametros
%type <str> comparacion
%type <str> expr

%start programa

%%

programa : RPROGRAM TIDENTIFIER TLBRACE listasentencias TRBRACE;

listasentencias : sentencia listasentencias
      | RPROCEDURE TIDENTIFIER TLPAREN listaparametros TRPAREN TLBRACE listasentenciassinproc TRBRACE listasentencias
      | %empty
      ;

listaparametros : definicionparametro TSEMIC listaparametros
      | definicionparametro
      | %empty
      ;

definicionparametro : tipovar inout TIDENTIFIER;

tipovar : RINTEGER
      | RFLOAT
      ;

listavars : TIDENTIFIER TCOMMA listavars
      | TIDENTIFIER TSEMIC
      ;

inout : RIN
      | ROUT
      ;

listasentenciassinproc : sentencia listasentenciassinproc
      | %empty
      ;

sentencia : TIDENTIFIER TASSIG expr TSEMIC
          | TCOMMENT
          | tipovar listavars
          | if
          | do
          | llamada
          | RENDPROGRAM TSEMIC
          ;

if : RIF TIDENTIFIER comparacion expr TLBRACE listasentenciassinproc TRBRACE else TSEMIC
  | RIF TIDENTIFIER comparacion expr TSEMIC
  ;

else : RELSE TLBRACE listasentenciassinproc TRBRACE
    | %empty
    ;

do : RDO TLBRACE listasentenciasdo TRBRACE RUNTIL TIDENTIFIER comparacion expr TRBRACE TSEMIC;

listasentenciasdo : RENDREPEAT RIF TIDENTIFIER comparacion expr TSEMIC listasentenciassinproc
      | sentencia listasentenciasdo
      | %empty
      ;

llamada : TIDENTIFIER TLPAREN pasodeparametros TRPAREN TSEMIC;

pasodeparametros : TIDENTIFIER TCOMMA pasodeparametros
      | expr TCOMMA pasodeparametros
      | expr
      | TIDENTIFIER
      ;

comparacion : TCLT
      | TCGT
      | TEQUAL
      ;

expr : expr TPLUS expr
     | expr TMINUS expr
     | expr TMUL expr
     | expr TDIV expr
     | TLPAREN expr TRPAREN
     | TIDENTIFIER
     | TINTEGER
     | TDOUBLE
     ;