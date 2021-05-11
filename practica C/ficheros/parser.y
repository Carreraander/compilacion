%error-verbose

%{
   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   #include <iterator>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;

   #include "Codigo.hpp"
   #include "Exp.hpp"
   #include "TablaSimbolos.hpp"
   #include "PilaTablaSimbolos.hpp"

   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) ;
   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3, std::vector<std::string> &s4) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;

   vector<int> *unir(vector<int> lis1, vector<int> lis2);
   
   Codigo codigo;
   PilaTablaSimbolos stPila;
   TablaSimbolos st;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
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
%token <str> RINTEGER RFLOAT RIF RELSE RDO RWHILE RNOT RFOREVER RENDREPEAT RUNTIL RENDPROGRAM RPROGRAM RPROCEDURE RIN ROUT RREAD RPRINTLN REXIT ROR
%token <str> TMUL TDIV TPLUS TMINUS TASSIG 
%token <str> TSEMIC TLBRACE TRBRACE TCOMMA TLPAREN TRPAREN TRCOR TLCOR
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
%type <list> array_id
%type <expr> expresion
%type <number> M
%type <numlist> lista_de_sentencias
%type <numlist> sentencia

%left TEQUAL TNOTEQ TLESS TLESSEQ TGREATER TGREATEREQ ROR RNOT
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
                TablaSimbolos st1;
                st1.anadirProcedimiento($2->back());
                
                //codigo.anadirInstruccion($2->back());
                std::string identificador = $2->back();
                $2->pop_back();
                int n = $2->size();
                
                //Guardar parametros menos el front ya que es el identificador, cuidado valor de n
                for (int i = 0; i < n-1;i++){
                  st1.anadirParametro(identificador,*$1,$2->back());
                  $2->pop_back();
                }
                //st1.anadirVariable($2->back(),*$1);

                string str;
                int n1 = st1.numArgsProcedimiento(identificador);
                stringstream ss;  
                ss << n1;  
                ss >> str;  
                
                //codigo.anadirInstruccion(str);
                //$2->pop_back();
                stPila.empilar(st1);
                codigo.anadirDeclaraciones(*$2, *$1);
              }
        declaraciones
      | TCOMMENT declaraciones
      | declaraciones TCOMMENT
      | %empty
      ;

//TODO: ARREGLAR LISTA DE IDENTIFICADORES PARA AÑADIR ARRAYS
// int ander[],juan[],pedro[];

lista_de_ident : TIDENTIFIER resto_lista_id
      {
        $$ = new vector<string>;
        $2->push_back(*$1);
        $$ = $2;
      }
      | TIDENTIFIER TLCOR variable TRCOR array_id resto_lista_id
      {
        $$ = new vector<string>;
        // Creamos un vector auxiliar del mismo tamaño que el vector de id de arrays
        int n = $5->size();
        std::vector<string> aux(n+1);
        std::ostringstream oss;
        //Guardamos en el vector auxiliar las dimensiones del array junto con su identificador 
        for (auto &auxi : *$5){
             aux.push_back("[" + auxi + "]");
        }
        aux.push_back("[" + *$3 + "]");
        
        //Convertimos en string para que no haya problemas a la hora de mostrar por pantalla.

        std::copy(aux.rbegin(), aux.rend(),
          std::ostream_iterator<string>(oss));

        //Insertamos en la lista de identificadores el identificador + dimensiones
        $6->push_back(*$1 + oss.str());

        //codigo.anadirInstruccion($5->back());
        //añadimos tipo de cada dimension a la cola
        for (auto &auxi : *$5){
          $6->push_back(auxi);
        }
        $6->push_back(*$3);
        $6->push_back(*$1);
        string str;
        
        stringstream ss;  
        ss << n;  
        ss >> str;

        //codigo.anadirInstruccion(str);
        $$ = $6;

      }
      | TIDENTIFIER TLCOR TRCOR resto_lista_id
      {
      $$ = new vector<string>;
      $4->push_back(*$1 + *$2 + *$3);
      $$ = $4;
      }
      | lista_de_ident TCOMMENT
      ;

resto_lista_id : TCOMMA TIDENTIFIER resto_lista_id
      {
      $$ = new vector<string>;
      $3->push_back(*$2);
      $$ = $3;
      }
      | TCOMMA TIDENTIFIER array_id resto_lista_id
      {
        $$ = new vector<string>;
        $4->push_back(*$2 + "[" + $3->back() + "]");
        //$3->push_back(*$1);
        $$ = $4;
      }
      | TCOMMA TIDENTIFIER TLCOR TRCOR resto_lista_id
      {
      $$ = new vector<string>;
      $5->push_back(*$1 + *$3 + *$4);
      $$ = $5;
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

array_id : TLCOR variable TRCOR array_id 
      {
        $$ = new vector<string>;
        $4->push_back(*$2);
        $$ = $4;
      }
      | %empty
      {
        $$ = new vector<string>;
        *$$ = {};
      }
      ;


decl_de_subprogs : decl_de_subprograma decl_de_subprogs
      | %empty
      | TCOMMENT decl_de_subprogs
      | decl_de_subprogs TCOMMENT
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
      | TCOMMENT argumentos
      | argumentos TCOMMENT
      ;

lista_de_param : tipo clase_par lista_de_ident
                {
                  codigo.anadirParametros(*$3, *$2, *$1);
                }
                resto_lis_de_param;
                | TCOMMENT lista_de_param
                | lista_de_param TCOMMENT
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
      | RREAD TLPAREN variable TRPAREN TSEMIC
      { 
        $$ = new numliststruct;
        codigo.anadirInstruccion("read " + *$3 + ";");
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
      }
      | expresion TGREATER expresion
      { 
        $$ = new expresionstruct;
        if ($1->arr.empty())
          *$$ = makecomparison($1->str,*$2,$3->str) ; 
        else
          *$$ = makecomparison($1->str,*$2,$3->str,$1->arr) ; 
      }
      | expresion TLESS expresion
      { 
        $$ = new expresionstruct;
        *$$ = makecomparison($1->str,*$2,$3->str) ;    
      }
      | expresion TGREATEREQ expresion
      { 
        $$ = new expresionstruct;
        *$$ = makecomparison($1->str,*$2,$3->str) ; 
      }
      | expresion TLESSEQ expresion
      { 
        $$ = new expresionstruct;
        *$$ = makecomparison($1->str,*$2,$3->str) ; 
      }
      | expresion TNOTEQ expresion
      { 
        $$ = new expresionstruct;
        *$$ = makecomparison($1->str,*$2,$3->str) ; 
      }
      | expresion ROR M expresion
      {
        $$ = new expresionstruct;
        expresionstruct tmp;
        codigo.completarInstrucciones($1->falses, $3);
        tmp.trues = *(unir($1->trues, $4->trues));
        tmp.falses = $4->falses;
        *$$ = tmp;
      }
      | RNOT expresion
      {
        $$ = new expresionstruct;
        expresionstruct tmp;
        tmp.trues = $2->falses;
        tmp.falses = $2->trues;
        *$$ = tmp;
      }
      | expresion TPLUS expresion 
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ;
      }
      | expresion TMINUS expresion
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ;
      }
      | expresion TMUL expresion
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ; 
      }
      | expresion TDIV expresion
      { 
        $$ = new expresionstruct;
        *$$ = makearithmetic($1->str,*$2,$3->str) ;
      }
      | variable
      { 
        $$ = new expresionstruct; 

        $$->str = *$1;
      }
      | TINTEGER
      { $$ = new expresionstruct; $$->str = *$1; }
      | TDOUBLE
      { $$ = new expresionstruct; $$->str = *$1; }
      | TLPAREN expresion TRPAREN
      { $$ = new expresionstruct; $$->str = $2->str; }
      | TIDENTIFIER TLCOR variable TRCOR array_id
      { 
        // $$ = new expresionstruct; 
        // // Creamos un vector auxiliar del mismo tamaño que el vector de id de arrays
        // int n = $2->size();
        // std::vector<string> aux(n);
        // std::ostringstream oss;
        // //Guardamos en el vector auxiliar las dimensiones del array junto con su identificador 
        // for (auto &auxi : *$2){
        //      aux.push_back("[" + auxi + "]");
        // }
        // //Convertimos en string para que no haya problemas a la hora de mostrar por pantalla.
        // std::copy(aux.rbegin(), aux.rend(),
        //   std::ostream_iterator<string>(oss));
        
        // //int n = st1.numArgsProcedimiento(identificador);
        // string str;
        
        // stringstream ss;  
        // ss << n;  
        // ss >> str;

        // //codigo.anadirInstruccion(str);
        // for (auto &auxi : *$2){
        //   $$->arr.push_back(auxi);
        // }
        // $$->arr.push_back(*$1);
        // $$->str = *$1 + oss.str();
        
        $$ = new expresionstruct;
        // Creamos un vector auxiliar del mismo tamaño que el vector de id de arrays
        int n = $5->size();
        std::vector<string> aux(n+1);
        std::ostringstream oss;
        //Guardamos en el vector auxiliar las dimensiones del array junto con su identificador 
        for (auto &auxi : *$5){
             aux.push_back("[" + auxi + "]");
        }
        aux.push_back("[" + *$3 + "]");
        
        //Convertimos en string para que no haya problemas a la hora de mostrar por pantalla.

        std::copy(aux.rbegin(), aux.rend(),
          std::ostream_iterator<string>(oss));
          
        //Insertamos en la lista de identificadores el identificador + dimensiones
        

        //codigo.anadirInstruccion($5->back());
        //añadimos tipo de cada dimension a la cola
        for (auto &auxi : *$5){
          $$->arr.push_back(auxi);
        }
        $$->arr.push_back(*$3);
        $$->arr.push_back(*$1);
        string str;
        
        stringstream ss;  
        ss << n;  
        ss >> str;

        //codigo.anadirInstruccion(str);

        $$->str = *$1 + oss.str();

      }
      | expresion TCOMMENT
      ;

M: %empty { $$ = codigo.obtenRef() ; }
  ;

%%
std::string tipoNum(const string& str)
{
  std::string::size_type sz;
  std::stoi (str,&sz);
  if (str.substr(sz) == ".") {
    return "float";
  }
  else{
    return "ent";
  }
}

expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3, std::vector<std::string> &s4) {
  expresionstruct tmp ; 
  int i,n,x;
  TablaSimbolos st2 = stPila.tope();
  
  codigo.anadirInstruccion(s4.back()) ;
  
  tmp.trues.push_back(codigo.obtenRef()) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;

  if (!st2.existeId(s4.back())){
    codigo.anadirInstruccion("El identificador no esta definido");
  }
  else {
    n = st2.numArgsProcedimiento(s4.back());
    for (i = 0; i < n; i++){
        std::pair <std::string,std::string> argumento; 
        if (argumento.second == tipoNum(s3))
          codigo.anadirInstruccion("Las variables no concuerdan en tipo");
    }
    s4.pop_back();
    x = s4.size();
    if (n != x){
      codigo.anadirInstruccion("No contiene las mismas dimensiones");
    }
  }
  
  tmp.falses.push_back(codigo.obtenRef()) ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}

expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 

  tmp.trues.push_back(codigo.obtenRef()) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;

  tmp.falses.push_back(codigo.obtenRef()) ;
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
