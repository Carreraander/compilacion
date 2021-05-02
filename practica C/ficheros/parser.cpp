/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

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


#line 98 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    RFOREVER = 264,
    RENDREPEAT = 265,
    RUNTIL = 266,
    RENDPROGRAM = 267,
    RPROGRAM = 268,
    RPROCEDURE = 269,
    RIN = 270,
    ROUT = 271,
    RREAD = 272,
    RPRINTLN = 273,
    REXIT = 274,
    TMUL = 275,
    TDIV = 276,
    TPLUS = 277,
    TMINUS = 278,
    TASSIG = 279,
    TSEMIC = 280,
    TLBRACE = 281,
    TRBRACE = 282,
    TCOMMA = 283,
    TLPAREN = 284,
    TRPAREN = 285,
    TEQUAL = 286,
    TNOTEQ = 287,
    TLESS = 288,
    TLESSEQ = 289,
    TGREATER = 290,
    TGREATEREQ = 291,
    TVAL = 292,
    TREF = 293,
    TINTEGER = 294,
    TDOUBLE = 295,
    TIDENTIFIER = 296,
    TCOMMENT = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser.y"

    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
    int number ;
    numliststruct *numlist;

#line 201 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    83,    94,    93,    98,    99,   100,   103,
     109,   112,   118,   123,   126,   127,   128,   129,   132,   133,
     134,   135,   139,   138,   148,   149,   150,   151,   155,   154,
     159,   160,   163,   164,   165,   166,   170,   169,   174,   175,
     176,   179,   185,   189,   192,   198,   205,   215,   228,   235,
     241,   246,   252,   258,   260,   261,   264,   270,   276,   282,
     288,   294,   300,   306,   312,   318,   324,   326,   328,   330,
     332,   335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RINTEGER", "RFLOAT", "RIF", "RELSE",
  "RDO", "RWHILE", "RFOREVER", "RENDREPEAT", "RUNTIL", "RENDPROGRAM",
  "RPROGRAM", "RPROCEDURE", "RIN", "ROUT", "RREAD", "RPRINTLN", "REXIT",
  "TMUL", "TDIV", "TPLUS", "TMINUS", "TASSIG", "TSEMIC", "TLBRACE",
  "TRBRACE", "TCOMMA", "TLPAREN", "TRPAREN", "TEQUAL", "TNOTEQ", "TLESS",
  "TLESSEQ", "TGREATER", "TGREATEREQ", "TVAL", "TREF", "TINTEGER",
  "TDOUBLE", "TIDENTIFIER", "TCOMMENT", "$accept", "programa", "$@1",
  "declaraciones", "$@2", "lista_de_ident", "resto_lista_id", "tipo",
  "decl_de_subprogs", "decl_de_subprograma", "$@3", "argumentos",
  "lista_de_param", "$@4", "clase_par", "resto_lis_de_param", "$@5",
  "lista_de_sentencias", "sentencia", "variable", "expresion", "M", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -25,    21,  -127,  -127,     5,  -127,  -127,     5,     0,
      50,    29,    50,    40,     1,    38,     1,    73,  -127,   -18,
    -127,  -127,     1,    65,  -127,  -127,    65,    69,    78,  -127,
    -127,    60,    77,    73,  -127,     5,     8,    60,    23,    34,
     100,   119,   136,   118,   120,   131,  -127,  -127,    96,   115,
     -19,    78,    29,     8,   269,    94,   116,     5,     0,    34,
    -127,  -127,    96,   117,   249,  -127,   138,    34,    34,    34,
    -127,   117,  -127,    34,  -127,   269,   123,  -127,  -127,   271,
     113,  -127,  -127,  -127,    44,   180,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,  -127,   142,  -127,  -127,
     249,   197,   214,   232,   271,   133,  -127,   134,  -127,  -127,
     144,   144,    46,    46,   266,   266,   266,   266,   266,   266,
    -127,    98,  -127,   148,   162,   169,  -127,    -6,   104,   125,
     184,   164,  -127,  -127,  -127,    37,    -6,   154,  -127,  -127,
    -127,   170,    37,   269,   154,  -127,   173,    34,   179,   165,
     113,  -127,   157,  -127,   134,  -127,    -6,   182,   154,  -127,
     143,  -127,   196,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     8,    14,    15,     8,    19,
       0,     6,     0,     0,     7,     0,    19,    12,    17,     0,
       7,    22,    19,    20,    42,    21,    18,     0,     9,     4,
      10,    25,     0,    12,    13,     8,     0,    25,     8,     0,
       0,     0,     0,     0,     0,     0,     3,    53,    43,    41,
       0,    11,     5,     0,     0,     0,    26,     8,    19,     0,
      67,    68,     0,    66,    71,    71,     0,     0,     0,     0,
      49,    54,    52,     0,    55,     0,    30,    32,    33,     0,
       0,    24,    31,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,    42,    71,
      71,     0,     0,     0,     0,    34,    35,    28,    42,    69,
      64,    65,    62,    63,    56,    61,    58,    60,    57,    59,
      42,     0,    42,     0,     0,     0,    44,    40,     0,     0,
       0,    71,    48,    50,    51,     0,    40,    29,    23,    71,
      71,     0,     0,     0,    38,    39,     0,     0,     0,    16,
       0,    45,     0,    46,    36,    71,    40,     0,    37,    42,
       0,    71,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,    13,  -127,   -78,   176,    -8,     4,  -127,
    -127,   186,   171,  -127,   -75,  -126,  -127,   -76,  -127,   -31,
     -34,   -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    11,    35,    19,    28,    10,    23,    16,
      31,    38,    55,   127,    80,   137,   156,    32,    49,    63,
      64,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    50,   107,    98,   105,    73,     1,    29,     6,     7,
     144,     6,     7,    15,    13,    13,     3,    71,     9,   135,
      26,     4,   121,    74,    30,    85,     6,     7,    54,   105,
     158,    71,   128,   100,   101,   102,   136,   122,   123,   103,
       6,     7,    14,    22,   129,    75,   131,     8,    52,    12,
      53,    58,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    84,    59,    24,    57,    86,    87,   150,   141,
     108,    20,   154,    60,    61,    47,    62,   146,   147,   142,
      25,    21,    39,   160,    40,    41,    25,    42,    96,    36,
      50,    17,    18,   157,    43,    44,    45,    50,    50,   162,
      50,    27,    37,    39,    46,    40,    41,    25,    42,    39,
      33,    40,    41,   152,    42,    43,    44,    45,    47,    48,
      34,    43,    44,    45,    81,   130,    65,   143,    66,    50,
      39,   138,    40,    41,   149,    42,    82,    47,    62,    47,
      48,    67,    43,    44,    45,    47,    48,    68,    39,    69,
      40,    41,   139,    42,    17,   106,    70,    72,    83,    74,
      43,    44,    45,   155,    99,    82,    47,    48,   120,    39,
     161,    40,    41,   132,    42,   106,    30,    86,    87,    88,
      89,    43,    44,    45,    47,    48,    96,   133,    90,    91,
      92,    93,    94,    95,   134,   140,   145,   148,   151,    96,
      86,    87,    88,    89,   153,    47,    48,    18,   159,    51,
     109,    90,    91,    92,    93,    94,    95,    86,    87,    88,
      89,   163,    96,    56,    76,     0,     0,   124,    90,    91,
      92,    93,    94,    95,    86,    87,    88,    89,     0,    96,
       0,     0,     0,     0,   125,    90,    91,    92,    93,    94,
      95,     0,    86,    87,    88,    89,    96,   126,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    86,
      87,    88,    89,     0,    96,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    86,    87,    88,    89,
       0,    96,     0,     0,     0,     0,     0,    -1,    -1,    -1,
      -1,    -1,    -1,    77,     0,    77,     0,    78,    96,    78,
       0,    79,     0,   104
};

static const yytype_int16 yycheck[] =
{
       8,    32,    80,    65,    79,    24,    13,    25,     3,     4,
     136,     3,     4,     9,    14,    14,    41,    48,     5,    25,
      16,     0,    98,    42,    42,    59,     3,     4,    36,   104,
     156,    62,   108,    67,    68,    69,    42,    99,   100,    73,
       3,     4,    42,    42,   120,    53,   122,    42,    35,    57,
      42,    38,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    58,    29,    26,    42,    20,    21,   143,   131,
      26,    42,   150,    39,    40,    41,    42,   139,   140,    42,
      42,    41,     5,   159,     7,     8,    42,    10,    42,    29,
     121,    41,    42,   155,    17,    18,    19,   128,   129,   161,
     131,    28,    42,     5,    27,     7,     8,    42,    10,     5,
      41,     7,     8,   147,    10,    17,    18,    19,    41,    42,
      42,    17,    18,    19,    30,    27,    26,   135,     9,   160,
       5,    27,     7,     8,   142,    10,    42,    41,    42,    41,
      42,     5,    17,    18,    19,    41,    42,    29,     5,    29,
       7,     8,    27,    10,    41,    42,    25,    42,    42,    42,
      17,    18,    19,     6,    26,    42,    41,    42,    26,     5,
      27,     7,     8,    25,    10,    42,    42,    20,    21,    22,
      23,    17,    18,    19,    41,    42,    42,    25,    31,    32,
      33,    34,    35,    36,    25,    11,    42,    27,    25,    42,
      20,    21,    22,    23,    25,    41,    42,    42,    26,    33,
      30,    31,    32,    33,    34,    35,    36,    20,    21,    22,
      23,    25,    42,    37,    53,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    20,    21,    22,    23,    -1,    42,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    20,    21,    22,    23,    42,    25,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    20,
      21,    22,    23,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    20,    21,    22,    23,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    34,    -1,    34,    -1,    38,    42,    38,
      -1,    42,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    44,    41,     0,    45,     3,     4,    42,    46,
      50,    46,    50,    14,    42,    51,    52,    41,    42,    48,
      42,    41,    42,    51,    26,    42,    51,    28,    49,    25,
      42,    53,    60,    41,    42,    47,    29,    42,    54,     5,
       7,     8,    10,    17,    18,    19,    27,    41,    42,    61,
      62,    49,    46,    42,    50,    55,    54,    42,    46,    29,
      39,    40,    42,    62,    63,    26,     9,     5,    29,    29,
      25,    62,    42,    24,    42,    50,    55,    34,    38,    42,
      57,    30,    42,    42,    51,    63,    20,    21,    22,    23,
      31,    32,    33,    34,    35,    36,    42,    64,    64,    26,
      63,    63,    63,    63,    42,    57,    42,    48,    26,    30,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      26,    60,    64,    64,    30,    30,    25,    56,    60,    60,
      27,    60,    25,    25,    25,    25,    42,    58,    27,    27,
      11,    64,    42,    50,    58,    42,    64,    64,    27,    50,
      57,    25,    63,    25,    48,     6,    59,    64,    58,    26,
      60,    27,    64,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    47,    46,    46,    46,    46,    48,
      48,    49,    49,    49,    50,    50,    50,    50,    51,    51,
      51,    51,    53,    52,    54,    54,    54,    54,    56,    55,
      55,    55,    57,    57,    57,    57,    59,    58,    58,    58,
      58,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     5,     2,     2,     0,     2,
       2,     3,     0,     2,     1,     1,     2,     2,     2,     0,
       2,     2,     0,     9,     3,     0,     2,     2,     0,     5,
       2,     2,     1,     1,     2,     2,     0,     6,     2,     2,
       0,     2,     0,     2,     4,     8,     8,    15,     5,     2,
       5,     5,     2,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 84 "parser.y"
          {
            codigo.anadirInstruccion("prog " + *(yyvsp[0].str) + ";");
          }
#line 1517 "parser.cpp"
    break;

  case 3:
#line 88 "parser.y"
          {
            codigo.anadirInstruccion("halt;");
            codigo.escribir();
          }
#line 1526 "parser.cpp"
    break;

  case 4:
#line 94 "parser.y"
              {
                codigo.anadirDeclaraciones(*(yyvsp[-1].list), *(yyvsp[-2].str));
              }
#line 1534 "parser.cpp"
    break;

  case 9:
#line 104 "parser.y"
      {
      (yyval.list) = new vector<string>;
      (yyvsp[0].list)->push_back(*(yyvsp[-1].str));
      (yyval.list) = (yyvsp[0].list);
      }
#line 1544 "parser.cpp"
    break;

  case 11:
#line 113 "parser.y"
      {
      (yyval.list) = new vector<string>;
      (yyvsp[0].list)->push_back(*(yyvsp[-1].str));
      (yyval.list) = (yyvsp[0].list);
      }
#line 1554 "parser.cpp"
    break;

  case 12:
#line 119 "parser.y"
      {
      (yyval.list) = new vector<string>;
      *(yyval.list) = {};
      }
#line 1563 "parser.cpp"
    break;

  case 14:
#line 126 "parser.y"
                {*(yyval.str) = "ent";}
#line 1569 "parser.cpp"
    break;

  case 15:
#line 127 "parser.y"
               {*(yyval.str) = "real";}
#line 1575 "parser.cpp"
    break;

  case 22:
#line 139 "parser.y"
                    {
                      codigo.anadirInstruccion("proc " + *(yyvsp[0].str) + ";");
                    }
#line 1583 "parser.cpp"
    break;

  case 23:
#line 143 "parser.y"
                    {
                      codigo.anadirInstruccion("endproc;");
                    }
#line 1591 "parser.cpp"
    break;

  case 28:
#line 155 "parser.y"
                {
                  codigo.anadirParametros(*(yyvsp[0].list), *(yyvsp[-1].str), *(yyvsp[-2].str));
                }
#line 1599 "parser.cpp"
    break;

  case 32:
#line 163 "parser.y"
                    {(yyval.str) = (yyvsp[0].str);}
#line 1605 "parser.cpp"
    break;

  case 33:
#line 164 "parser.y"
                    {(yyval.str) = (yyvsp[0].str);}
#line 1611 "parser.cpp"
    break;

  case 36:
#line 170 "parser.y"
                    {
                      codigo.anadirParametros(*(yyvsp[0].list), *(yyvsp[-1].str), *(yyvsp[-2].str));
                    }
#line 1619 "parser.cpp"
    break;

  case 41:
#line 180 "parser.y"
                      {
                        (yyval.numlist) = new numliststruct;
                        (yyval.numlist)->exit = *(unir((yyvsp[0].numlist)->exit, (yyvsp[-1].numlist)->exit));
                        (yyval.numlist)->skip = *(unir((yyvsp[0].numlist)->skip, (yyvsp[-1].numlist)->skip));
                      }
#line 1629 "parser.cpp"
    break;

  case 42:
#line 186 "parser.y"
                      {
                        (yyval.numlist) = new numliststruct;
                      }
#line 1637 "parser.cpp"
    break;

  case 44:
#line 193 "parser.y"
      { 
        codigo.anadirInstruccion(*(yyvsp[-3].str) + " := " + (yyvsp[-1].expr)->str + ";") ; 
        delete (yyvsp[-3].str) ; delete (yyvsp[-1].expr);
        (yyval.numlist) = new numliststruct;
      }
#line 1647 "parser.cpp"
    break;

  case 45:
#line 199 "parser.y"
      { 
        codigo.completarInstrucciones((yyvsp[-6].expr)->trues, (yyvsp[-5].number));
        codigo.completarInstrucciones((yyvsp[-6].expr)->falses, (yyvsp[-1].number));
        //EXIT
        (yyval.numlist)->exit = (yyvsp[-3].numlist)->exit;
      }
#line 1658 "parser.cpp"
    break;

  case 46:
#line 206 "parser.y"
      {
        (yyval.numlist) = new numliststruct;
        stringstream cadena;
        cadena << " " << (yyvsp[-4].number);
        codigo.anadirInstruccion("goto" + cadena.str() + ";");
        //EXIT
        codigo.completarInstrucciones((yyvsp[-3].numlist)->exit, (yyvsp[-2].number));
        (yyval.numlist)->exit = (yyvsp[-3].numlist)->exit;
      }
#line 1672 "parser.cpp"
    break;

  case 47:
#line 217 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
        codigo.completarInstrucciones((yyvsp[-7].expr)->falses, (yyvsp[-12].number));
        codigo.completarInstrucciones((yyvsp[-7].expr)->trues, (yyvsp[-5].number));
        (yyval.numlist)->exit = *(unir((yyvsp[-11].numlist)->exit, (yyvsp[-3].numlist)->exit));
        //EXIT
        codigo.completarInstrucciones((yyvsp[-11].numlist)->exit, (yyvsp[-5].number));
        codigo.completarInstrucciones((yyvsp[-3].numlist)->exit, (yyvsp[-1].number));
        //FALTA EL SKIP
        codigo.completarInstrucciones((yyvsp[-11].numlist)->skip, (yyvsp[-8].number));
      }
#line 1688 "parser.cpp"
    break;

  case 48:
#line 229 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
        codigo.completarInstrucciones((yyvsp[-2].expr)->falses, (yyvsp[-1].number));
        (yyval.numlist)->skip = (yyvsp[-2].expr)->trues;
        delete (yyvsp[-2].expr);
      }
#line 1699 "parser.cpp"
    break;

  case 49:
#line 236 "parser.y"
      {
        (yyval.numlist) = new numliststruct;
        (yyval.numlist)->exit.push_back(codigo.obtenRef());
        codigo.anadirInstruccion("goto");
      }
#line 1709 "parser.cpp"
    break;

  case 50:
#line 242 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
        codigo.anadirInstruccion("read " + (yyvsp[-2].expr)->str + ";");
      }
#line 1718 "parser.cpp"
    break;

  case 51:
#line 247 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
        codigo.anadirInstruccion("write " + (yyvsp[-2].expr)->str + ";");
        codigo.anadirInstruccion("writeln;");
      }
#line 1728 "parser.cpp"
    break;

  case 52:
#line 253 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
      }
#line 1736 "parser.cpp"
    break;

  case 53:
#line 259 "parser.y"
          {(yyval.str) = (yyvsp[0].str);}
#line 1742 "parser.cpp"
    break;

  case 56:
#line 265 "parser.y"
      { 
      (yyval.expr) = new expresionstruct;
      *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
      delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
      }
#line 1752 "parser.cpp"
    break;

  case 57:
#line 271 "parser.y"
      { 
      (yyval.expr) = new expresionstruct;
      *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
      delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
      }
#line 1762 "parser.cpp"
    break;

  case 58:
#line 277 "parser.y"
      { 
      (yyval.expr) = new expresionstruct;
      *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
      delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
      }
#line 1772 "parser.cpp"
    break;

  case 59:
#line 283 "parser.y"
      { 
      (yyval.expr) = new expresionstruct;
      *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
      delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
      }
#line 1782 "parser.cpp"
    break;

  case 60:
#line 289 "parser.y"
      { 
      (yyval.expr) = new expresionstruct;
      *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
      delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
      }
#line 1792 "parser.cpp"
    break;

  case 61:
#line 295 "parser.y"
      { 
      (yyval.expr) = new expresionstruct;
      *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
      delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
      }
#line 1802 "parser.cpp"
    break;

  case 62:
#line 301 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr); 
      }
#line 1812 "parser.cpp"
    break;

  case 63:
#line 307 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr); 
      }
#line 1822 "parser.cpp"
    break;

  case 64:
#line 313 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr); 
      }
#line 1832 "parser.cpp"
    break;

  case 65:
#line 319 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr); 
      }
#line 1842 "parser.cpp"
    break;

  case 66:
#line 325 "parser.y"
      { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 1848 "parser.cpp"
    break;

  case 67:
#line 327 "parser.y"
      { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 1854 "parser.cpp"
    break;

  case 68:
#line 329 "parser.y"
      { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 1860 "parser.cpp"
    break;

  case 69:
#line 331 "parser.y"
      { (yyval.expr) = new expresionstruct; (yyval.expr)->str = (yyvsp[-1].expr)->str; }
#line 1866 "parser.cpp"
    break;

  case 71:
#line 335 "parser.y"
          { (yyval.number) = codigo.obtenRef() ; }
#line 1872 "parser.cpp"
    break;


#line 1876 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 338 "parser.y"


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
