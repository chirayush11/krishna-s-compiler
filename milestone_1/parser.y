%{
  #include <iostream>
  #include <set>
  #include "parser.hpp"

  extern int yylex();
  void yyerror(YYLTYPE* loc, const char* err);
  std::string* translate_boolean_str(std::string* boolean_str);

  std::string* target_program;
  std::set<std::string> symbols;
  Tree * root;
%}

%code requires {
  #include "tree.hpp"
}

%locations

%union {
  std::string* str;
  Tree * node;
}

%define api.pure full
%define api.push-pull push

%token <str> IDENTIFIER  BOOLEAN INT FLOAT NUMBER STR DECIMAL BOOL 
%token <node> INDENT DEDENT NEWLINE NEGATION LIST NONE
%token <node> DEF FOR IF RANGE
%token <node> PLUS MINUS TIMES DIVIDEDBY INTDIVIDEDBY MOD EXPO
%token <node> EQ NEQ GT GTE LT LTE
%token <node> BITOR XOR BITAND
%token <node> NOT AND OR
%token <node> RETURN BREAK CONTINUE ELSE ELIF WHILE
%token <node> LSQUARE RSQUARE IN COLON COMMA ARROW LPAREN RPAREN ASSIGN CONDASSIGN
%type <node> program stmts stmt while_state if_state elif_blocks else_block for_state arg funcdef maindef data_declaration args arglist keyword data data_values
%type <node> continue_state break_state condition assign_state expression block negated_expression primary_expression

%left OR
%left AND
%right NOT
%left EQ NEQ GT GTE LT LTE
%left BITOR XOR BITAND
%left LSHIFT RSHIFT
%left PLUS MINUS
%left TIMES DIVIDEDBY INTDIVIDEDBY MOD
%left EXPO

%start program

%%

program
  : stmts {
      root = $1;
    }
  ;

stmts
  : stmt {
      Tree * temp = new Tree("STATEMENT", "");
      temp->block.push_back($1);
      $$ = temp;
  }
  | stmts stmt {
      Tree * temp = new Tree("STATEMENT", "");
      temp->block.push_back($1);
      temp->block.push_back($2);
      $$ = temp;
    }
  ;

stmt
  : while_state { $$ = $1; }
  | break_state { $$ = $1; }
  | continue_state { $$ = $1; }
  | if_state { $$ = $1; }
  | for_state { $$ = $1;}
  | funcdef  {$$ = $1;}
  | maindef  {$$ = $1;}
  | data_declaration { $$ = $1; }
  | assign_state { $$ = $1; }
  ;


funcdef
    : DEF IDENTIFIER LPAREN IDENTIFIER RPAREN ARROW keyword COLON NEWLINE block {
      Tree * temp = new Tree("FUNCTION_DEFINITION", "");
      temp->child.push_back(new Tree("IDENTIFIER", *$2));
      temp->child.push_back($7);
      $$ = temp;
    }
;

maindef
    : DEF IDENTIFIER LPAREN RPAREN COLON NEWLINE block {
      Tree * temp = new Tree("MAIN_DEFINITION", "");
      temp->child.push_back(new Tree("IDENTIFIER", *$2));
      temp->child.push_back($7);
      $$ = temp;
    }
    ;

arg 
    : %empty {
      $$ = NULL;
    }
    | args arglist {
        $$ = $1;
    }
    ;

args    
    : IDENTIFIER COLON keyword {
        Tree * temp = new Tree("COLON","");
        temp->child.push_back(new Tree("IDENTIFIER", *$1));
        temp->child.push_back($3);
        $$ = temp;
    }
    ;

arglist
    : %empty {
      $$ = NULL;
    }
    | COMMA args arglist {
        Tree * temp = new Tree("COMMA","");
        temp->child.push_back($2);
        temp->child.push_back($3);

    }
    ;

keyword
    : INT {
      Tree * temp = new Tree("INT", "");
      $$ = temp;
    }
    | FLOAT {
      Tree * temp = new Tree("FLOAT", "");
      $$ = temp;
    }
    | STR {
      Tree * temp = new Tree("STR", "");
      $$ = temp;
    }
    | BOOL {
      Tree * temp = new Tree("BOOL", "");
      $$ = temp;
    }
    | NONE {
      Tree * temp = new Tree("NONE", "");
      $$ = temp;
    }
    
;


assign_state
  : IDENTIFIER ASSIGN expression NEWLINE {
      Tree * id = new Tree("IDENTIFIER", *$1);
      Tree * temp = new Tree("aa", "");
      temp->child.push_back(id);
      temp->child.push_back($3);
      $$ = temp;
    }
  | IDENTIFIER CONDASSIGN expression NEWLINE {
      Tree * id = new Tree("IDENTIFIER", *$1);
      Tree * temp = new Tree("ConditionalAssignmentStatement", "");
      temp->child.push_back(id);
      temp->child.push_back($3);
      $$ = temp;
    }
  ;

data_declaration
  : IDENTIFIER COLON LIST LSQUARE keyword RSQUARE ASSIGN LSQUARE data RSQUARE NEWLINE {
      Tree * temp = new Tree("DATA_DECLARATION", "");
      temp->child.push_back(new Tree("IDENTIFIER", *$1));
      temp->child.push_back($5); // The type of the list (e.g., FLOAT)
      temp->child.push_back($9); // The list data
      $$ = temp;
    }
  ;


data
  : LSQUARE data_values RSQUARE {
      Tree * temp = new Tree("LIST", "");
      temp->block.push_back($2);
      $$ = temp;
    }
  ;

data_values
  : %empty {
      $$ = NULL;
    }
  | expression {
      Tree * temp = new Tree("DATA", "");
      temp->child.push_back($1);
      $$ = temp;
    }
  | data_values COMMA expression {
      Tree * temp = new Tree("DATA", "");
      temp->block.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
    }
  ;


block
  : INDENT stmts DEDENT {
      Tree * temp = new Tree("block", "");
      temp->child.push_back($2);
      $$ = temp;
     }
  ;

if_state
  : IF condition COLON NEWLINE block elif_blocks else_block {
      Tree * temp = new Tree("IF_STATEMENT", "");
      temp->child.push_back($2);
      temp->child.push_back($5);
      temp->child.push_back($6);
      temp->child.push_back($7);
      $$ = temp;
    }
  ;

elif_blocks
  : %empty {
      $$ = NULL;
    }
  | elif_blocks ELIF condition COLON NEWLINE block {
      Tree * temp = new Tree("ELIF_BLOCKS", "");
      temp->block.push_back($1);
      temp->child.push_back($6);
      temp->child.push_back($3);
      $$ = temp;
    }
  ;

else_block
  : %empty {
      $$ = NULL;
    }
  | ELSE COLON NEWLINE block {
      Tree * temp = new Tree("ELSE", "");
      temp->child.push_back($4);
      $$ = temp;
    }
  ;

while_state
  : WHILE condition COLON NEWLINE block {
      Tree * temp = new Tree("WHILE", "");
      temp->child.push_back($5);
      temp->child.push_back($2);
      $$ = temp;
    }
  ;

for_state
  : FOR IDENTIFIER IN RANGE LPAREN data RPAREN COLON NEWLINE block {
      Tree *temp = new Tree("FOR_RANGE", "");
      temp->child.push_back(new Tree("VAR", *$2));
      temp->child.push_back($6);
      temp->child.push_back($9);
      $$ = temp;
    }
  ;

continue_state
  : CONTINUE NEWLINE {
      Tree * temp = new Tree("CONTINUE", "");
      $$ = temp;
    }
  ;

break_state
  : BREAK NEWLINE {
      Tree * temp = new Tree("BREAK", "");
      $$ = temp;
    }
  ;

condition
  : expression { $$ = $1; }
  | condition AND condition {
      Tree * temp = new Tree("AND", "AND");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
    }
  | condition OR condition {
      Tree * temp = new Tree("OR", "OR");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
    }
  ;

expression
  : primary_expression { $$ = $1; }
  | negated_expression { $$ = $1; }
  | expression PLUS expression {
      Tree * temp = new Tree("PLUS", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression MINUS expression {
      Tree * temp = new Tree("MINUS", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression TIMES expression {
      Tree * temp = new Tree("TIMES", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression DIVIDEDBY expression {
      Tree * temp = new Tree("DIVIDEDBY", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression INTDIVIDEDBY expression {
      Tree * temp = new Tree("INTDIVIDEDBY", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression MOD expression {
      Tree * temp = new Tree("MOD", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression EXPO expression {
      Tree * temp = new Tree("EXPO", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression EQ expression {
      Tree * temp = new Tree("EQ", "");
      temp->child.push_back($1);
      temp->child.push_back($3);      
      $$ = temp;
     }
  | expression NEQ expression {
      Tree * temp = new Tree("NEQ", "");
      temp->child.push_back($1);
      temp->child.push_back($3);      
      $$ = temp;
     }
  | expression GT expression {
      Tree * temp = new Tree("GT", "");
      temp->child.push_back($1);
      temp->child.push_back($3);
      $$ = temp;
     }
  | expression GTE expression {
      Tree * temp = new Tree("GTE", "");
      temp->child.push_back($1);
      temp->child.push_back($3);      
      $$ = temp;
     }
  | expression LT expression {
      Tree * temp = new Tree("LT", "");
      temp->child.push_back($1);
      temp->child.push_back($3);      
      $$ = temp;
     }
  | expression LTE expression {
      Tree * temp = new Tree("LTE", "");
      temp->child.push_back($1);
      temp->child.push_back($3);      
      $$ = temp;
     }
  ;

negated_expression
  : NOT primary_expression {
      Tree * temp = new Tree("NOT", NULL);
      temp->child.push_back($2);
      $$ = temp;
    }
  ;

primary_expression
  : IDENTIFIER {
      Tree * temp = new Tree("IDENTIFIER", *$1);
      $$ = temp;
    }
  | DECIMAL {
      Tree * temp = new Tree("DECIMAL", *$1);
      $$ = temp;
    }
  | NUMBER {
      Tree * temp = new Tree("NUMBER", *$1);
      $$ = temp;
    }
  | BOOLEAN {
      Tree * temp = new Tree("BOOLEAN", *translate_boolean_str($1));
      $$ = temp;
    }
  | LPAREN expression RPAREN {
      Tree * temp = new Tree("PARENTHESES", "");
      temp->child.push_back($2);
      $$ = temp;
    }
  ;

%%

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

