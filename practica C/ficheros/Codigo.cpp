#include "Codigo.hpp"

using namespace std;


/****************/
/* Constructora */
/****************/

Codigo::Codigo() {
  siguienteIdentificador = 1;
}


/************************/
/* siguienteInstruccion */
/************************/

int Codigo::siguienteInstruccion() const {
  return instrucciones.size() + 1;
}


/***********/
/* nuevoId */
/***********/

string Codigo::nuevoId() {
  stringstream cadena;
  cadena << "_t" << siguienteIdentificador++;
  return cadena.str();
}


/*********************/
/* anadirInstruccion */
/*********************/

void Codigo::anadirInstruccion(const string &instruccion) {
  stringstream cadena;
  cadena << siguienteInstruccion() << ": " << instruccion;
  instrucciones.push_back(cadena.str());
}

/***********************/
/* anadirDeclaraciones */
/***********************/

void Codigo::anadirDeclaraciones(const vector<string> &idNombres, const string &tipoNombre) {
  vector<string>::const_reverse_iterator iter;
  for (iter=idNombres.rbegin(); iter!=idNombres.rend(); ++iter) {
    anadirInstruccion(tipoNombre + " " + *iter + ";");
  }
}

/*********************/
/* anadirParametros  */
/*********************/

void Codigo::anadirParametros(const vector<string> &idNombres, const string &pTipo, const string &tipoNombre) {  //, string procedimiento){
  string pTipoAux ;
  if      (pTipo == "<=") pTipoAux = "val" ;
  else if (pTipo == "=>") pTipoAux = "ref" ;
  else if (pTipo == "<=>") pTipoAux = "ref" ;
  vector<string>::const_iterator iter;
  for (iter=idNombres.begin(); iter!=idNombres.end(); iter++) {
    anadirInstruccion(pTipoAux + "_" + tipoNombre + " " + *iter + ";");
  }
}

/**************************/
/* completarInstrucciones */
/**************************/

void Codigo::completarInstrucciones(vector<int> &numerosInstrucciones, const int referencia) {
  stringstream cadena;
  vector<int>::iterator iter;
  cadena << " " << referencia;
  for (iter = numerosInstrucciones.begin(); iter != numerosInstrucciones.end(); iter++) {
    instrucciones[*iter-1].append(cadena.str() + ";");
  }
}


/************/
/* escribir */
/************/

void Codigo::escribir() const {
  //const string nombreFichero("output.txt");
  //fstream f(nombreFichero.c_str(), fstream::out);
  vector<string>::const_iterator iter;
  for (iter = instrucciones.begin(); iter != instrucciones.end(); iter++) {
    cout << *iter << endl;
    //f << *iter << endl;
  }
  //f.close();
}


/************/
/* obtenRef */
/************/

int Codigo::obtenRef() const {
  return siguienteInstruccion();
}


