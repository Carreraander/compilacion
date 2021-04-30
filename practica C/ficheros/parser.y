%error-verbose

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

   #include "Codigo.hpp"
   #include "Exp.hpp"


   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;

   vector<int> *unir(vector<int> lis1, vector<int> lis2);


   Codigo codigo;

%}

/* 
   qué atributos tienen los símbolos 
*/
%union {
    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
    int number ;
    vector<int> *numlist;
}

/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/
%token <str> RINTEGER RFLOAT RIF RELSE RDO RWHILE RFOREVER RENDREPEAT RUNTIL RENDPROGRAM RPROGRAM RPROCEDURE RIN ROUT RREAD RPRINTLN
%token <str> TMUL TDIV TPLUS TMINUS TASSIG 
%token <str> TSEMIC TLBRACE TRBRACE TCOMMA TLPAREN TRPAREN
%token <str> TEQUAL TNOTEQ TLESS TLESSEQ TGREATER TGREATEREQ
%token <str> TVAL TREF
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
%type <list> lista_de_ident
%type <list> resto_lista_id
%type <str> tipo
%type <str> decl_de_subprogs
%type <str> decl_de_subprograma
%type <str> argumentos
%type <str> lista_de_param
%type <str> clase_par
%type <str> resto_lis_de_param
%type <str> variable
%type <str> expresion
%type <number> M
%type <numlist> N
%type <numlist> lista_de_sentencias
%type <numlist> sentencia

%nonassoc TEQUAL TNOTEQ TLESS TLESSEQ TGREATER TGREATEREQ
%left TPLUS TMINUS
%left TMUL TDIV

%start programa

%%

programa : RPROGRAM TIDENTIFIER 
          {
            codigo.anadirInstruccion("prog " + *$2 + ";");
          } 
          declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE
          {
            codigo.anadirInstruccion("halt;");
            codigo.escribir();
          }

declaraciones :  tipo lista_de_ident TSEMIC 
              {
                codigo.anadirDeclaraciones(*$2, *$1);
              }
      declaraciones
      | %empty
      ;

lista_de_ident : TIDENTIFIER resto_lista_id
      {
        $$ = new vector<string>;
        $2->push_back(*$1);
        $$ = $2;
      }
      ;

resto_lista_id : TCOMMA TIDENTIFIER resto_lista_id
      {
        $$ = new vector<string>;
        $3->push_back(*$2);
        $$ = $3;
      }
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

clase_par : TVAL
      | TLESSEQ
      | TREF
      ;

resto_lis_de_param : TSEMIC tipo clase_par lista_de_ident resto_lis_de_param
      | %empty
      ;

lista_de_sentencias : lista_de_sentencias sentencia 
      | %empty
      ;

sentencia :  variable TASSIG expresion TSEMIC
      { 
        //Falta inicializar el atributo de stmt
        $$ = new vector<int>;
      }
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

M: %empty { $$ = codigo.obtenRef() ; }
  ;

N: %empty {
  $$ = new vector<int>; 
        vector<int> tmp1 ; tmp1.push_back(codigo.obtenRef()) ;
  *$$ = tmp1;
  codigo.anadirInstruccion("goto");}
        ;

%%

expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 
  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}


expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 
  tmp.str = codigo.nuevoId() ;
  codigo.anadirInstruccion(tmp.str + ":=" + s1 + s2 + s3 + ";") ;     
  return tmp ;
}

//Falta la función unir
vector<int> *unir(vector<int> lis1, vector<int> lis2){
  std::vector<int> *nuevalista = new vector<int>;
  nuevalista->insert(nuevalista->begin(), lis1.begin(), lis1.end());
  nuevalista->insert(nuevalista->end(), lis2.begin(), lis2.end());
  return nuevalista;
}
