
%{
 #include <string>
 #include <iostream>
 #include <vector>
 #include "traza.hpp" 
 using namespace std ;

 #define TOKEN(t) processtoken(t, string(yytext, yyleng))

 void processtoken (int t, string id) {
   cout << t << " <" << id << ">" << endl ;
 }

%}
%option nounput
%%
program                 TOKEN(RPROGRAM);
proc 					TOKEN(RPROCEDURE);

"+"						TOKEN(TPLUS);

"-"						TOKEN(TMINUS);

"*"                     TOKEN(TMUL);

"/"						TOKEN(TDIV);

"="                     TOKEN(TASSIG);

";"                     TOKEN(TSEMIC);

"{"                     TOKEN(TLBRACE);

"}"                     TOKEN(TRBRACE);

","						TOKEN(TCOMMA);

"("						TOKEN(TLPAREN);

")"						TOKEN(TRPAREN);


"=="					TOKEN(TEQUAL);
"<"     				TOKEN(TCLT);
"<="     				TOKEN(RIN);
">"     				TOKEN(TCGT);
"<=>"					TOKEN(ROUT);

int						TOKEN(RINTEGER);
float					TOKEN(RFLOAT);
if 						TOKEN(RIF);
else					TOKEN(RELSE);
do 						TOKEN(RDO);
skip					TOKEN(RENDREPEAT);
until					TOKEN(RUNTIL);
exit					TOKEN(RENDPROGRAM);


"#"[^\n]*				TOKEN(TCOMMENT);										

[ \t\n]                 ;

\[\*(([^\*]\])*[^\]]*)*\*\]					TOKEN(TCOMMENT) ;
[a-zA-Z]+(_[a-zA-Z0-9]|[a-zA-Z0-9])*    	TOKEN(TIDENTIFIER) ; 
[0-9]+\.[0-9]*((e|E)(\+|\-)?)?[0-9]+          TOKEN(TDOUBLE);
[0-9]+                  					TOKEN(TINTEGER); 

.                       { cout << "Token desconocido: " << yytext << endl; yyterminate();}
%%

int main() {
  yylex() ;
  cout << "Ha finalizado." << endl ; 
}
