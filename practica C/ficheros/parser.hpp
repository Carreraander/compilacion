/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RINTEGER = 258,
    RFLOAT = 259,
    RIF = 260,
    RELSE = 261,
    RDO = 262,
    RWHILE = 263,
    RNOT = 264,
    RAND = 265,
    RFOREVER = 266,
    RENDREPEAT = 267,
    RUNTIL = 268,
    RENDPROGRAM = 269,
    RPROGRAM = 270,
    RPROCEDURE = 271,
    RIN = 272,
    ROUT = 273,
    RREAD = 274,
    RPRINTLN = 275,
    REXIT = 276,
    ROR = 277,
    TMUL = 278,
    TDIV = 279,
    TPLUS = 280,
    TMINUS = 281,
    TASSIG = 282,
    TSEMIC = 283,
    TLBRACE = 284,
    TRBRACE = 285,
    TCOMMA = 286,
    TLPAREN = 287,
    TRPAREN = 288,
    TRCOR = 289,
    TLCOR = 290,
    TEQUAL = 291,
    TNOTEQ = 292,
    TLESS = 293,
    TLESSEQ = 294,
    TGREATER = 295,
    TGREATEREQ = 296,
    TVAL = 297,
    TREF = 298,
    TINTEGER = 299,
    TDOUBLE = 300,
    TIDENTIFIER = 301,
    TCOMMENT = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "parser.y"

    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
    int number ;
    numliststruct *numlist;

#line 113 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
