/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* First part of user prologue.  */
#line 1 "parser.y"

  #include <iostream>
  #include <set>
  #include "parser.hpp"

  extern int yylex();
  void yyerror(YYLTYPE* loc, const char* err);
  std::string* translate_boolean_str(std::string* boolean_str);

  std::string* target_program;
  std::set<std::string> symbols;
  Tree * root;

#line 85 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_BOOLEAN = 4,                    /* BOOLEAN  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_NUMBER = 7,                     /* NUMBER  */
  YYSYMBOL_STR = 8,                        /* STR  */
  YYSYMBOL_DECIMAL = 9,                    /* DECIMAL  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_INDENT = 11,                    /* INDENT  */
  YYSYMBOL_DEDENT = 12,                    /* DEDENT  */
  YYSYMBOL_NEWLINE = 13,                   /* NEWLINE  */
  YYSYMBOL_NEGATION = 14,                  /* NEGATION  */
  YYSYMBOL_LIST = 15,                      /* LIST  */
  YYSYMBOL_NONE = 16,                      /* NONE  */
  YYSYMBOL_DEF = 17,                       /* DEF  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_RANGE = 20,                     /* RANGE  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_TIMES = 23,                     /* TIMES  */
  YYSYMBOL_DIVIDEDBY = 24,                 /* DIVIDEDBY  */
  YYSYMBOL_INTDIVIDEDBY = 25,              /* INTDIVIDEDBY  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_EXPO = 27,                      /* EXPO  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NEQ = 29,                       /* NEQ  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_GTE = 31,                       /* GTE  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_LTE = 33,                       /* LTE  */
  YYSYMBOL_BITOR = 34,                     /* BITOR  */
  YYSYMBOL_XOR = 35,                       /* XOR  */
  YYSYMBOL_BITAND = 36,                    /* BITAND  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_AND = 38,                       /* AND  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 42,                  /* CONTINUE  */
  YYSYMBOL_ELSE = 43,                      /* ELSE  */
  YYSYMBOL_ELIF = 44,                      /* ELIF  */
  YYSYMBOL_WHILE = 45,                     /* WHILE  */
  YYSYMBOL_LSQUARE = 46,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 47,                   /* RSQUARE  */
  YYSYMBOL_IN = 48,                        /* IN  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_COMMA = 50,                     /* COMMA  */
  YYSYMBOL_ARROW = 51,                     /* ARROW  */
  YYSYMBOL_LPAREN = 52,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 53,                    /* RPAREN  */
  YYSYMBOL_ASSIGN = 54,                    /* ASSIGN  */
  YYSYMBOL_CONDASSIGN = 55,                /* CONDASSIGN  */
  YYSYMBOL_LSHIFT = 56,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 57,                    /* RSHIFT  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_stmts = 60,                     /* stmts  */
  YYSYMBOL_stmt = 61,                      /* stmt  */
  YYSYMBOL_funcdef = 62,                   /* funcdef  */
  YYSYMBOL_maindef = 63,                   /* maindef  */
  YYSYMBOL_keyword = 64,                   /* keyword  */
  YYSYMBOL_assign_state = 65,              /* assign_state  */
  YYSYMBOL_data_declaration = 66,          /* data_declaration  */
  YYSYMBOL_data = 67,                      /* data  */
  YYSYMBOL_data_values = 68,               /* data_values  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_if_state = 70,                  /* if_state  */
  YYSYMBOL_elif_blocks = 71,               /* elif_blocks  */
  YYSYMBOL_else_block = 72,                /* else_block  */
  YYSYMBOL_while_state = 73,               /* while_state  */
  YYSYMBOL_for_state = 74,                 /* for_state  */
  YYSYMBOL_continue_state = 75,            /* continue_state  */
  YYSYMBOL_break_state = 76,               /* break_state  */
  YYSYMBOL_condition = 77,                 /* condition  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_negated_expression = 79,        /* negated_expression  */
  YYSYMBOL_primary_expression = 80         /* primary_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    62,    67,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    89,    98,   137,   141,   145,   149,
     153,   162,   169,   179,   190,   198,   201,   206,   216,   224,
     235,   238,   248,   251,   259,   268,   278,   285,   292,   293,
     299,   308,   309,   310,   316,   322,   328,   334,   340,   346,
     352,   358,   364,   370,   376,   382,   391,   399,   403,   407,
     411,   415
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "BOOLEAN", "INT", "FLOAT", "NUMBER", "STR", "DECIMAL", "BOOL", "INDENT",
  "DEDENT", "NEWLINE", "NEGATION", "LIST", "NONE", "DEF", "FOR", "IF",
  "RANGE", "PLUS", "MINUS", "TIMES", "DIVIDEDBY", "INTDIVIDEDBY", "MOD",
  "EXPO", "EQ", "NEQ", "GT", "GTE", "LT", "LTE", "BITOR", "XOR", "BITAND",
  "NOT", "AND", "OR", "RETURN", "BREAK", "CONTINUE", "ELSE", "ELIF",
  "WHILE", "LSQUARE", "RSQUARE", "IN", "COLON", "COMMA", "ARROW", "LPAREN",
  "RPAREN", "ASSIGN", "CONDASSIGN", "LSHIFT", "RSHIFT", "$accept",
  "program", "stmts", "stmt", "funcdef", "maindef", "keyword",
  "assign_state", "data_declaration", "data", "data_values", "block",
  "if_state", "elif_blocks", "else_block", "while_state", "for_state",
  "continue_state", "break_state", "condition", "expression",
  "negated_expression", "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      64,   -48,    -1,     1,    20,    -3,     3,    20,    28,    64,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
      15,    20,    20,     9,   -14,   -70,   -70,   -70,   -70,     8,
      20,   -30,   159,   -70,   -70,   -70,   -70,   -18,   -70,   -70,
      -9,   125,   146,     2,    49,   -70,    92,    20,    20,    57,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    60,    58,   -70,   -70,    22,    30,    39,
     -70,   -70,    42,    81,   103,   103,    66,    66,    66,    66,
     -70,    63,    63,    63,    63,    63,    63,    81,   -70,   -70,
     -70,   -70,   -70,    47,    45,    84,    52,    64,   -70,   -70,
      48,    58,    81,    20,    50,    59,    -5,    61,    62,   -70,
     -15,   159,    82,   -70,    83,    20,   -70,    52,    97,   -70,
      20,   120,   121,   -13,    88,    81,   159,    81,    81,   123,
     124,   -70,   -70,   -70,    81,   -70,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,    10,    11,    13,    12,     8,     5,     9,     7,     6,
       0,     0,     0,     0,     0,    57,    60,    59,    58,     0,
       0,     0,    38,    42,    41,    37,    36,     0,     1,     4,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,     0,     0,     0,
      61,    39,    40,     0,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     0,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,    30,    34,
       0,     0,     0,    25,     0,     0,    32,     0,     0,    15,
       0,    26,     0,    28,     0,     0,    29,     0,     0,    24,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,    14,    35,    33,     0,    23,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,    43,    -6,   -70,   -70,    38,   -70,   -70,    24,
     -70,   -69,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    -7,
      -8,   -70,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    93,    13,    14,   104,
     110,    98,    15,   106,   116,    16,    17,    18,    19,    31,
      32,    33,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    20,    23,    39,    24,    67,    21,    22,    47,    48,
      35,    25,    26,    41,    42,    27,    36,    28,    99,    49,
      47,    48,    46,    25,    26,    47,    48,    27,    38,    28,
      40,    63,   119,   109,    44,   120,   129,    64,   114,   115,
      71,    72,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    68,   131,    29,   132,   133,
      30,    43,     1,    88,    89,   136,    90,     1,    91,    69,
      73,   113,    30,    87,    92,    94,     2,     3,     4,    95,
      47,     2,     3,     4,    50,    51,    52,    53,    54,    55,
      56,    96,    97,    56,   100,   111,   101,   102,   103,    39,
       5,     6,   107,   112,     7,     5,     6,   117,   123,     7,
     125,   118,   126,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    52,    53,    54,    55,
      56,   121,   122,   127,   128,   130,   134,   135,    65,   108,
     105,   124,    45,     0,     0,    70,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    66,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62
};

static const yytype_int16 yycheck[] =
{
       7,    49,     3,     9,     3,     3,    54,    55,    38,    39,
      13,     3,     4,    21,    22,     7,    13,     9,    87,    49,
      38,    39,    30,     3,     4,    38,    39,     7,     0,     9,
      15,    49,    47,   102,    48,    50,    49,    46,    43,    44,
      47,    48,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    53,   125,    37,   127,   128,
      52,    52,     3,     5,     6,   134,     8,     3,    10,    20,
      13,    12,    52,    13,    16,    53,    17,    18,    19,    49,
      38,    17,    18,    19,    21,    22,    23,    24,    25,    26,
      27,    52,    11,    27,    47,   103,    51,    13,    46,   105,
      41,    42,    54,    53,    45,    41,    42,    46,   115,    45,
      13,    49,   120,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    23,    24,    25,    26,
      27,    49,    49,    13,    13,    47,    13,    13,    13,   101,
      97,   117,    29,    -1,    -1,    53,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    17,    18,    19,    41,    42,    45,    59,    60,
      61,    62,    63,    65,    66,    70,    73,    74,    75,    76,
      49,    54,    55,     3,     3,     3,     4,     7,     9,    37,
      52,    77,    78,    79,    80,    13,    13,    77,     0,    61,
      15,    78,    78,    52,    48,    80,    78,    38,    39,    49,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    49,    46,    13,    13,     3,    53,    20,
      53,    77,    77,    13,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    13,     5,     6,
       8,    10,    16,    64,    53,    49,    52,    11,    69,    69,
      47,    51,    13,    46,    67,    60,    71,    54,    64,    69,
      68,    78,    53,    12,    43,    44,    72,    46,    49,    47,
      50,    49,    49,    77,    67,    13,    78,    13,    13,    49,
      47,    69,    69,    69,    13,    13,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    64,    64,    64,    64,
      64,    65,    65,    66,    67,    68,    68,    68,    69,    70,
      71,    71,    72,    72,    73,    74,    75,    76,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    80,    80,    80,
      80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    10,     7,     1,     1,     1,     1,
       1,     4,     4,    11,     3,     0,     1,     3,     3,     7,
       0,     6,     0,     4,     5,    10,     2,     2,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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
/* Parser data structure.  */
struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;
    /* Whether this instance has not started parsing yet.
     * If 2, it corresponds to a finished parsing.  */
    int yynew;
  };






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}





#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yylsa yyps->yylsa
#define yyls yyps->yyls
#define yylsp yyps->yylsp
#define yystacksize yyps->yystacksize

/* Initialize the parser data structure.  */
static void
yypstate_clear (yypstate *yyps)
{
  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

  /* Initialize the state stack, in case yypcontext_expected_tokens is
     called before the first call to yyparse. */
  *yyssp = 0;
  yyps->yynew = 1;
}

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = YY_CAST (yypstate *, YYMALLOC (sizeof *yyps));
  if (!yyps)
    return YY_NULLPTR;
  yystacksize = YYINITDEPTH;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yypstate_clear (yyps);
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
  if (yyps)
    {
#ifndef yyoverflow
      /* If the stack was reallocated but the parse did not complete, then the
         stack still needs to be freed.  */
      if (yyss != yyssa)
        YYSTACK_FREE (yyss);
#endif
      YYFREE (yyps);
    }
}



/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps,
              int yypushed_char, YYSTYPE const *yypushed_val, YYLTYPE *yypushed_loc)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  switch (yyps->yynew)
    {
    case 0:
      yyn = yypact[yystate];
      goto yyread_pushed_token;

    case 2:
      yypstate_clear (yyps);
      break;

    default:
      break;
    }

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = *yypushed_loc;
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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
      if (yypushed_loc)
        yylloc = *yypushed_loc;
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmts  */
#line 56 "parser.y"
          {
      root = (yyvsp[0].node);
    }
#line 1453 "parser.cpp"
    break;

  case 3: /* stmts: stmt  */
#line 62 "parser.y"
         {
      Tree * temp = new Tree("STATEMENT", "");
      temp->block.push_back((yyvsp[0].node));
      (yyval.node) = temp;
  }
#line 1463 "parser.cpp"
    break;

  case 4: /* stmts: stmts stmt  */
#line 67 "parser.y"
               {
      Tree * temp = new Tree("STATEMENT", "");
      temp->block.push_back((yyvsp[-1].node));
      temp->block.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1474 "parser.cpp"
    break;

  case 5: /* stmt: while_state  */
#line 76 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1480 "parser.cpp"
    break;

  case 6: /* stmt: break_state  */
#line 77 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1486 "parser.cpp"
    break;

  case 7: /* stmt: continue_state  */
#line 78 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1492 "parser.cpp"
    break;

  case 8: /* stmt: if_state  */
#line 79 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1498 "parser.cpp"
    break;

  case 9: /* stmt: for_state  */
#line 80 "parser.y"
              { (yyval.node) = (yyvsp[0].node);}
#line 1504 "parser.cpp"
    break;

  case 10: /* stmt: funcdef  */
#line 81 "parser.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 1510 "parser.cpp"
    break;

  case 11: /* stmt: maindef  */
#line 82 "parser.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 1516 "parser.cpp"
    break;

  case 12: /* stmt: data_declaration  */
#line 83 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1522 "parser.cpp"
    break;

  case 13: /* stmt: assign_state  */
#line 84 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1528 "parser.cpp"
    break;

  case 14: /* funcdef: DEF IDENTIFIER LPAREN IDENTIFIER RPAREN ARROW keyword COLON NEWLINE block  */
#line 89 "parser.y"
                                                                                {
      Tree * temp = new Tree("FUNCTION_DEFINITION", "");
      temp->child.push_back(new Tree("IDENTIFIER", *(yyvsp[-8].str)));
      temp->child.push_back((yyvsp[-3].node));
      (yyval.node) = temp;
    }
#line 1539 "parser.cpp"
    break;

  case 15: /* maindef: DEF IDENTIFIER LPAREN RPAREN COLON NEWLINE block  */
#line 98 "parser.y"
                                                       {
      Tree * temp = new Tree("MAIN_DEFINITION", "");
      temp->child.push_back(new Tree("IDENTIFIER", *(yyvsp[-5].str)));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1550 "parser.cpp"
    break;

  case 16: /* keyword: INT  */
#line 137 "parser.y"
          {
      Tree * temp = new Tree("INT", "");
      (yyval.node) = temp;
    }
#line 1559 "parser.cpp"
    break;

  case 17: /* keyword: FLOAT  */
#line 141 "parser.y"
            {
      Tree * temp = new Tree("FLOAT", "");
      (yyval.node) = temp;
    }
#line 1568 "parser.cpp"
    break;

  case 18: /* keyword: STR  */
#line 145 "parser.y"
          {
      Tree * temp = new Tree("STR", "");
      (yyval.node) = temp;
    }
#line 1577 "parser.cpp"
    break;

  case 19: /* keyword: BOOL  */
#line 149 "parser.y"
           {
      Tree * temp = new Tree("BOOL", "");
      (yyval.node) = temp;
    }
#line 1586 "parser.cpp"
    break;

  case 20: /* keyword: NONE  */
#line 153 "parser.y"
           {
      Tree * temp = new Tree("NONE", "");
      (yyval.node) = temp;
    }
#line 1595 "parser.cpp"
    break;

  case 21: /* assign_state: IDENTIFIER ASSIGN expression NEWLINE  */
#line 162 "parser.y"
                                         {
      Tree * id = new Tree("IDENTIFIER", *(yyvsp[-3].str));
      Tree * temp = new Tree("aa", "");
      temp->child.push_back(id);
      temp->child.push_back((yyvsp[-1].node));
      (yyval.node) = temp;
    }
#line 1607 "parser.cpp"
    break;

  case 22: /* assign_state: IDENTIFIER CONDASSIGN expression NEWLINE  */
#line 169 "parser.y"
                                             {
      Tree * id = new Tree("IDENTIFIER", *(yyvsp[-3].str));
      Tree * temp = new Tree("ConditionalAssignmentStatement", "");
      temp->child.push_back(id);
      temp->child.push_back((yyvsp[-1].node));
      (yyval.node) = temp;
    }
#line 1619 "parser.cpp"
    break;

  case 23: /* data_declaration: IDENTIFIER COLON LIST LSQUARE keyword RSQUARE ASSIGN LSQUARE data RSQUARE NEWLINE  */
#line 179 "parser.y"
                                                                                      {
      Tree * temp = new Tree("DATA_DECLARATION", "");
      temp->child.push_back(new Tree("IDENTIFIER", *(yyvsp[-10].str)));
      temp->child.push_back((yyvsp[-6].node)); // The type of the list (e.g., FLOAT)
      temp->child.push_back((yyvsp[-2].node)); // The list data
      (yyval.node) = temp;
    }
#line 1631 "parser.cpp"
    break;

  case 24: /* data: LSQUARE data_values RSQUARE  */
#line 190 "parser.y"
                                {
      Tree * temp = new Tree("LIST", "");
      temp->block.push_back((yyvsp[-1].node));
      (yyval.node) = temp;
    }
#line 1641 "parser.cpp"
    break;

  case 25: /* data_values: %empty  */
#line 198 "parser.y"
           {
      (yyval.node) = NULL;
    }
#line 1649 "parser.cpp"
    break;

  case 26: /* data_values: expression  */
#line 201 "parser.y"
               {
      Tree * temp = new Tree("DATA", "");
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1659 "parser.cpp"
    break;

  case 27: /* data_values: data_values COMMA expression  */
#line 206 "parser.y"
                                 {
      Tree * temp = new Tree("DATA", "");
      temp->block.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1670 "parser.cpp"
    break;

  case 28: /* block: INDENT stmts DEDENT  */
#line 216 "parser.y"
                        {
      Tree * temp = new Tree("block", "");
      temp->child.push_back((yyvsp[-1].node));
      (yyval.node) = temp;
     }
#line 1680 "parser.cpp"
    break;

  case 29: /* if_state: IF condition COLON NEWLINE block elif_blocks else_block  */
#line 224 "parser.y"
                                                            {
      Tree * temp = new Tree("IF_STATEMENT", "");
      temp->child.push_back((yyvsp[-5].node));
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[-1].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1693 "parser.cpp"
    break;

  case 30: /* elif_blocks: %empty  */
#line 235 "parser.y"
           {
      (yyval.node) = NULL;
    }
#line 1701 "parser.cpp"
    break;

  case 31: /* elif_blocks: elif_blocks ELIF condition COLON NEWLINE block  */
#line 238 "parser.y"
                                                   {
      Tree * temp = new Tree("ELIF_BLOCKS", "");
      temp->block.push_back((yyvsp[-5].node));
      temp->child.push_back((yyvsp[0].node));
      temp->child.push_back((yyvsp[-3].node));
      (yyval.node) = temp;
    }
#line 1713 "parser.cpp"
    break;

  case 32: /* else_block: %empty  */
#line 248 "parser.y"
           {
      (yyval.node) = NULL;
    }
#line 1721 "parser.cpp"
    break;

  case 33: /* else_block: ELSE COLON NEWLINE block  */
#line 251 "parser.y"
                             {
      Tree * temp = new Tree("ELSE", "");
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1731 "parser.cpp"
    break;

  case 34: /* while_state: WHILE condition COLON NEWLINE block  */
#line 259 "parser.y"
                                        {
      Tree * temp = new Tree("WHILE", "");
      temp->child.push_back((yyvsp[0].node));
      temp->child.push_back((yyvsp[-3].node));
      (yyval.node) = temp;
    }
#line 1742 "parser.cpp"
    break;

  case 35: /* for_state: FOR IDENTIFIER IN RANGE LPAREN data RPAREN COLON NEWLINE block  */
#line 268 "parser.y"
                                                                   {
      Tree *temp = new Tree("FOR_RANGE", "");
      temp->child.push_back(new Tree("VAR", *(yyvsp[-8].str)));
      temp->child.push_back((yyvsp[-4].node));
      temp->child.push_back((yyvsp[-1].node));
      (yyval.node) = temp;
    }
#line 1754 "parser.cpp"
    break;

  case 36: /* continue_state: CONTINUE NEWLINE  */
#line 278 "parser.y"
                     {
      Tree * temp = new Tree("CONTINUE", "");
      (yyval.node) = temp;
    }
#line 1763 "parser.cpp"
    break;

  case 37: /* break_state: BREAK NEWLINE  */
#line 285 "parser.y"
                  {
      Tree * temp = new Tree("BREAK", "");
      (yyval.node) = temp;
    }
#line 1772 "parser.cpp"
    break;

  case 38: /* condition: expression  */
#line 292 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1778 "parser.cpp"
    break;

  case 39: /* condition: condition AND condition  */
#line 293 "parser.y"
                            {
      Tree * temp = new Tree("AND", "AND");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1789 "parser.cpp"
    break;

  case 40: /* condition: condition OR condition  */
#line 299 "parser.y"
                           {
      Tree * temp = new Tree("OR", "OR");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1800 "parser.cpp"
    break;

  case 41: /* expression: primary_expression  */
#line 308 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1806 "parser.cpp"
    break;

  case 42: /* expression: negated_expression  */
#line 309 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1812 "parser.cpp"
    break;

  case 43: /* expression: expression PLUS expression  */
#line 310 "parser.y"
                               {
      Tree * temp = new Tree("PLUS", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1823 "parser.cpp"
    break;

  case 44: /* expression: expression MINUS expression  */
#line 316 "parser.y"
                                {
      Tree * temp = new Tree("MINUS", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1834 "parser.cpp"
    break;

  case 45: /* expression: expression TIMES expression  */
#line 322 "parser.y"
                                {
      Tree * temp = new Tree("TIMES", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1845 "parser.cpp"
    break;

  case 46: /* expression: expression DIVIDEDBY expression  */
#line 328 "parser.y"
                                    {
      Tree * temp = new Tree("DIVIDEDBY", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1856 "parser.cpp"
    break;

  case 47: /* expression: expression INTDIVIDEDBY expression  */
#line 334 "parser.y"
                                       {
      Tree * temp = new Tree("INTDIVIDEDBY", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1867 "parser.cpp"
    break;

  case 48: /* expression: expression MOD expression  */
#line 340 "parser.y"
                              {
      Tree * temp = new Tree("MOD", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1878 "parser.cpp"
    break;

  case 49: /* expression: expression EXPO expression  */
#line 346 "parser.y"
                               {
      Tree * temp = new Tree("EXPO", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1889 "parser.cpp"
    break;

  case 50: /* expression: expression EQ expression  */
#line 352 "parser.y"
                             {
      Tree * temp = new Tree("EQ", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));      
      (yyval.node) = temp;
     }
#line 1900 "parser.cpp"
    break;

  case 51: /* expression: expression NEQ expression  */
#line 358 "parser.y"
                              {
      Tree * temp = new Tree("NEQ", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));      
      (yyval.node) = temp;
     }
#line 1911 "parser.cpp"
    break;

  case 52: /* expression: expression GT expression  */
#line 364 "parser.y"
                             {
      Tree * temp = new Tree("GT", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
     }
#line 1922 "parser.cpp"
    break;

  case 53: /* expression: expression GTE expression  */
#line 370 "parser.y"
                              {
      Tree * temp = new Tree("GTE", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));      
      (yyval.node) = temp;
     }
#line 1933 "parser.cpp"
    break;

  case 54: /* expression: expression LT expression  */
#line 376 "parser.y"
                             {
      Tree * temp = new Tree("LT", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));      
      (yyval.node) = temp;
     }
#line 1944 "parser.cpp"
    break;

  case 55: /* expression: expression LTE expression  */
#line 382 "parser.y"
                              {
      Tree * temp = new Tree("LTE", "");
      temp->child.push_back((yyvsp[-2].node));
      temp->child.push_back((yyvsp[0].node));      
      (yyval.node) = temp;
     }
#line 1955 "parser.cpp"
    break;

  case 56: /* negated_expression: NOT primary_expression  */
#line 391 "parser.y"
                           {
      Tree * temp = new Tree("NOT", NULL);
      temp->child.push_back((yyvsp[0].node));
      (yyval.node) = temp;
    }
#line 1965 "parser.cpp"
    break;

  case 57: /* primary_expression: IDENTIFIER  */
#line 399 "parser.y"
               {
      Tree * temp = new Tree("IDENTIFIER", *(yyvsp[0].str));
      (yyval.node) = temp;
    }
#line 1974 "parser.cpp"
    break;

  case 58: /* primary_expression: DECIMAL  */
#line 403 "parser.y"
            {
      Tree * temp = new Tree("DECIMAL", *(yyvsp[0].str));
      (yyval.node) = temp;
    }
#line 1983 "parser.cpp"
    break;

  case 59: /* primary_expression: NUMBER  */
#line 407 "parser.y"
           {
      Tree * temp = new Tree("NUMBER", *(yyvsp[0].str));
      (yyval.node) = temp;
    }
#line 1992 "parser.cpp"
    break;

  case 60: /* primary_expression: BOOLEAN  */
#line 411 "parser.y"
            {
      Tree * temp = new Tree("BOOLEAN", *translate_boolean_str((yyvsp[0].str)));
      (yyval.node) = temp;
    }
#line 2001 "parser.cpp"
    break;

  case 61: /* primary_expression: LPAREN expression RPAREN  */
#line 415 "parser.y"
                             {
      Tree * temp = new Tree("PARENTHESES", "");
      temp->child.push_back((yyvsp[-1].node));
      (yyval.node) = temp;
    }
#line 2011 "parser.cpp"
    break;


#line 2015 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (&yylloc, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
  yyps->yynew = 2;
  goto yypushreturn;


/*-------------------------.
| yypushreturn -- return.  |
`-------------------------*/
yypushreturn:

  return yyresult;
}
#undef yynerrs
#undef yystate
#undef yyerrstatus
#undef yyssa
#undef yyss
#undef yyssp
#undef yyvsa
#undef yyvs
#undef yyvsp
#undef yylsa
#undef yyls
#undef yylsp
#undef yystacksize
#line 422 "parser.y"


void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error (line " << loc->first_line << "): " << err << std::endl;
}

std::string* translate_boolean_str(std::string* boolean_str) {
  if (*boolean_str == "True") {
    return new std::string("true");
  } else {
    return new std::string("false");
  }
}

