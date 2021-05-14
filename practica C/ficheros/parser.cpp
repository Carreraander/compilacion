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


#line 103 "parser.cpp"

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
#line 39 "parser.y"

    string *str ; 
    vector<string> *list ;
    expresionstruct *expr ;
    int number ;
    numliststruct *numlist;

#line 211 "parser.cpp"

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
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    92,   103,   102,   174,   175,   176,   182,
     188,   231,   237,   240,   246,   278,   284,   289,   292,   293,
     294,   295,   298,   304,   310,   316,   322,   330,   331,   332,
     333,   337,   336,   346,   347,   348,   349,   353,   352,   357,
     358,   361,   362,   363,   364,   368,   367,   372,   373,   374,
     377,   383,   387,   391,   397,   404,   414,   427,   434,   440,
     445,   451,   457,   459,   460,   464,   472,   480,   488,   496,
     504,   512,   521,   530,   538,   543,   548,   553,   558,   564,
     566,   568,   570,   599,   628,   631
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RINTEGER", "RFLOAT", "RIF", "RELSE",
  "RDO", "RWHILE", "RNOT", "RAND", "RFOREVER", "RENDREPEAT", "RUNTIL",
  "RENDPROGRAM", "RPROGRAM", "RPROCEDURE", "RIN", "ROUT", "RREAD",
  "RPRINTLN", "REXIT", "ROR", "TMUL", "TDIV", "TPLUS", "TMINUS", "TASSIG",
  "TSEMIC", "TLBRACE", "TRBRACE", "TCOMMA", "TLPAREN", "TRPAREN", "TRCOR",
  "TLCOR", "TEQUAL", "TNOTEQ", "TLESS", "TLESSEQ", "TGREATER",
  "TGREATEREQ", "TVAL", "TREF", "TINTEGER", "TDOUBLE", "TIDENTIFIER",
  "TCOMMENT", "$accept", "programa", "$@1", "declaraciones", "$@2",
  "lista_de_ident", "resto_lista_id", "tipo", "array_int", "array_id",
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF (-152)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   -35,    47,  -152,  -152,    10,  -152,  -152,    10,    45,
      97,    38,    97,    22,    46,    70,    46,    96,  -152,    63,
    -152,  -152,    46,    62,  -152,  -152,    62,    65,    80,    90,
    -152,  -152,    69,   128,    99,   114,   118,  -152,    10,    12,
      69,    16,    42,   127,   154,   161,   136,   139,   144,  -152,
    -152,   104,   126,     6,    85,    90,    90,   142,    38,    12,
     120,   -24,   140,    10,    45,    42,    42,  -152,  -152,   151,
     104,   141,   299,  -152,   164,    42,   104,    42,  -152,   141,
    -152,    42,  -152,   114,   160,   166,   114,   120,   153,  -152,
    -152,   156,   115,  -152,  -152,  -152,    71,   318,   239,   158,
    -152,  -152,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,  -152,   182,  -152,  -152,   299,    75,   259,   279,
      90,   142,   200,    90,   156,   169,  -152,   188,  -152,  -152,
     202,    68,    42,    42,   190,   190,    49,    49,     2,     2,
       2,     2,     2,     2,  -152,   134,  -152,   210,   211,   212,
    -152,   114,   142,    66,   171,   215,   215,   318,   318,   177,
     233,   207,  -152,  -152,  -152,    90,  -152,    18,    66,   204,
    -152,   186,  -152,  -152,  -152,  -152,   222,    18,   120,   204,
    -152,   234,    73,   242,    42,   243,   220,   115,   142,   215,
    -152,   219,  -152,   188,   215,  -152,  -152,    66,  -152,   244,
     204,  -152,   201,  -152,   246,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     8,    18,    19,     8,    28,
       0,     6,     0,     0,     7,     0,    28,    16,    21,     0,
       7,    31,    28,    29,    51,    30,    27,     0,     0,     9,
       4,    12,    34,     0,    16,    16,     0,    17,     8,     0,
      34,     8,     0,     0,     0,     0,     0,     0,     0,     3,
      62,    52,    50,     0,     0,    13,    11,    23,     5,     0,
       0,     0,    35,     8,    28,     0,     0,    79,    80,    62,
       0,    78,    85,    85,     0,     0,     0,     0,    58,    63,
      61,     0,    64,    16,     0,     0,    16,     0,    39,    41,
      42,     0,     0,    33,    40,    36,     0,    73,     0,     0,
      85,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,    51,    85,    85,     0,     0,     0,
      15,    23,     0,    10,     0,    43,    44,    37,    51,    81,
       0,     0,     0,     0,    76,    77,    74,    75,    65,    70,
      67,    69,    66,    68,    51,     0,    51,     0,     0,     0,
      53,    16,    23,    49,     0,    26,    26,    72,    71,     0,
       0,    85,    57,    59,    60,    14,    22,     0,    49,    38,
      32,     0,    82,    83,    85,    85,     0,     0,     0,    47,
      48,     0,     0,     0,     0,     0,    20,     0,    23,    26,
      54,     0,    55,    45,    26,    24,    85,    49,    25,     0,
      46,    51,     0,    85,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,    29,  -152,   -89,   -28,    -7,  -117,  -125,
      -4,  -152,  -152,   247,   229,  -152,   -83,  -151,  -152,  -104,
    -152,   -33,   -27,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    11,    38,    19,    29,    10,    86,   172,
      23,    16,    32,    41,    61,   153,    92,   169,   197,    33,
      52,    71,    72,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,    12,   114,   127,   151,    15,    55,    56,   125,    93,
     145,     3,    26,     6,     7,     6,     7,   179,    79,     6,
       7,     6,     7,    94,   154,   102,   103,   104,   105,   132,
     133,   173,    60,    81,     9,   166,     1,    79,    97,    98,
     159,   125,   161,   117,   146,   147,   200,     4,   116,   112,
     118,    65,    87,    82,   119,   120,    12,     8,   123,    59,
      96,    13,    13,    63,   195,   177,   131,    58,    21,   198,
      64,   194,   102,   103,    66,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    20,    67,    68,    69,    70,
     176,    30,    14,    22,   167,   187,   112,   202,   193,    24,
     128,    39,   156,   183,   184,   157,   158,   189,   148,    25,
      31,    34,    53,   168,    35,    82,    40,    25,    25,    83,
      82,    53,    82,   165,    36,   199,    53,    27,    53,    84,
      27,    28,   204,    42,    54,    43,    44,    37,   182,    42,
      45,    43,    44,    17,    18,    27,    45,    46,    47,    48,
      50,    70,    57,    46,    47,    48,    73,   191,    49,    89,
     178,    17,   126,    90,   160,    74,    75,    91,    76,    53,
     186,    77,    78,    80,    50,    51,    42,    85,    43,    44,
      50,    51,    42,    45,    43,    44,    99,    95,    82,    45,
      46,    47,    48,   115,   121,    89,    46,    47,    48,    90,
      94,   170,   130,   124,    50,    70,    42,   174,    43,    44,
     122,   144,    42,    45,    43,    44,   126,    50,    51,    45,
      46,    47,    48,    50,    51,   196,    46,    47,    48,   100,
     181,   203,    50,    70,   152,    31,   155,   112,   162,   163,
     164,   101,   102,   103,   104,   105,   175,    50,    51,   100,
     171,   180,   185,    50,    51,   106,   107,   108,   109,   110,
     111,   101,   102,   103,   104,   105,   112,    18,   188,   100,
     190,   192,   129,   201,   205,   106,   107,   108,   109,   110,
     111,   101,   102,   103,   104,   105,   112,    62,    88,   100,
       0,     0,   149,     0,     0,   106,   107,   108,   109,   110,
     111,   101,   102,   103,   104,   105,   112,   150,     0,   100,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   101,   102,   103,   104,   105,   112,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   102,   103,   104,   105,     0,   112,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,   112
};

static const yytype_int16 yycheck[] =
{
      33,     8,    73,    92,   121,     9,    34,    35,    91,    33,
     114,    46,    16,     3,     4,     3,     4,   168,    51,     3,
       4,     3,     4,    47,   128,    23,    24,    25,    26,   100,
     101,   156,    39,    27,     5,   152,    15,    70,    65,    66,
     144,   124,   146,    76,   115,   116,   197,     0,    75,    47,
      77,     9,    59,    47,    81,    83,    63,    47,    86,    47,
      64,    16,    16,    47,   189,    47,    99,    38,    46,   194,
      41,   188,    23,    24,    32,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    47,    44,    45,    46,    47,
     161,    28,    47,    47,    28,   178,    47,   201,   187,    29,
      29,    32,    34,   174,   175,   132,   133,    34,    33,    47,
      47,    46,   145,    47,    34,    47,    47,    47,    47,    34,
      47,   154,    47,   151,    44,   196,   159,    31,   161,    44,
      31,    35,   203,     5,    35,     7,     8,    47,   171,     5,
      12,     7,     8,    46,    47,    31,    12,    19,    20,    21,
      46,    47,    34,    19,    20,    21,    29,   184,    30,    39,
     167,    46,    47,    43,    30,    11,     5,    47,    32,   202,
     177,    32,    28,    47,    46,    47,     5,    35,     7,     8,
      46,    47,     5,    12,     7,     8,    35,    47,    47,    12,
      19,    20,    21,    29,    34,    39,    19,    20,    21,    43,
      47,    30,    44,    47,    46,    47,     5,    30,     7,     8,
      44,    29,     5,    12,     7,     8,    47,    46,    47,    12,
      19,    20,    21,    46,    47,     6,    19,    20,    21,    10,
      44,    30,    46,    47,    34,    47,    34,    47,    28,    28,
      28,    22,    23,    24,    25,    26,    13,    46,    47,    10,
      35,    47,    30,    46,    47,    36,    37,    38,    39,    40,
      41,    22,    23,    24,    25,    26,    47,    47,    34,    10,
      28,    28,    33,    29,    28,    36,    37,    38,    39,    40,
      41,    22,    23,    24,    25,    26,    47,    40,    59,    10,
      -1,    -1,    33,    -1,    -1,    36,    37,    38,    39,    40,
      41,    22,    23,    24,    25,    26,    47,    28,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    22,    23,    24,    25,    26,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    23,    24,    25,    26,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    49,    46,     0,    50,     3,     4,    47,    51,
      55,    51,    55,    16,    47,    58,    59,    46,    47,    53,
      47,    46,    47,    58,    29,    47,    58,    31,    35,    54,
      28,    47,    60,    67,    46,    34,    44,    47,    52,    32,
      47,    61,     5,     7,     8,    12,    19,    20,    21,    30,
      46,    47,    68,    69,    35,    54,    54,    34,    51,    47,
      55,    62,    61,    47,    51,     9,    32,    44,    45,    46,
      47,    69,    70,    29,    11,     5,    32,    32,    28,    69,
      47,    27,    47,    34,    44,    35,    56,    55,    62,    39,
      43,    47,    64,    33,    47,    47,    58,    70,    70,    35,
      10,    22,    23,    24,    25,    26,    36,    37,    38,    39,
      40,    41,    47,    71,    71,    29,    70,    69,    70,    70,
      54,    34,    44,    54,    47,    64,    47,    53,    29,    33,
      44,    69,    71,    71,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    29,    67,    71,    71,    33,    33,
      28,    56,    34,    63,    67,    34,    34,    70,    70,    67,
      30,    67,    28,    28,    28,    54,    56,    28,    47,    65,
      30,    35,    57,    57,    30,    13,    71,    47,    55,    65,
      47,    44,    69,    71,    71,    30,    55,    64,    34,    34,
      28,    70,    28,    53,    56,    57,     6,    66,    57,    71,
      65,    29,    67,    30,    71,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    49,    52,    51,    51,    51,    51,    53,
      53,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    56,    56,    57,    57,    57,    58,    58,    58,
      58,    60,    59,    61,    61,    61,    61,    63,    62,    62,
      62,    64,    64,    64,    64,    66,    65,    65,    65,    65,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     5,     2,     2,     0,     2,
       6,     4,     2,     3,     7,     5,     0,     2,     1,     1,
       2,     2,     4,     0,     4,     5,     0,     2,     0,     2,
       2,     0,     9,     3,     0,     2,     2,     0,     5,     2,
       2,     1,     1,     2,     2,     0,     6,     2,     2,     0,
       2,     0,     2,     4,     8,     8,    15,     5,     2,     5,
       5,     2,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     4,     4,     2,     3,     3,     3,     3,     1,     1,
       1,     3,     5,     5,     2,     0
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
#line 93 "parser.y"
          {
            codigo.anadirInstruccion("prog " + *(yyvsp[0].str) + ";");
          }
#line 1554 "parser.cpp"
    break;

  case 3:
#line 97 "parser.y"
          {
            codigo.anadirInstruccion("halt;");
            codigo.escribir();
          }
#line 1563 "parser.cpp"
    break;

  case 4:
#line 103 "parser.y"
              {
                std::string estruct = (yyvsp[-1].list)->back();
                int w = (yyvsp[-1].list)->size(),k;
                //CODIGO PARA COMPROBAR LO QUE CONTIENE EL ARRAY Y SU DIMENSION
                /*string str;
                stringstream ss;  
                ss << w;  
                ss >> str;  
                for (int i = 0; i < w; i++){
                  codigo.anadirInstruccion($2->back());
                  $2->pop_back();
                }
                codigo.anadirInstruccion(str);
                */

                if (estruct == "Array"){
                  // 5 posiciones de vector por cada array unidimensional + dimension del array
                  for ( k = 0; k < w; k = k + 5) {

                    //Quito "Array" del vector
                    (yyvsp[-1].list)->pop_back();
                    int num;
                    stringstream ss1;  
                    ss1 << (yyvsp[-1].list)->back();  
                    ss1 >> num;
                    int numdim = num;

                    //Quito el numero de dimensiones del vector
                    (yyvsp[-1].list)->pop_back();
 
                    //Creo procedimiento con el identificador
                    if (st.existeId((yyvsp[-1].list)->back())){
                      codigo.anadirInstruccion("La variable " + (yyvsp[-1].list)->back() + " ha sido definida previamente y no se puede volver a definir");
                    }
                    else{
                      st.anadirProcedimiento((yyvsp[-1].list)->back());
                      std::string identificador = (yyvsp[-1].list)->back();

                      //Quito el identificador del vector
                      (yyvsp[-1].list)->pop_back();
                      
                      //Guardamos parametros segun la dimension (dimension inicializada a 0 para mayor facilidad)
                      for (int i = 0; i < numdim + 1;i++){
                        st.anadirParametro(identificador,*(yyvsp[-2].str),*(yyvsp[-2].str));
                        (yyvsp[-1].list)->pop_back();
                      }

                      //Nuevo vector para distinguir los arrays declarados en una misma linea
                      std::vector<std::string> declarr;
                      declarr.push_back((yyvsp[-1].list)->back());
                      //Quito la declaracion del array del vector Ej: a[i]
                      (yyvsp[-1].list)->pop_back();

                      codigo.anadirDeclaraciones(declarr, *(yyvsp[-2].str));
                    }
                    k = k + numdim;
                  }
                }
                else{
                  codigo.anadirDeclaraciones(*(yyvsp[-1].list), *(yyvsp[-2].str));
                  for (int i = 0; i < w;i++){
                    //codigo.anadirInstruccion($2->back());
                    st.anadirVariable((yyvsp[-1].list)->back(),*(yyvsp[-2].str));
                    (yyvsp[-1].list)->pop_back();
                  }
                  //stPila.empilar(st);
                  //codigo.anadirDeclaraciones(*$2, *$1);
                }
                
              }
#line 1638 "parser.cpp"
    break;

  case 9:
#line 183 "parser.y"
      {
        (yyval.list) = new vector<string>;
        (yyvsp[0].list)->push_back(*(yyvsp[-1].str));
        (yyval.list) = (yyvsp[0].list);
      }
#line 1648 "parser.cpp"
    break;

  case 10:
#line 189 "parser.y"
      {
        
        (yyval.list) = new vector<string>;
        // Creamos un vector auxiliar del mismo tamaño que el vector de int de arrays
        int n = (yyvsp[-1].list)->size();
        // Variable para detectar la dimension del array
        int numdim = 0;
        std::vector<string> aux(n+1);
        std::ostringstream oss;
        // Guardamos en el vector auxiliar las dimensiones del array junto con su identificador 
        for (auto &auxi : *(yyvsp[-1].list)){
             aux.push_back("[" + auxi + "]");
             numdim++;
        }
        aux.push_back("[" + *(yyvsp[-3].str) + "]");
        
        //Convertimos en string para que no haya problemas a la hora de mostrar la incializacion.

        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));

        //Insertamos en la lista de identificadores el identificador + dimensiones
        (yyvsp[0].list)->push_back(*(yyvsp[-5].str) + oss.str());

        // añadimos tamaño de cada dimension al vector Ej: 17,25...
        for (auto &auxi : *(yyvsp[-1].list)){
          (yyvsp[0].list)->push_back(auxi);
        }
        // Añadimos el primer parametro?
        (yyvsp[0].list)->push_back(*(yyvsp[-3].str));
        // Añadimos el identificador
        (yyvsp[0].list)->push_back(*(yyvsp[-5].str));
        string str;
        stringstream ss;  
        ss << numdim;  
        ss >> str;
        // Añadimos la dimension del array y la palabra "Array" para diferencia de un int normal.
        (yyvsp[0].list)->push_back(str);
        (yyvsp[0].list)->push_back("Array");
        (yyval.list) = (yyvsp[0].list);

      }
#line 1695 "parser.cpp"
    break;

  case 11:
#line 232 "parser.y"
      {
        (yyval.list) = new vector<string>;
        (yyvsp[0].list)->push_back(*(yyvsp[-3].str) + *(yyvsp[-2].str) + *(yyvsp[-1].str));
        (yyval.list) = (yyvsp[0].list);
      }
#line 1705 "parser.cpp"
    break;

  case 13:
#line 241 "parser.y"
      {
      (yyval.list) = new vector<string>;
      (yyvsp[0].list)->push_back(*(yyvsp[-1].str));
      (yyval.list) = (yyvsp[0].list);
      }
#line 1715 "parser.cpp"
    break;

  case 14:
#line 247 "parser.y"
      {
        (yyval.list) = new vector<string>;
        int n = (yyvsp[-1].list)->size();
        int numdim1 = 0;
        std::vector<string> aux(n+1);
        std::ostringstream oss;

        for (auto &auxi : *(yyvsp[-1].list)){
             aux.push_back("[" + auxi + "]");
             numdim1++;
        }

        aux.push_back("[" + *(yyvsp[-3].str) + "]");
        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));
        (yyvsp[0].list)->push_back(*(yyvsp[-5].str) + oss.str());

        for (auto &auxi : *(yyvsp[-1].list)){
          (yyvsp[0].list)->push_back(auxi);
        }

        (yyvsp[0].list)->push_back(*(yyvsp[-3].str));
        (yyvsp[0].list)->push_back(*(yyvsp[-5].str));
        string str;
        stringstream ss;  
        ss << numdim1;  
        ss >> str;
        (yyvsp[0].list)->push_back(str);
        (yyvsp[0].list)->push_back("Array");
        (yyval.list) = (yyvsp[0].list);
      }
#line 1751 "parser.cpp"
    break;

  case 15:
#line 279 "parser.y"
      {
      (yyval.list) = new vector<string>;
      (yyvsp[0].list)->push_back(*(yyvsp[-4].str) + *(yyvsp[-2].str) + *(yyvsp[-1].str));
      (yyval.list) = (yyvsp[0].list);
      }
#line 1761 "parser.cpp"
    break;

  case 16:
#line 285 "parser.y"
      {
      (yyval.list) = new vector<string>;
      *(yyval.list) = {};
      }
#line 1770 "parser.cpp"
    break;

  case 18:
#line 292 "parser.y"
                {*(yyval.str) = "ent";}
#line 1776 "parser.cpp"
    break;

  case 19:
#line 293 "parser.y"
               {*(yyval.str) = "real";}
#line 1782 "parser.cpp"
    break;

  case 22:
#line 299 "parser.y"
      {
        (yyval.list) = new vector<string>;
        (yyvsp[0].list)->push_back(*(yyvsp[-2].str));
        (yyval.list) = (yyvsp[0].list);
      }
#line 1792 "parser.cpp"
    break;

  case 23:
#line 305 "parser.y"
      {
        (yyval.list) = new vector<string>;
        *(yyval.list) = {};
      }
#line 1801 "parser.cpp"
    break;

  case 24:
#line 311 "parser.y"
      {
        (yyval.list) = new vector<string>;
        (yyvsp[0].list)->push_back(*(yyvsp[-2].str));
        (yyval.list) = (yyvsp[0].list);
      }
#line 1811 "parser.cpp"
    break;

  case 25:
#line 317 "parser.y"
      {
        (yyval.list) = new vector<string>;
        (yyvsp[-1].list)->push_back(*(yyvsp[-3].str));
        (yyval.list) = (yyvsp[-1].list);
      }
#line 1821 "parser.cpp"
    break;

  case 26:
#line 323 "parser.y"
      {
        (yyval.list) = new vector<string>;
        *(yyval.list) = {};
      }
#line 1830 "parser.cpp"
    break;

  case 31:
#line 337 "parser.y"
                    {
                      codigo.anadirInstruccion("proc " + *(yyvsp[0].str) + ";");
                    }
#line 1838 "parser.cpp"
    break;

  case 32:
#line 341 "parser.y"
                    {
                      codigo.anadirInstruccion("endproc;");
                    }
#line 1846 "parser.cpp"
    break;

  case 37:
#line 353 "parser.y"
                {
                  codigo.anadirParametros(*(yyvsp[0].list), *(yyvsp[-1].str), *(yyvsp[-2].str));
                }
#line 1854 "parser.cpp"
    break;

  case 41:
#line 361 "parser.y"
                    {(yyval.str) = (yyvsp[0].str);}
#line 1860 "parser.cpp"
    break;

  case 42:
#line 362 "parser.y"
                    {(yyval.str) = (yyvsp[0].str);}
#line 1866 "parser.cpp"
    break;

  case 45:
#line 368 "parser.y"
                    {
                      codigo.anadirParametros(*(yyvsp[0].list), *(yyvsp[-1].str), *(yyvsp[-2].str));
                    }
#line 1874 "parser.cpp"
    break;

  case 50:
#line 378 "parser.y"
                      {
                        (yyval.numlist) = new numliststruct;
                        (yyval.numlist)->exit = *(unir((yyvsp[0].numlist)->exit, (yyvsp[-1].numlist)->exit));
                        (yyval.numlist)->skip = *(unir((yyvsp[0].numlist)->skip, (yyvsp[-1].numlist)->skip));
                      }
#line 1884 "parser.cpp"
    break;

  case 51:
#line 384 "parser.y"
                      {
                        (yyval.numlist) = new numliststruct;
                      }
#line 1892 "parser.cpp"
    break;

  case 53:
#line 392 "parser.y"
      { 
        codigo.anadirInstruccion(*(yyvsp[-3].str) + " := " + (yyvsp[-1].expr)->str + ";") ; 
        delete (yyvsp[-3].str) ; delete (yyvsp[-1].expr);
        (yyval.numlist) = new numliststruct;
      }
#line 1902 "parser.cpp"
    break;

  case 54:
#line 398 "parser.y"
      { 
        codigo.completarInstrucciones((yyvsp[-6].expr)->trues, (yyvsp[-5].number));
        codigo.completarInstrucciones((yyvsp[-6].expr)->falses, (yyvsp[-1].number));
        //EXIT
        (yyval.numlist)->exit = (yyvsp[-3].numlist)->exit;
      }
#line 1913 "parser.cpp"
    break;

  case 55:
#line 405 "parser.y"
      {
        (yyval.numlist) = new numliststruct;
        stringstream cadena;
        cadena << " " << (yyvsp[-4].number);
        codigo.anadirInstruccion("goto" + cadena.str() + ";");
        //EXIT
        codigo.completarInstrucciones((yyvsp[-3].numlist)->exit, (yyvsp[-2].number));
        (yyval.numlist)->exit = (yyvsp[-3].numlist)->exit;
      }
#line 1927 "parser.cpp"
    break;

  case 56:
#line 416 "parser.y"
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
#line 1943 "parser.cpp"
    break;

  case 57:
#line 428 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
        codigo.completarInstrucciones((yyvsp[-2].expr)->falses, (yyvsp[-1].number));
        (yyval.numlist)->skip = (yyvsp[-2].expr)->trues;
        delete (yyvsp[-2].expr);
      }
#line 1954 "parser.cpp"
    break;

  case 58:
#line 435 "parser.y"
      {
        (yyval.numlist) = new numliststruct;
        (yyval.numlist)->exit.push_back(codigo.obtenRef());
        codigo.anadirInstruccion("goto");
      }
#line 1964 "parser.cpp"
    break;

  case 59:
#line 441 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
        codigo.anadirInstruccion("read " + *(yyvsp[-2].str) + ";");
      }
#line 1973 "parser.cpp"
    break;

  case 60:
#line 446 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
        codigo.anadirInstruccion("write " + (yyvsp[-2].expr)->str + ";");
        codigo.anadirInstruccion("writeln;");
      }
#line 1983 "parser.cpp"
    break;

  case 61:
#line 452 "parser.y"
      { 
        (yyval.numlist) = new numliststruct;
      }
#line 1991 "parser.cpp"
    break;

  case 62:
#line 458 "parser.y"
          {(yyval.str) = (yyvsp[0].str);}
#line 1997 "parser.cpp"
    break;

  case 65:
#line 465 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        if ((yyvsp[-2].expr)->arr.empty())
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
        else
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str,(yyvsp[-2].expr)->arr) ; 
      }
#line 2009 "parser.cpp"
    break;

  case 66:
#line 473 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        if ((yyvsp[-2].expr)->arr.empty())
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
        else
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str,(yyvsp[-2].expr)->arr) ; 
      }
#line 2021 "parser.cpp"
    break;

  case 67:
#line 481 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        if ((yyvsp[-2].expr)->arr.empty())
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
        else
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str,(yyvsp[-2].expr)->arr) ; 
      }
#line 2033 "parser.cpp"
    break;

  case 68:
#line 489 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        if ((yyvsp[-2].expr)->arr.empty())
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
        else
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str,(yyvsp[-2].expr)->arr) ; 
      }
#line 2045 "parser.cpp"
    break;

  case 69:
#line 497 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        if ((yyvsp[-2].expr)->arr.empty())
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
        else
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str,(yyvsp[-2].expr)->arr) ; 
      }
#line 2057 "parser.cpp"
    break;

  case 70:
#line 505 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        if ((yyvsp[-2].expr)->arr.empty())
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
        else
          *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str,(yyvsp[-2].expr)->arr) ; 
      }
#line 2069 "parser.cpp"
    break;

  case 71:
#line 513 "parser.y"
      {
        (yyval.expr) = new expresionstruct;
        expresionstruct tmp;
        codigo.completarInstrucciones((yyvsp[-3].expr)->falses, (yyvsp[-1].number));
        tmp.trues = *(unir((yyvsp[-3].expr)->trues, (yyvsp[0].expr)->trues));
        tmp.falses = (yyvsp[0].expr)->falses;
        *(yyval.expr) = tmp;
      }
#line 2082 "parser.cpp"
    break;

  case 72:
#line 522 "parser.y"
      {
        (yyval.expr) = new expresionstruct;
        expresionstruct tmp;
        codigo.completarInstrucciones((yyvsp[-3].expr)->trues, (yyvsp[-1].number));
        tmp.trues = (yyvsp[0].expr)->trues;
        tmp.falses = *(unir((yyvsp[-3].expr)->falses, (yyvsp[0].expr)->falses));
        *(yyval.expr) = tmp;
      }
#line 2095 "parser.cpp"
    break;

  case 73:
#line 531 "parser.y"
      {
        (yyval.expr) = new expresionstruct;
        expresionstruct tmp;
        tmp.trues = (yyvsp[0].expr)->falses;
        tmp.falses = (yyvsp[0].expr)->trues;
        *(yyval.expr) = tmp;
      }
#line 2107 "parser.cpp"
    break;

  case 74:
#line 539 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
      }
#line 2116 "parser.cpp"
    break;

  case 75:
#line 544 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
      }
#line 2125 "parser.cpp"
    break;

  case 76:
#line 549 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ; 
      }
#line 2134 "parser.cpp"
    break;

  case 77:
#line 554 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str) ;
      }
#line 2143 "parser.cpp"
    break;

  case 78:
#line 559 "parser.y"
      { 
        (yyval.expr) = new expresionstruct; 

        (yyval.expr)->str = *(yyvsp[0].str);
      }
#line 2153 "parser.cpp"
    break;

  case 79:
#line 565 "parser.y"
      { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 2159 "parser.cpp"
    break;

  case 80:
#line 567 "parser.y"
      { (yyval.expr) = new expresionstruct; (yyval.expr)->str = *(yyvsp[0].str); }
#line 2165 "parser.cpp"
    break;

  case 81:
#line 569 "parser.y"
      { (yyval.expr) = new expresionstruct; (yyval.expr)->str = (yyvsp[-1].expr)->str; }
#line 2171 "parser.cpp"
    break;

  case 82:
#line 571 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        int n = (yyvsp[0].list)->size();
        std::vector<string> aux(n+1);
        std::ostringstream oss;

        for (auto &auxi : *(yyvsp[0].list)){
             aux.push_back("[" + auxi + "]");
        }

        aux.push_back("[" + *(yyvsp[-2].str) + "]");
        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));

        for (auto &auxi : *(yyvsp[0].list)){
          (yyval.expr)->arr.push_back(auxi);
        }
        
        (yyval.expr)->arr.push_back(*(yyvsp[-2].str));
        (yyval.expr)->arr.push_back(*(yyvsp[-4].str));
        string str;
        stringstream ss;  
        ss << n;  
        ss >> str;

        (yyval.expr)->str = *(yyvsp[-4].str) + oss.str();

      }
#line 2204 "parser.cpp"
    break;

  case 83:
#line 600 "parser.y"
      { 
        (yyval.expr) = new expresionstruct;
        int n = (yyvsp[0].list)->size();
        std::vector<string> aux(n+1);
        std::ostringstream oss;

        for (auto &auxi : *(yyvsp[0].list)){
             aux.push_back("[" + auxi + "]");
        }

        aux.push_back("[" + *(yyvsp[-2].str) + "]");
        std::copy(aux.rbegin(), aux.rend(),
        std::ostream_iterator<string>(oss));
        
        for (auto &auxi : *(yyvsp[0].list)){
          (yyval.expr)->arr.push_back(auxi);
        }
        
        (yyval.expr)->arr.push_back(*(yyvsp[-2].str));
        (yyval.expr)->arr.push_back(*(yyvsp[-4].str));
        string str;
        stringstream ss;  
        ss << n;  
        ss >> str;

        (yyval.expr)->str = *(yyvsp[-4].str) + oss.str();

      }
#line 2237 "parser.cpp"
    break;

  case 85:
#line 631 "parser.y"
          { (yyval.number) = codigo.obtenRef() ; }
#line 2243 "parser.cpp"
    break;


#line 2247 "parser.cpp"

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
#line 634 "parser.y"

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
