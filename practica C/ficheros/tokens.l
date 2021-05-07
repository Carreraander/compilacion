%option yylineno
%option nounput

%{
 #include <string>
 #include <vector>
 #include <algorithm>
 using namespace std ;
 #include "Exp.hpp"
 #include "parser.hpp"

 #define TOKEN(t) yylval.str = new std::string(yytext, yyleng) ; return t 
 extern "C" int yywrap() { return(1) ; }  
%}

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

"["                     TOKEN(TLCOR);

"]"                     TOKEN(TRCOR);


"=="					TOKEN(TEQUAL);
"<"     				TOKEN(TLESS);
"<="     				TOKEN(TLESSEQ);
">"     				TOKEN(TGREATER);
">="                    TOKEN(TGREATEREQ);
"/="                    TOKEN(TNOTEQ);

"=>"					TOKEN(TREF);
"<=>"					TOKEN(TREF);

int						TOKEN(RINTEGER);
float					TOKEN(RFLOAT);
if 						TOKEN(RIF);
else					TOKEN(RELSE);
do 						TOKEN(RDO);
while                   TOKEN(RWHILE);
forever                 TOKEN(RFOREVER);
skip					TOKEN(RENDREPEAT);
until					TOKEN(RUNTIL);
exit					TOKEN(REXIT);
read                    TOKEN(RREAD);
println                 TOKEN(RPRINTLN);

"#"[^\n]*				TOKEN(TCOMMENT);{}									

[ \t\n]                 ;

\[\*(([^\*]\])*[^\]]*)*\*\]					TOKEN(TCOMMENT)  ; {}
[a-zA-Z]+(_[a-zA-Z0-9]|[a-zA-Z0-9])*    	TOKEN(TIDENTIFIER) ; 

[0-9]+\.[0-9]*((e|E)(\+|\-)?)?[0-9]+          TOKEN(TDOUBLE);
[0-9]+                  					TOKEN(TINTEGER); 

.                       printf("Token desconocido!\n"); yyterminate();
%%