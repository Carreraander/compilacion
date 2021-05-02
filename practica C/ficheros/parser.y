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

   #include "Codigo.hpp"
   #include "Exp.hpp"


   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;

   vector<int> *unir(vector<int> lis1, vector<int> lis2);

   Codigo codigo;

   void yyerror (const char *msg) {
    stringstream cadena;
    cadena << "line " << yylineno << ": " << msg << " at " << yytext;
    codigo.anadirError(cadena.str());
   }

%}

/* 
   qué atributos tienen los símbolos 
*/
%union {
    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
    int number ;
    numliststruct *numlist;
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
      | TCOMMENT declaraciones
      | declaraciones TCOMMENT
      | error declaraciones
      | %empty
      ;

lista_de_ident : TIDENTIFIER resto_lista_id
      {
      $$ = new vector<string>;
      $2->push_back(*$1);
      $$ = $2;
      }
      | lista_de_ident TCOMMENT
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
      | resto_lista_id TCOMMENT
      ;

tipo : RINTEGER {*$$ = "ent";}
      | RFLOAT {*$$ = "real";}
      | TCOMMENT tipo
      | tipo TCOMMENT
      ;

decl_de_subprogs : decl_de_subprograma decl_de_subprogs
      | %empty
      | TCOMMENT decl_de_subprogs
      | decl_de_subprogs TCOMMENT
      | error decl_de_subprogs
      ;

decl_de_subprograma : RPROCEDURE TIDENTIFIER 
                    {
                      codigo.anadirInstruccion("proc " + *$2 + ";");
                    } 
                    argumentos declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE
                    {
                      codigo.anadirInstruccion("endproc;");
                    }
                    | error argumentos declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE
                    {
                      codigo.anadirInstruccion("endproc;");
                    }
                    ;

argumentos : TLPAREN lista_de_param TRPAREN
      | %empty
      | TCOMMENT argumentos
      | argumentos TCOMMENT
      | error argumentos
      ;

lista_de_param : tipo clase_par lista_de_ident
                {
                  codigo.anadirParametros(*$3, *$2, *$1);
                }
                resto_lis_de_param;
                | TCOMMENT lista_de_param
                | lista_de_param TCOMMENT
                | error resto_lis_de_param
                ;

clase_par : TLESSEQ {$$ = $1;}
            | TREF  {$$ = $1;}
            | TCOMMENT clase_par
            | clase_par TCOMMENT
            ;

resto_lis_de_param : TSEMIC tipo clase_par lista_de_ident
                    {
                      codigo.anadirParametros(*$4, *$3, *$2);
                    }
                    resto_lis_de_param
                    | TCOMMENT resto_lis_de_param
                    | resto_lis_de_param TCOMMENT
                    | %empty
                    | error resto_lis_de_param
                    ;

lista_de_sentencias : lista_de_sentencias sentencia 
                      {
                        $$ = new numliststruct;
                        $$->exit = *(unir($2->exit, $1->exit));
                        $$->skip = *(unir($2->skip, $1->skip));
                      }
                      | %empty
                      {
                        $$ = new numliststruct;
                      }
                      | lista_de_sentencias TCOMMENT
                      | error lista_de_sentencias
                      ;

sentencia :  variable TASSIG expresion TSEMIC
      { 
        codigo.anadirInstruccion(*$1 + " := " + $3->str + ";") ; 
        delete $1 ; delete $3;
        $$ = new numliststruct;
      }
      | RIF expresion M TLBRACE lista_de_sentencias TRBRACE M TSEMIC
      { 
        codigo.completarInstrucciones($2->trues, $3);
        codigo.completarInstrucciones($2->falses, $7);
        //EXIT
        $$->exit = $5->exit;
      }
      | RWHILE RFOREVER TLBRACE M lista_de_sentencias M TRBRACE TSEMIC
      {
        $$ = new numliststruct;
        stringstream cadena;
        cadena << " " << $4;
        codigo.anadirInstruccion("goto" + cadena.str() + ";");
        //EXIT
        codigo.completarInstrucciones($5->exit, $6);
        $$->exit = $5->exit;
      }
      | RDO TLBRACE M lista_de_sentencias TRBRACE RUNTIL M expresion RELSE M TLBRACE 
      lista_de_sentencias TRBRACE M TSEMIC
      { 
        $$ = new numliststruct;
        codigo.completarInstrucciones($8->falses, $3);
        codigo.completarInstrucciones($8->trues, $10);
        $$->exit = *(unir($4->exit, $12->exit));
        //EXIT
        codigo.completarInstrucciones($4->exit, $10);
        codigo.completarInstrucciones($12->exit, $14);
        //FALTA EL SKIP
        codigo.completarInstrucciones($4->skip, $7);
      }
      | RENDREPEAT RIF expresion M TSEMIC
      { 
        $$ = new numliststruct;
        codigo.completarInstrucciones($3->falses, $4);
        $$->skip = $3->trues;
        delete $3;
      }
      | REXIT TSEMIC
      {
        $$ = new numliststruct;
        $$->exit.push_back(codigo.obtenRef());
        codigo.anadirInstruccion("goto");
      }
      | RREAD TLPAREN expresion TRPAREN TSEMIC
      { 
        $$ = new numliststruct;
        codigo.anadirInstruccion("read " + $3->str + ";");
      }
      | RPRINTLN TLPAREN expresion TRPAREN TSEMIC
      { 
        $$ = new numliststruct;
        codigo.anadirInstruccion("write " + $3->str + ";");
        codigo.anadirInstruccion("writeln;");
      }
      | sentencia TCOMMENT
      { 
        $$ = new numliststruct;
      }
      ;

variable : TIDENTIFIER
          {$$ = $1;}
          | TCOMMENT variable
          | variable TCOMMENT
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
      { $$ = new expresionstruct; $$->str = $2->str; }
      | expresion TCOMMENT
      ;

M: %empty { $$ = codigo.obtenRef() ; }
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
