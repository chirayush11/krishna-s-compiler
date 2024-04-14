/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "parser.y"

  #include "tree.hpp"

#line 53 "parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    BOOLEAN = 259,                 /* BOOLEAN  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    NUMBER = 262,                  /* NUMBER  */
    STR = 263,                     /* STR  */
    DECIMAL = 264,                 /* DECIMAL  */
    BOOL = 265,                    /* BOOL  */
    INDENT = 266,                  /* INDENT  */
    DEDENT = 267,                  /* DEDENT  */
    NEWLINE = 268,                 /* NEWLINE  */
    NEGATION = 269,                /* NEGATION  */
    LIST = 270,                    /* LIST  */
    NONE = 271,                    /* NONE  */
    DEF = 272,                     /* DEF  */
    FOR = 273,                     /* FOR  */
    IF = 274,                      /* IF  */
    RANGE = 275,                   /* RANGE  */
    PLUS = 276,                    /* PLUS  */
    MINUS = 277,                   /* MINUS  */
    TIMES = 278,                   /* TIMES  */
    DIVIDEDBY = 279,               /* DIVIDEDBY  */
    INTDIVIDEDBY = 280,            /* INTDIVIDEDBY  */
    MOD = 281,                     /* MOD  */
    EXPO = 282,                    /* EXPO  */
    EQ = 283,                      /* EQ  */
    NEQ = 284,                     /* NEQ  */
    GT = 285,                      /* GT  */
    GTE = 286,                     /* GTE  */
    LT = 287,                      /* LT  */
    LTE = 288,                     /* LTE  */
    BITOR = 289,                   /* BITOR  */
    XOR = 290,                     /* XOR  */
    BITAND = 291,                  /* BITAND  */
    NOT = 292,                     /* NOT  */
    AND = 293,                     /* AND  */
    OR = 294,                      /* OR  */
    RETURN = 295,                  /* RETURN  */
    BREAK = 296,                   /* BREAK  */
    CONTINUE = 297,                /* CONTINUE  */
    ELSE = 298,                    /* ELSE  */
    ELIF = 299,                    /* ELIF  */
    WHILE = 300,                   /* WHILE  */
    LSQUARE = 301,                 /* LSQUARE  */
    RSQUARE = 302,                 /* RSQUARE  */
    IN = 303,                      /* IN  */
    COLON = 304,                   /* COLON  */
    COMMA = 305,                   /* COMMA  */
    ARROW = 306,                   /* ARROW  */
    LPAREN = 307,                  /* LPAREN  */
    RPAREN = 308,                  /* RPAREN  */
    ASSIGN = 309,                  /* ASSIGN  */
    CONDASSIGN = 310,              /* CONDASSIGN  */
    LSHIFT = 311,                  /* LSHIFT  */
    RSHIFT = 312                   /* RSHIFT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

  std::string* str;
  Tree * node;

#line 132 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;


int yypush_parse (yypstate *ps,
                  int pushed_char, YYSTYPE const *pushed_val, YYLTYPE *pushed_loc);

yypstate *yypstate_new (void);
void yypstate_delete (yypstate *ps);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
