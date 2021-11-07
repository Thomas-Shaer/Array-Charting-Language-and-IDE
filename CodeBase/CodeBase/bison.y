%require "3.2"
%define parse.error verbose 
%param { yyscan_t scanner }
%parse-param { BlockNode** inputnode}
%language "c++"
%define api.value.type variant
%define parse.trace
%token-table

%{

    #include <string>
    #include <vector>
    class NumberNode;
    class BooleanNode;
    class Expression;
    class Statement;
    class Node;
    class BinaryOpNode;
    class BlockNode;
    class AssignNode;
    class IdentifierNode;
    class MethodCallNode;
	#include "node.h"

%}

%code requires {
  typedef void* yyscan_t;
}

%code provides {
      #define YY_DECL \
        int yylex(yy::parser::semantic_type* value, yyscan_t yyscanner)
	YY_DECL;
    std::string token_name(int t);
 
}


%token <std::string> TNUMBER TIDENTIFIER
%token <int> TPLUS "+" TMINUS "-" TMUL "*" TDIV "/" TASSIGN "=" 
%token <int> TLESS "<" TLESSEQUAL "<=" TGREATER ">" TGREATEREQUAL ">=" TAND "&&" TOR "||" TNOT "!"
%token <int> TOPENBRACKET "(" TCLOSEBRACKET ")" TCOMMA ","
%token <int> TTRUE "TRUE" TFALSE "FALSE"



%type <int> binop unop
%type <Expression*> expr
%type <BlockNode*> stmts
%type <Statement*> stmt
%type <NumberNode*> numeric
%type <BooleanNode*> boolean
%type <BlockNode*> block;
%type <AssignNode*> assign;
%type <IdentifierNode*> identifier;
%type <MethodCallNode*> method;
%type <std::vector<Expression*>> call_params


%%

program : stmts { 
				   *inputnode = $1;
				}
        ;

stmts : stmt { $$ = new BlockNode(); $$->statementNodes.push_back($1); }
      | stmts stmt { $1->statementNodes.push_back($2); $$ = $1; }
	  | /*blank*/ { $$ = new BlockNode(); }
      ;

stmt : assign {$$ = $1;}
     ;

identifier : TIDENTIFIER {$$ = new IdentifierNode($1);}
           ;


assign : TIDENTIFIER TASSIGN expr {$$ = new AssignNode($1, $3);}
       ;

expr : numeric { $$ = $1; }
     | boolean {$$=$1;}
     | method {$$=$1;}
     | identifier {$$ = $1; }
     | expr binop expr {$$ =  new MethodCallNode("binary_operator" + token_name($2), {$1, $3}); }
     | unop expr {$$ =  new MethodCallNode("unary_operator" + token_name($1), {$2}); }
     ;

binop : TMUL | TDIV | TPLUS | TMINUS | TLESS | TLESSEQUAL | TGREATER | TGREATEREQUAL | TAND | TOR
      ;

unop : TPLUS | TMINUS | TNOT
      ;

numeric : TNUMBER { $$ = new NumberNode(atoi($1.c_str())); }
        ;

boolean : TFALSE { $$ = new BooleanNode(false); }
        | TTRUE { $$ = new BooleanNode(true); }
        ;

method : TIDENTIFIER TOPENBRACKET call_params TCLOSEBRACKET {$$ = new MethodCallNode($1, $3);}
       ;

call_params : /*blank*/  { $$ = std::vector<Expression*>(); }
          | expr { $$ = std::vector<Expression*>(); $$.push_back($1); }
          | call_params TCOMMA expr { $1.push_back($3); $$ = $1; }
          ;

%%
void yy::parser::error( const std::string& msg) {
    std::cout << msg << std::endl;
}



std::string token_name(int t) {
    return yy::parser::symbol_name(yy::parser::by_kind((yy::parser::token_type)t).type_get());
}

