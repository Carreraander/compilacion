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

// Añado la declaración de la función unir. Si la hacéis diferente, debéis cambiar esta declaración.
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
%token <str> TIDENTIFIER TINTEGER TDOUBLE
%token <str> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <str> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT
%token <str> TPLUS TMINUS TMUL TDIV
%token <str> TCOLON TSEMIC TASSIG
%token <str> RPROGRAM RIS RBEGIN RENDPROGRAM RVAR RINTEGER RFLOAT RENDPROCEDURE RPROCEDURE RIN ROUT RIF RTHEN RELSE RENDIF RGET RPUT_LINE RWHILE RDO RENDWHILE REXIT
//Falta declarar los nuevos tokens

%type <str> ident
%type <str> numeric 
%type <expr> expr
%type <str> program 
%type <str> decls 
%type <str> type 
%type <list> list 
%type <number> M
%type <numlist> N
%type <numlist> stmt
%type <numlist> stmts


%nonassoc TCEQ TCNE TCLT TCLE TCGT TCGE
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : RPROGRAM { codigo.anadirInstruccion("prog;" ) ;} 
          ident RIS
	      decls
	      RBEGIN
	      stmts 
	      RENDPROGRAM TSEMIC {
            codigo.anadirInstruccion("halt;");
		    codigo.escribir() ; 
           }
        ;


decls : /*blank*/ {}
      | decls decl {} 
      ;

decl : RVAR list TCOLON type TSEMIC {
         codigo.anadirDeclaraciones(*$2,*$4);
         delete $2; delete $4 ;
        }
	;

type : RFLOAT 
     | RINTEGER 
     ;

list : ident {
         $$ = new vector<string> ; 
	     $$->push_back(*$1);
        }
     | list TCOMMA ident { 
         $$ = $1 ;
         $$->push_back(*$3);
        } 
     ;

stmts : stmt TSEMIC
       {
        $$ = $1;
       } //Añadir la acción correspondiente
      | stmts stmt TSEMIC //Añadir la acción correspondiente
      {
        $$ = new vector<int>;
        $$ = unir(*$1, *$2);
      }
      ;

stmt :  ident TASSIG expr { 
          codigo.anadirInstruccion(*$1 + *$2 + $3->str + ";") ; 
    	  delete $1 ; delete $3;
	 //Falta inicializar el atributo de stmt
        $$ = new vector<int>;
         }
	
	|  RIF expr RTHEN M
        stmts   N 
		RELSE
        M stmts M RENDIF 
	{
          
	      	codigo.completarInstrucciones($2->trues,$4) ;
    	  	codigo.completarInstrucciones($2->falses,$8) ;
    	  	
    	  	codigo.completarInstrucciones(*$6, $10) ;
	      	delete $2 ;
 		//Falta inicializar el atributo de stmt
		      $$ = unir(*$5, *$9);
         }


        | RWHILE M
        expr RDO M
	stmts M RENDWHILE
	{ codigo.completarInstrucciones($3->trues,$5) ;
    	  codigo.completarInstrucciones($3->falses,$7+1) ;
	 
    	  codigo.anadirInstruccion("goto");
	  vector<int> tmp1 ; tmp1.push_back($7) ;
    	  codigo.completarInstrucciones(tmp1, $2) ;

    //Falta completar stmts.exit
    codigo.completarInstrucciones(*$6, $7+1);
 	  //Falta inicializar el atributo de stmt
    $$ = new vector<int>;
    
	}  
	
		
	| REXIT RIF expr M
	{ 
    codigo.completarInstrucciones($3->falses, $4);
    *$$ = $3->trues;
    delete $3;
	}

  | REXIT
  {
    $$ = new vector<int>;
    $$->push_back(codigo.obtenRef());
    codigo.anadirInstruccion("goto");
  }
       ;


M:  { $$ = codigo.obtenRef() ; }
	;

N:  {
	$$ = new vector<int>;	
        vector<int> tmp1 ; tmp1.push_back(codigo.obtenRef()) ;
	*$$ = tmp1;
	codigo.anadirInstruccion("goto");}
        ;

expr : ident   { $$ = new expresionstruct; $$->str = *$1; }
     | numeric { $$ = new expresionstruct; $$->str = *$1; }
     | TLPAREN expr TRPAREN { $$ = $2; }

     | expr TPLUS expr  { $$ = new expresionstruct;
			 *$$ = makearithmetic($1->str,*$2,$3->str) ;
			delete $1; delete $3; }
     | expr TMINUS expr { $$ = new expresionstruct;
			 *$$ = makearithmetic($1->str,*$2,$3->str) ;
			delete $1; delete $3; }
     | expr TMUL expr   { $$ = new expresionstruct;
			 *$$ = makearithmetic($1->str,*$2,$3->str) ;
			delete $1; delete $3; }
     | expr TDIV expr   {$$ = new expresionstruct;
			 *$$ = makearithmetic($1->str,*$2,$3->str) ;
			delete $1; delete $3; }
     | expr TCEQ expr { $$ = new expresionstruct;
			 *$$ = makecomparison($1->str,*$2,$3->str) ; 
			delete $1; delete $3; }
     | expr TCNE expr { $$ = new expresionstruct;
			 *$$ = makecomparison($1->str,*$2,$3->str) ; 
			delete $1; delete $3; }
     | expr TCLT expr { $$ = new expresionstruct;
			 *$$ = makecomparison($1->str,*$2,$3->str) ; 
			delete $1; delete $3; }
     | expr TCLE expr { $$ = new expresionstruct;
			 *$$ = makecomparison($1->str,*$2,$3->str) ; 
			delete $1; delete $3; }
     | expr TCGT expr { $$ = new expresionstruct;
			 *$$ = makecomparison($1->str,*$2,$3->str) ; 
			delete $1; delete $3; }
     | expr TCGE expr { $$ = new expresionstruct;
			 *$$ = makecomparison($1->str,*$2,$3->str) ; 
			delete $1; delete $3; }
     ;

ident : TIDENTIFIER { $$ = $1 ; }
      ;

numeric : TINTEGER { $$ = $1; }
        | TDOUBLE  { $$ = $1; }
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
