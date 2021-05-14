%error-verbose

%{
  /*TODO: 
    - Llamadas a procedimientos?
    - Arreglar arrays no deben tener un identificador dentro a la hora de declarar sino un int o float
      - Mantener estructura 
      - Modificar que como paramentros añada el integer a str
      - Necesario comprobar el valor maximo del array? -> 
        -> Se puede añadir como parametro 0 el valor maximo y simplemente es un if
    - Realizar ETDS :_(
  */
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
%token <str> RINTEGER RFLOAT RIF RELSE RDO RWHILE RNOT RAND RFOREVER RENDREPEAT RUNTIL RENDPROGRAM RPROGRAM RPROCEDURE RIN ROUT RREAD RPRINTLN REXIT ROR
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
%type <list> array_int
%type <list> array_id
%type <expr> expresion
%type <number> M
%type <numlist> lista_de_sentencias
%type <numlist> sentencia

%left ROR RAND RNOT
%left TEQUAL TNOTEQ TLESS TLESSEQ TGREATER TGREATEREQ 
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
                std::string estruct = $2->back();
                int w = $2->size(),k;
                //CODIGO PARA COMPROBAR LO QUE CONTIENE EL ARRAY Y SU DIMENSION
                /*string str;
                stringstream ss;  
                ss << w;  
                ss >> str;  
                for (int i = 0; i < w; i++){
                  codigo.anadirInstruccion($2->back());
                  $2->pop_back();
                }
                codigo.anadirInstruccion(str);*/
                /*En realidad en vez de añadir como variable cada procedimiento */

                if (estruct == "Array"){
                  // 5 posiciones de vector por cada array unidimensional + dimension del array
                  for ( k = 0; k < w; k = k + 5) {

                    //Quito "Array" del vector
                    $2->pop_back();
                    int num;
                    stringstream ss1;  
                    ss1 << $2->back();  
                    ss1 >> num;
                    int numdim = num;

                    //Quito el numero de dimensiones del vector
                    $2->pop_back();
 
                    //Creo procedimiento con el identificador
                    if (st.existeId($2->back())){
                      codigo.anadirInstruccion("La variable " + $2->back() + " ha sido definida previamente y no se puede volver a definir");
                    }
                    else{
                      st.anadirProcedimiento($2->back());
                      std::string identificador = $2->back();

                      //Quito el identificador del vector
                      $2->pop_back();
                      
                      //Guardamos parametros segun la dimension (dimension inicializada a 0 para mayor facilidad)
                      for (int i = 0; i < numdim + 1;i++){
                        st.anadirParametro(identificador,*$1,*$1);
                        $2->pop_back();
                      }
              
                      string str;
                      stringstream ss;  
                      ss << k + numdim;  
                      ss >> str;  

                      //Nuevo vector para distinguir los arrays declarados en una misma linea
                      std::vector<std::string> declarr;
                      declarr.push_back($2->back());
                      //Quito la declaracion del array del vector Ej: a[i]
                      $2->pop_back();

                      codigo.anadirDeclaraciones(declarr, *$1);
                    }
                    k = k + numdim;
                  }
                }
                else{
                  codigo.anadirDeclaraciones(*$2, *$1);
                  for (int i = 0; i < w;i++){
                    //codigo.anadirInstruccion($2->back());
                    st.anadirVariable($2->back(),*$1);
                    $2->pop_back();
                  }
                  //stPila.empilar(st);
                  //codigo.anadirDeclaraciones(*$2, *$1);
                }
                
              }
        declaraciones
      | TCOMMENT declaraciones
      | declaraciones TCOMMENT
      | %empty
      ;




lista_de_ident : TIDENTIFIER resto_lista_id
      {
        $$ = new vector<string>;
        $2->push_back(*$1);
        $$ = $2;
      }
      | TIDENTIFIER TLCOR TINTEGER TRCOR array_int resto_lista_id
      {
        
        $$ = new vector<string>;
        // Creamos un vector auxiliar del mismo tamaño que el vector de int de arrays
        int n = $5->size();
        // Variable para detectar la dimension del array
        int numdim = 0;
        std::vector<string> aux(n+1);
        std::ostringstream oss;
        // Guardamos en el vector auxiliar las dimensiones del array junto con su identificador 
        for (auto &auxi : *$5){
             aux.push_back("[" + auxi + "]");
             numdim++;
        }
        aux.push_back("[" + *$3 + "]");
        
        //Convertimos en string para que no haya problemas a la hora de mostrar la incializacion.

        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));

        //Insertamos en la lista de identificadores el identificador + dimensiones
        $6->push_back(*$1 + oss.str());

        // añadimos tamaño de cada dimension al vector Ej: 17,25...
        for (auto &auxi : *$5){
          $6->push_back(auxi);
        }
        // Añadimos el primer parametro?
        $6->push_back(*$3);
        // Añadimos el identificador
        $6->push_back(*$1);
        string str;
        stringstream ss;  
        ss << numdim;  
        ss >> str;
        // Añadimos la dimension del array y la palabra "Array" para diferencia de un int normal.
        $6->push_back(str);
        $6->push_back("Array");
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
      | TCOMMA TIDENTIFIER TLCOR TINTEGER TRCOR array_int resto_lista_id
      {
        $$ = new vector<string>;
        int n = $6->size();
        int numdim1 = 0;
        std::vector<string> aux(n+1);
        std::ostringstream oss;

        for (auto &auxi : *$6){
             aux.push_back("[" + auxi + "]");
             numdim1++;
        }

        aux.push_back("[" + *$4 + "]");
        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));
        $7->push_back(*$2 + oss.str());

        for (auto &auxi : *$6){
          $7->push_back(auxi);
        }

        $7->push_back(*$4);
        $7->push_back(*$2);
        string str;
        stringstream ss;  
        ss << numdim1;  
        ss >> str;
        $7->push_back(str);
        $7->push_back("Array");
        $$ = $7;
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

array_int : TLCOR TINTEGER TRCOR array_int
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
array_id : TLCOR variable TRCOR array_id
      {
        $$ = new vector<string>;
        $4->push_back(*$2);
        $$ = $4;
      }
      | TLCOR TINTEGER TRCOR array_int array_id
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
        if ($1->arr.empty())
          *$$ = makecomparison($1->str,*$2,$3->str) ; 
        else
          *$$ = makecomparison($1->str,*$2,$3->str,$1->arr) ; 
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
        if ($1->arr.empty())
          *$$ = makecomparison($1->str,*$2,$3->str) ; 
        else
          *$$ = makecomparison($1->str,*$2,$3->str,$1->arr) ; 
      }
      | expresion TGREATEREQ expresion
      { 
        $$ = new expresionstruct;
        if ($1->arr.empty())
          *$$ = makecomparison($1->str,*$2,$3->str) ; 
        else
          *$$ = makecomparison($1->str,*$2,$3->str,$1->arr) ; 
      }
      | expresion TLESSEQ expresion
      { 
        $$ = new expresionstruct;
        if ($1->arr.empty())
          *$$ = makecomparison($1->str,*$2,$3->str) ; 
        else
          *$$ = makecomparison($1->str,*$2,$3->str,$1->arr) ; 
      }
      | expresion TNOTEQ expresion
      { 
        $$ = new expresionstruct;
        if ($1->arr.empty())
          *$$ = makecomparison($1->str,*$2,$3->str) ; 
        else
          *$$ = makecomparison($1->str,*$2,$3->str,$1->arr) ; 
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
      | expresion RAND M expresion
      {
        $$ = new expresionstruct;
        expresionstruct tmp;
        codigo.completarInstrucciones($1->trues, $3);
        tmp.trues = $4->trues;
        tmp.falses = *(unir($1->falses, $4->falses));
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
      | TIDENTIFIER TLCOR TINTEGER TRCOR array_id
      { 
        $$ = new expresionstruct;
        int n = $5->size();
        std::vector<string> aux(n+1);
        std::ostringstream oss;

        for (auto &auxi : *$5){
             aux.push_back("[" + auxi + "]");
        }

        aux.push_back("[" + *$3 + "]");
        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));

        for (auto &auxi : *$5){
          $$->arr.push_back(auxi);
        }
        
        $$->arr.push_back(*$3);
        $$->arr.push_back(*$1);
        string str;
        stringstream ss;  
        ss << n;  
        ss >> str;

        $$->str = *$1 + oss.str();

      }
      | TIDENTIFIER TLCOR variable TRCOR array_id
      { 
        $$ = new expresionstruct;
        int n = $5->size();
        std::vector<string> aux(n+1);
        std::ostringstream oss;

        for (auto &auxi : *$5){
             aux.push_back("[" + auxi + "]");
        }

        aux.push_back("[" + *$3 + "]");
        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));
        
        for (auto &auxi : *$5){
          $$->arr.push_back(auxi);
        }
        
        $$->arr.push_back(*$3);
        $$->arr.push_back(*$1);
        string str;
        stringstream ss;  
        ss << n;  
        ss >> str;

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
  if (sz == str.length()) {
    return "ent";
  }
  else{
    return "real";
  }
}
bool es_numero(const std::string &s) {
  {
    for (char const &c : s) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
}

//Comparacion para arrays
expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3, std::vector<std::string> &s4) {
  expresionstruct tmp ; 
  int n,x,m;
  std::string identificador = s4.back();
  s4.pop_back();
  m = s4.size();
  //codigo.anadirInstruccion(s4.back()) ;
  
  tmp.trues.push_back(codigo.obtenRef()) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;

  if (!st.existeId(identificador)){
    codigo.anadirInstruccion("No esta definida la variable " + identificador);
  }
  else {
    x = s4.size();
    for (int i = 0; i < m;i++){
     //codigo.anadirInstruccion(s4.back());
      if (st.existeId(s4.back())){
          std::pair <std::string,std::string> argumento = st.obtenerTiposParametro(identificador,i);
          if (argumento.second != tipoNum(s3)){
            //codigo.anadirInstruccion(argumento.second + " " + tipoNum(s3));
            codigo.anadirInstruccion("Las variables no concuerdan en tipo");

          }
      }
      else{
          if (!es_numero(s4.back())){
            string str;

            stringstream ss;  
            ss << i;  
            ss >> str;  
            codigo.anadirInstruccion("La variable en el argumento " + str + " no esta definido");
          }
      }
      s4.pop_back();
    }
    n = st.numArgsProcedimiento(identificador);

    //s4.pop_back();
    
    if (n != x){
      codigo.anadirInstruccion("No contiene las mismas dimensiones");
    }
  }
  
  tmp.falses.push_back(codigo.obtenRef()) ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}

//Comparacion para variables comunes
expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 

  tmp.trues.push_back(codigo.obtenRef()) ;
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;
  if (!st.existeId(s1)){
    codigo.anadirInstruccion("No esta definida la variable " + s1);
  }
  else {
    if (es_numero(s3)){
        std::string tipodevar = st.obtenerTipo(s1);
        //codigo.anadirInstruccion(s3 + " 2");
        if (tipodevar != tipoNum(s3)){
           codigo.anadirInstruccion("Las variables no concuerdan en tipo");
        }
    }
  }
  tmp.falses.push_back(codigo.obtenRef()) ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}




expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 

  tmp.str = codigo.nuevoId() ;
  codigo.anadirInstruccion(tmp.str + ":=" + s1 + s2 + s3 + ";") ;
  /*Problemas:
    s1 puede ser una variable temporal
    s3 puede ser otra variable temporal
  Soluciones:
    Si s1 es temporal vamos a suponer que tiene el mismo tipo que s3
  Importante los dos no pueden ser a la vez temporales s1 y s3, si no existe s1 s3 tiene que existir
    */
 
  if(!st.existeId(s1)){
      //s1 se trata de una variable temporal o no esta declarado
    codigo.anadirInstruccion("No esta definida la variable " + s1);
  }
  else {
    //codigo.anadirInstruccion(s1) ;
    std::string tipodevar = st.obtenerTipo(s1);
    if (es_numero(s3)){
      
        //Si s1 o s3 no estan definidos no funcionara nada
        //codigo.anadirInstruccion("El identificador de arriba no esta definido");
        //s3 es una variable temporal
        if(tipodevar != tipoNum(s3)){
           codigo.anadirInstruccion("Las variables no concuerdan en tipo");
        }
    }
    else{
        if(st.existeId(s3)){
          std::string tipodevar2 = st.obtenerTipo(s3);
          if(tipodevar != tipodevar2){
             codigo.anadirInstruccion("Las variables no concuerdan en tipo: " + tipodevar + ", " + tipodevar2);
             //Aun sabiendo que no concuerdan en tipo s1 y s3 le damos a la variable temporal el tipo de s1
             st.anadirVariable(tmp.str,st.obtenerTipo(s1));
          }
          else{
             st.anadirVariable(tmp.str,st.obtenerTipo(s1));
          }
        }
        else{
          codigo.anadirInstruccion("No esta definida la variable " + s3);
        }
    }
  }
  return tmp ;
}

//Falta la función unir
vector<int> *unir(vector<int> lis1, vector<int> lis2){
  std::vector<int> *nuevalista = new vector<int>;
  nuevalista->insert(nuevalista->begin(), lis1.begin(), lis1.end());
  nuevalista->insert(nuevalista->end(), lis2.begin(), lis2.end());
  return nuevalista;
}
