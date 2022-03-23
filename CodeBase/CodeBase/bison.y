%require "3.2"
%define parse.error verbose 
%param { yyscan_t scanner }
%parse-param { std::string* errorReturn}
%parse-param { BlockNode** inputnode}
%language "c++"
%define api.value.type variant
%parse-param { yy::SourceLocation** errorLocation}
%define api.location.type {yy::SourceLocation}

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
    class KeywordNode;
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
  #include "sourcelocation.h"
  typedef void* yyscan_t;
}

%code provides {
      #define YY_DECL \
        int yylex(yy::parser::semantic_type* value, yy::parser::location_type* location,  yyscan_t yyscanner)
	YY_DECL;
    std::string token_name(int t);
    static std::map<const int, const int> assign_op_converter({
	 {yy::parser::token::TPLUSASSIGN, yy::parser::token::TPLUS},
	 {yy::parser::token::TMINUSASSIGN, yy::parser::token::TMINUS},
	 {yy::parser::token::TMULASSIGN, yy::parser::token::TMUL},
	 {yy::parser::token::TDIVASSIGN, yy::parser::token::TDIV},
	 {yy::parser::token::TPOWASSIGN, yy::parser::token::TPOW},
	 {yy::parser::token::TMODASSIGN, yy::parser::token::TMOD}
	
	});
 
}


%token <std::string> TNUMBER TIDENTIFIER TFLOAT TSTRING
%token <int> TPLUS "+" TMINUS "-" TMUL "*" TDIV "/" TASSIGN "=" TPOW "^" TMOD "%"
%token <int> TLESS "<" TLESSEQUAL "<=" TGREATER ">" TGREATEREQUAL ">=" TAND "&&" TOR "||" TNOT "!" TNOTEQUAL "!=" TEQUAL "=="
%token <int> TPLUSASSIGN "+=" TMINUSASSIGN "-=" TMULASSIGN "*=" TDIVASSIGN "/=" TMODASSIGN "%=" TPOWASSIGN "^="
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
%type <KeywordNode*> keyword;
%type <MethodCallNode*> method;
%type <ExpressionStatementNode*> exprstmt;
%type <TernaryNode*> ternary;
%type <StringNode*> string;
%type <std::vector<Expression*>> call_params
%type <std::vector<Expression*>> call_params_keywords
%type <int> assignoptokens

%left TQUESTIONMARK
%left TOR
%left TAND
%left TEQUAL TNOTEQUAL
%left TLESS TLESSEQUAL TGREATER TGREATEREQUAL
%left TPLUS TMINUS
%left TMUL TDIV
%left TNOT
%left TOPENBRACKET TCLOSEBRACKET


%%

program : stmts { 
				   *inputnode = $1;
				}
        ;

stmts : stmt { $$ = new BlockNode(yy::SourceLocation()); $$->statementNodes.push_back($1); }
      | stmts stmt { $1->statementNodes.push_back($2); $$ = $1; }
	  | /*blank*/ { $$ = new BlockNode(yy::SourceLocation()); }
      ;

stmt : assign {$$ = $1;}
     | exprstmt {$$ = $1;}
     | ifstmt {$$ = $1;}
     ;

exprstmt : method {$$ = new ExpressionStatementNode($1, $1->sourceLocation);}
         | ternary {$$ = new ExpressionStatementNode($1, $1->sourceLocation);}
         ;

ifstmt : TIF TOPENBRACKET expr TCLOSEBRACKET TOPENBLOCK stmts TCLOSEBLOCK { 
										$$ = new IfStatementNode($3, $6, @1 + @7);
									  }
       ;

identifier : TIDENTIFIER {$$ = new IdentifierNode($1, @1);}
           ;

assignoptokens : TPLUSASSIGN | TMINUSASSIGN | TMULASSIGN | TDIVASSIGN | TMODASSIGN | TPOWASSIGN
			   ;

assign : TIDENTIFIER TASSIGN expr {$$ = new AssignNode($1, $3, @1 + $3->sourceLocation);}
       | TIDENTIFIER assignoptokens expr {$$ = new AssignNode($1, 
												new MethodCallNode("operator" + token_name(assign_op_converter.at($2)),
													{ new IdentifierNode($1, @1), $3},
													@1 + $3->sourceLocation),
										@1 + $3->sourceLocation);
									  }
       ;

expr : numeric { $$ = $1; }
     | boolean {$$=$1;}
     | string {$$=$1;}
     | method {$$=$1;}
     | identifier {$$ = $1; }
     | TOPENBRACKET expr TCLOSEBRACKET {$$ = $2; }
     | ternary {$$ =  $1; }
     | expr TMUL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3},  $1->sourceLocation + $3->sourceLocation); }
     | expr TDIV expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TPLUS expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TMINUS expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TLESS expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TPOW expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TMOD expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TLESSEQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TGREATER expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TGREATEREQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TNOTEQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TEQUAL expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TOR expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | expr TAND expr {$$ =  new MethodCallNode("operator" + token_name($2), {$1, $3}, $1->sourceLocation + $3->sourceLocation); }
     | TPLUS expr {$$ =  new MethodCallNode("operator" + token_name($1), {$2}, @1 + $2->sourceLocation); }
     | TMINUS expr {$$ =  new MethodCallNode("operator" + token_name($1), {$2}, @1 + $2->sourceLocation); }
     | TNOT expr {$$ =  new MethodCallNode("operator" + token_name($1), {$2}, @1 + $2->sourceLocation); }
     ;

keyword : TIDENTIFIER TASSIGN expr {$$ = new KeywordNode($1, $3, @1 + $3->sourceLocation);}
       ;

ternary : expr TQUESTIONMARK expr TCOLON expr { $$ = new TernaryNode($1, $3, $5, $1->sourceLocation + $3->sourceLocation); }
        ;


numeric : TNUMBER { $$ = new NumberNode(atoi($1.c_str()), @1); }
        | TFLOAT { $$ = new NumberNode(atof($1.c_str()), @1); }
        ;

boolean : TFALSE { $$ = new BooleanNode(false, @1); }
        | TTRUE { $$ = new BooleanNode(true, @1); }
        ;

string : TSTRING { $$ = new StringNode($1.c_str(), @1);}
       ;


method : TIDENTIFIER TOPENBRACKET /*blank*/ TCLOSEBRACKET {$$ = new MethodCallNode($1, std::vector<Expression*>(), @1 + @3);}
       | TIDENTIFIER TOPENBRACKET call_params TCLOSEBRACKET {$$ = new MethodCallNode($1, $3, @1 + @4);}
       | TIDENTIFIER TOPENBRACKET call_params_keywords TCLOSEBRACKET {$$ = new MethodCallNode($1, $3, @1 + @4);}
       ;



call_params : expr { $$ = std::vector<Expression*>(); $$.push_back($1); }
            | call_params TCOMMA expr { $1.push_back($3); $$ = $1; }
            | call_params TCOMMA call_params_keywords { 
                std::vector<Expression*> combinedParamList = $1;
                std::vector<Expression*> newParamList = $3;
                combinedParamList.insert(combinedParamList.end(), newParamList.begin(), newParamList.end());
                $$ = combinedParamList;
              }
            ;

call_params_keywords : keyword { $$ = std::vector<Expression*>(); $$.push_back($1); }
                     | call_params_keywords TCOMMA keyword { $1.push_back($3); $$ = $1; }
                     ;



%%
void yy::parser::error(const location_type &l,  const std::string& msg) {
    **errorLocation = l;
    *errorReturn = msg;
}



std::string token_name(int t) {
    return yy::parser::symbol_name(yy::parser::by_kind((yy::parser::token_type)t).type_get());
}

