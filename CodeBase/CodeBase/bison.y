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
    class ExpressionStatementNode;
    class IfStatementNode;
    class StringNode;
    class TernaryNode;
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


%token <std::string> TNUMBER TIDENTIFIER TFLOAT TSTRING
%token <int> TPLUS "+" TMINUS "-" TMUL "*" TDIV "/" TASSIGN "=" TPOW "^" TMOD "%"
%token <int> TLESS "<" TLESSEQUAL "<=" TGREATER ">" TGREATEREQUAL ">=" TAND "&&" TOR "||" TNOT "!" TNOTEQUAL "!=" TEQUAL "=="
%token <int> TOPENBRACKET "(" TCLOSEBRACKET ")" TCOMMA ","
%token <int> TTRUE "TRUE" TFALSE "FALSE"
%token <int> TIF "if" TOPENBLOCK "{" TCLOSEBLOCK "}"
%token <int> TCOLON ":" TQUESTIONMARK "?"


%type <Expression*> expr
%type <BlockNode*> stmts
%type <Statement*> stmt
%type <IfStatementNode*> ifstmt
%type <NumberNode*> numeric
%type <BooleanNode*> boolean
%type <BlockNode*> block;
%type <AssignNode*> assign;
%type <IdentifierNode*> identifier;
%type <MethodCallNode*> method;
%type <ExpressionStatementNode*> exprstmt;
%type <TernaryNode*> ternary;
%type <StringNode*> string;
%type <std::vector<Expression*>> call_params


%right TQUESTIONMARK
%left TOR
%left TAND
%left TEQUAL TNOTEQUAL
%left TLESS TLESSEQUAL TGREATER TGREATEREQUAL
%left TPLUS TMINUS
%left TMUL TDIV
%left TOPENBRACKET TCLOSEBRACKET

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
     | exprstmt {$$ = $1;}
     | ifstmt {$$ = $1;}
     ;

exprstmt : method {$$ = new ExpressionStatementNode($1);}
         | ternary {$$ = new ExpressionStatementNode($1);}
         ;

ifstmt : TIF TOPENBRACKET expr TCLOSEBRACKET TOPENBLOCK stmts TCLOSEBLOCK { 
										$$ = new IfStatementNode($3, $6);
									  }
       ;

identifier : TIDENTIFIER {$$ = new IdentifierNode($1);}
           ;


assign : TIDENTIFIER TASSIGN expr {$$ = new AssignNode($1, $3);}
       ;

expr : numeric { $$ = $1; }
     | boolean {$$=$1;}
     | string {$$=$1;}
     | method {$$=$1;}
     | identifier {$$ = $1; }
     | TOPENBRACKET expr TCLOSEBRACKET {$$ = $2; }
     | ternary {$$ =  $1; }
     | expr TMUL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TDIV expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TPLUS expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TMINUS expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TLESS expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TPOW expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TMOD expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TLESSEQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TGREATER expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TGREATEREQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TNOTEQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TEQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TOR expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | expr TAND expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}); }
     | TPLUS expr {$$ =  new MethodCallNode("operator" + token_name($1), {$2}); }
     | TMINUS expr {$$ =  new MethodCallNode("operator" + token_name($1), {$2}); }
     | TNOT expr {$$ =  new MethodCallNode("operator" + token_name($1), {$2}); }
     ;

ternary : expr TQUESTIONMARK expr TCOLON expr { $$ = new TernaryNode($1, $3, $5); }
        ;


numeric : TNUMBER { $$ = new NumberNode(atoi($1.c_str())); }
        | TFLOAT { $$ = new NumberNode(atof($1.c_str())); }
        ;

boolean : TFALSE { $$ = new BooleanNode(false); }
        | TTRUE { $$ = new BooleanNode(true); }
        ;

string : TSTRING { $$ = new StringNode($1.c_str());}
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

