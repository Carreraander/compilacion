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
%token <str> RINTEGER RFLOAT RIF RELSE RDO RWHILE RFOREVER RENDREPEAT RUNTIL RENDPROGRAM RPROGRAM RPROCEDURE RIN ROUT RREAD RPRINTLN REXIT
%token <str> TMUL TDIV TPLUS TMINUS TASSIG 
%token <str> TSEMIC TLBRACE TRBRACE TCOMMA TLPAREN TRPAREN
%token <str> TEQUAL TNOTEQ TLESS TLESSEQ TGREATER TGREATEREQ
%token <str> TVAL TREF
%token <str> TINTEGER TDOUBLE TIDENTIFIER TCOMMENT


/* 
   declaración de no terminales. Por ej:
%type <str> expr
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
%type <expr> expresion
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
      {
      $$ = new vector<string>;
      *$$ = {};
      }
      ;

tipo : RINTEGER {*$$ = "ent";}
      | RFLOAT {*$$ = "real";}
      ;

decl_de_subprogs : decl_de_subprograma decl_de_subprogs
      | %empty
      ;

decl_de_subprograma : RPROCEDURE TIDENTIFIER 
                    {
                      codigo.anadirInstruccion("proc " + *$2 + ";");
                    } 
                    argumentos declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE
                    {
                      codigo.anadirInstruccion("endproc;");
                    }
                    ;

argumentos : TLPAREN lista_de_param TRPAREN
      | %empty
      ;

lista_de_param : tipo clase_par lista_de_ident
                {
                  codigo.anadirParametros(*$3, *$2, *$1);
                }
                resto_lis_de_param;

clase_par : TLESSEQ {$$ = $1;}
            | TREF  {$$ = $1;}
            ;

resto_lis_de_param : TSEMIC tipo clase_par lista_de_ident
                    {
                      codigo.anadirParametros(*$4, *$3, *$2);
                    }
                    resto_lis_de_param
                    | %empty
                    ;

lista_de_sentencias : lista_de_sentencias sentencia 
                      {
                        $$ = unir(*$1, *$2);
                      }
                      | %empty
                      {
                        $$ = new vector<int>;
                      }
                      ;

sentencia :  variable TASSIG expresion TSEMIC
      { 
        codigo.anadirInstruccion(*$1 + " := " + $3->str + ";") ; 
        delete $1 ; delete $3;
        $$ = new vector<int>;
      }
      | RIF expresion M TLBRACE lista_de_sentencias TRBRACE M TSEMIC
      { 
        codigo.completarInstrucciones($2->trues, $3);
        codigo.completarInstrucciones($2->falses, $7);
        $$ = $5;
      }
      | RWHILE RFOREVER TLBRACE M lista_de_sentencias M TRBRACE TSEMIC
      {
        $$ = new vector<int>;
        $$->push_back(codigo.obtenRef());
        codigo.anadirInstruccion("goto");
        codigo.completarInstrucciones(*$$, $4);
        $$ = $5;
      }
      | RDO TLBRACE M lista_de_sentencias TRBRACE RUNTIL M expresion RELSE M TLBRACE 
      lista_de_sentencias TRBRACE M TSEMIC
      { 
        $$ = new vector<int>;
        codigo.completarInstrucciones($8->falses, $3);
        codigo.completarInstrucciones($8->trues, $10);
        $$ = unir(*$4, *$12);
        //EXIT
        codigo.completarInstrucciones(*$4, $10);
        codigo.completarInstrucciones(*$12, $14);
        //FALTA EL SKIP
      }
      | RENDREPEAT RIF expresion M TSEMIC
      { 
        codigo.completarInstrucciones($3->falses, $4);
        *$$ = $3->trues;
        delete $3;
      }
      | REXIT TSEMIC
      {
        $$ = new vector<int>;
        $$->push_back(codigo.obtenRef());
        codigo.anadirInstruccion("goto");
      }
      | RREAD TLPAREN expresion TRPAREN TSEMIC
      { 
        $$ = new vector<int>;
      }
      | RPRINTLN TLPAREN expresion TRPAREN TSEMIC
      { 
        $$ = new vector<int>;
      }
      | TCOMMENT
      { 
        $$ = new vector<int>;
      }
      ;

variable : TIDENTIFIER
          {$$ = $1;}
          ;

expresion : expresion TEQUAL expresion
      { 
      $$ = new expresionstruct;
      *$$ = makecomparison($1->str,*$2,$3->str) ; 
      delete $1; delete $3;
      }
      | expresion TGREATER expresion
      { 
      $$ = new expresionstruct;
      *$$ = makecomparison($1->str,*$2,$3->str) ; 
      delete $1; delete $3;
      }
      | expresion TLESS expresion
      { 
      $$ = new expresionstruct;
      *$$ = makecomparison($1->str,*$2,$3->str) ; 
      delete $1; delete $3;
      }
      | expresion TGREATEREQ expresion
      { 
      $$ = new expresionstruct;
      *$$ = makecomparison($1->str,*$2,$3->str) ; 
      delete $1; delete $3;
      }
      | expresion TLESSEQ expresion
      { 
      $$ = new expresionstruct;
      *$$ = makecomparison($1->str,*$2,$3->str) ; 
      delete $1; delete $3;
      }
      | expresion TNOTEQ expresion
      { 
      $$ = new expresionstruct;
      *$$ = makecomparison($1->str,*$2,$3->str) ; 
      delete $1; delete $3;
      }
      | expresion TPLUS expresion 
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ;
        delete $1; delete $3; 
      }
      | expresion TMINUS expresion
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ;
        delete $1; delete $3; 
      }
      | expresion TMUL expresion
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ;
        delete $1; delete $3; 
      }
      | expresion TDIV expresion
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ;
        delete $1; delete $3; 
      }
      | variable
      { $$ = new expresionstruct; $$->str = *$1; }
      | TINTEGER
      { $$ = new expresionstruct; $$->str = *$1; }
      | TDOUBLE
      { $$ = new expresionstruct; $$->str = *$1; }
      | TLPAREN expresion TRPAREN
      { $$ = new expresionstruct;}
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
