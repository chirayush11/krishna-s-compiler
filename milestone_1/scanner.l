%{
  #include <iostream>
  #include <stack>
  #include <cstdlib>

  #include "parser.hpp"

  /*
   * https://docs.python.org/3/reference/lexical_analysis.html#indentation
   */
  std::stack<int> _indent_stack;
%}

%option noyywrap
%option yylineno

%%

%{
  if (_indent_stack.empty()) {
    _indent_stack.push(0);
  }
  yypstate* pstate = yypstate_new();

  YYSTYPE yylval;
  YYLTYPE loc;
  #define PUSH_TOKEN(category, lexeme) do {                      \
    yylval.str = lexeme ? new std::string(lexeme) : NULL;            \
    loc.first_line = loc.last_line = yylineno;                   \
    int status = yypush_parse(pstate, category, &yylval, &loc);  \
    if (status != YYPUSH_MORE) {                                 \
      yypstate_delete(pstate);                                   \
      return status;                                             \
    }                                                            \
  } while (0)
%}

^[ \t]*\r?\n

^[ \t]*#.*\r?\n 

#.*$

^[ \t]+ {
  if (_indent_stack.top() < yyleng) {
    _indent_stack.push(yyleng);
    PUSH_TOKEN(INDENT, NULL);
  } else {
    while (!_indent_stack.empty() && _indent_stack.top() != yyleng) {
      _indent_stack.pop();
      PUSH_TOKEN(DEDENT, NULL);
    }
    if (_indent_stack.empty()) {
      std::cerr << "Error: Incorrect indentation on line " << yylineno
        << std::endl;
      return 1;
    }
  }
}
^[^ \t\r\n]+ {
  while (_indent_stack.top() != 0) {
    _indent_stack.pop();
    PUSH_TOKEN(DEDENT, NULL);
  }
  REJECT;
}

\r?\n {
  PUSH_TOKEN(NEWLINE, NULL);
}

<<EOF>> {
  /*
   * If we reach the end of the file, pop all indentation levels off the stack
   * and emit a DEDENT for each one.
   */
  while(_indent_stack.top() != 0) {
    _indent_stack.pop();
    PUSH_TOKEN(DEDENT, NULL);
  }
  int status = yypush_parse(pstate, 0, NULL, NULL);
  yypstate_delete(pstate);
  return status;
}

[ \t]  
"and" {
  PUSH_TOKEN(AND, NULL);
}
"break" {
  PUSH_TOKEN(BREAK, NULL);
}
"def" {
  PUSH_TOKEN(DEF, NULL);
}
"elif" {
  PUSH_TOKEN(ELIF, NULL);
}
"else" {
  PUSH_TOKEN(ELSE, NULL);
}
"for" {
  PUSH_TOKEN(FOR, NULL);
}
"if" {
  PUSH_TOKEN(IF, NULL);
}
"not" {
  PUSH_TOKEN(NOT, NULL);
}
"or" {
  PUSH_TOKEN(OR, NULL);
}
"return" {
  PUSH_TOKEN(RETURN, NULL);
}
"int" {
  PUSH_TOKEN(INT, NULL);
}
"float" {
  PUSH_TOKEN(FLOAT, NULL);
}
"bool" {
    PUSH_TOKEN(BOOL, NULL);
}
"str" {
    PUSH_TOKEN(STR, NULL);
}
"while" {
  PUSH_TOKEN(WHILE, NULL);
}
"continue" {
  PUSH_TOKEN(CONTINUE, NULL);
}
"True" {
  PUSH_TOKEN(BOOLEAN, yytext);
}
"False" {
  PUSH_TOKEN(BOOLEAN, yytext);
}
"in" {
  PUSH_TOKEN(IN, yytext);
}
"range" {
  PUSH_TOKEN(RANGE, yytext);
}
"list" {
  PUSH_TOKEN(LIST, yytext);
}
"None" {
  PUSH_TOKEN(NONE, yytext);
}
[a-zA-Z_][a-zA-Z0-9_]* {
  PUSH_TOKEN(IDENTIFIER, yytext);
}
[0-9]*"."[0-9]+ {
  PUSH_TOKEN(DECIMAL, yytext);
}
[0-9]+ {
  PUSH_TOKEN(NUMBER, yytext);
}
"=" {
  PUSH_TOKEN(ASSIGN, NULL);
}
"+=" {
  PUSH_TOKEN(CONDASSIGN, NULL);
}
"+" {
  PUSH_TOKEN(PLUS, NULL);
}
"-" {
  PUSH_TOKEN(MINUS, NULL);
}
"*" {
  PUSH_TOKEN(TIMES, NULL);
}
"/" {
  PUSH_TOKEN(DIVIDEDBY, NULL);
}
"//" {
  PUSH_TOKEN(INTDIVIDEDBY, NULL);
}
"%" {
  PUSH_TOKEN(MOD, NULL);
}
"^" {
  PUSH_TOKEN(XOR, NULL);
}
"~" {
  PUSH_TOKEN(NEGATION, NULL);
}
"->" {
  PUSH_TOKEN(ARROW, NULL);
}
"<<" {
  PUSH_TOKEN(LSHIFT, NULL);
}
">>" {
  PUSH_TOKEN(RSHIFT, NULL);
}
"**" {
  PUSH_TOKEN(EXPO, NULL);
}
"==" {
  PUSH_TOKEN(EQ, NULL);
}
"!=" {
  PUSH_TOKEN(NEQ, NULL);
}
">"  {
  PUSH_TOKEN(GT, NULL);
}
">=" {
  PUSH_TOKEN(GTE, NULL);
}
"<" {
  PUSH_TOKEN(LT, NULL);
}
"<=" {
  PUSH_TOKEN(LTE, NULL);
}
"(" {
  PUSH_TOKEN(LPAREN, NULL);
}
")" {
  PUSH_TOKEN(RPAREN, NULL);
}
"," {
  PUSH_TOKEN(COMMA, NULL);
}
":" {
  PUSH_TOKEN(COLON, NULL);
}
\[	{
  PUSH_TOKEN(LSQUARE, NULL);
}
\]	{
  PUSH_TOKEN(RSQUARE, NULL);
}
. {
  std::cerr << "Unrecognized token on line " << yylineno << ": " << yytext
    << std::endl;
  PUSH_TOKEN(yytext[0], NULL);
}
%%
 