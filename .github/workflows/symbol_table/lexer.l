%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "symtab.c"
	
	extern FILE *yyin;
	extern FILE *yyout;
	
	int lineno = 1; // initialize to 1
	void ret_print(char *token_type);
	void yyerror();
%}

%x ML_COMMENT

alpha 		[a-zA-Z]
digit 		[0-9]
alnum 		{alpha}|{digit}
print		[ -~]

ID          [a-zA-Z_][a-zA-Z0-9_]* 
ICONST		"0"|[0-9]{digit}*
FCONST		"0"|{digit}*"."{digit}+
CCONST		(\'{print}\')|(\'\\[nftrbv]\')
STRING		\"{print}*\"

%%

":"						{ ret_print("COLON");}
"//".*					{ printf("Eat up comment at line %d\n", lineno); } 

"/*"					{ printf("Eat up comment from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/" 		{ printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+		
<ML_COMMENT>"*"			
<ML_COMMENT>"\n"		{ lineno += 1; }


"str"|"STR"       	{ ret_print("KEYWORD_STR"); }
"int"|"INT"				{ ret_print("KEYWORD_INT"); }
"float"|"FLOAT"			{ ret_print("KEYWORD_FLOAT"); }
"if"|"IF"				{ ret_print("KEYWORD_IF"); }
"else"|"ELSE"			{ ret_print("KEYWORD_ELSE"); }
"elif"|"ELIF"			{ ret_print("KEYWORD_ELSEIF"); }
"while"|"WHILE"			{ ret_print("KEYWORD_WHILE"); }
"for"|"FOR"				{ ret_print("KEYWORD_FOR"); }
"continue"|"CONTINUE"	{ ret_print("KEYWORD_CONTINUE"); }
"break"|"BREAK"			{ ret_print("KEYWORD_BREAK"); }
"void"|"VOID"			{ ret_print("KEYWORD_VOID"); }
"return"|"RETURN"		{ ret_print("KEYWORD_RETURN"); }
"def"                   { ret_print("DEF");}
"print"|"PRINT"         { ret_print("PRINT");}
"none"|"None"|"NONE"    { ret_print("NONE");}
"__name__"              { ret_print("NAME");}
"\'__main__\'"|"\"__main__\""              { ret_print("MAINCALLED");}
"main"                  { ret_print("MAIN");}



"#"                 { ret_print("COMMENT");}
"+"|"-"				{ ret_print("ADDOP"); }
"*"					{ ret_print("MULOP"); }
"/"					{ ret_print("DIVOP"); }
"//"				{ ret_print("INTDIVOP"); }
"**"				{ ret_print("EXPOP"); }
"%"					{ ret_print("MODOP"); }
"++"|"--"			{ ret_print("INCR"); }
"|"					{ ret_print("OROP"); }
"&"					{ ret_print("ANDOP"); }
"^"					{ ret_print("XOROP"); }
"<<"				{ ret_print("LSHIFTOP"); }
">>"				{ ret_print("RSHIFTOP"); }
"~"|"!"					{ ret_print("NOTOPOP"); }
"=="				{ ret_print("EQUOP"); }
">"|"<"|">="|"<="	{ ret_print("RELOP"); }


"("				{ ret_print("LPAREN"); }
")"				{ ret_print("RPAREN"); }
"]"				{ ret_print("LBRACK"); }
"["				{ ret_print("RBRACK"); }
"{"				{ ret_print("LBRACE"); }
"}"				{ ret_print("RBRACE"); }
";"				{ ret_print("SEMI"); }
"."				{ ret_print("DOT"); }
","				{ ret_print("COMMA"); }
"="				{ ret_print("ASSIGN"); }
"+="			{ ret_print("PLUSASSIGN"); }
"-="			{ ret_print("MINUSASSIGN"); }
"*="			{ ret_print("MULTASSIGN"); }
"/="			{ ret_print("DIVASSIGN"); }
"//="			{ ret_print("INTDIVASSIGN"); }
"**="			{ ret_print("EXPASSIGN"); }
"%="			{ ret_print("MODASSIGN"); }
"&="			{ ret_print("ANDASSIGN"); }
"|="			{ ret_print("ORASSIGN"); }
"^="			{ ret_print("XORASSIGN"); }
"<<="			{ ret_print("LSHIFTASSIGN"); }
">>="			{ ret_print("RSHIFTASSIGN"); }




{ID} 			{
					// insert identifier into symbol table
					insert(yytext, strlen(yytext), UNDEF, lineno);
					ret_print("ID");
				}
{ICONST} 		{ ret_print("ICONST"); }
{FCONST} 		{ ret_print("FCONST"); }
{CCONST} 		{ ret_print("CCONST"); }
{STRING} 		{ ret_print("STRING"); }


"\n"			{ lineno += 1; }
[ \t\r\f]+			/* eat up whitespace */

.				{ yyerror("Unrecognized character"); }

%%

void ret_print(char *token_type){
	printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

void yyerror(char *message){
	printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
	exit(1);
}

int main(int argc, char *argv[]){
	// initialize symbol table
	init_hash_table();

	// open input file
	yyin = fopen(argv[1], "r");
	
	// lexical analysis
	yylex();
	fclose(yyin);
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);	
	
	return 0;
}