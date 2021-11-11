%option noyywrap noinput nounput
%option nodefault
%option nounistd
%option reentrant
 

%{
    class Expression;
    class Statement;
    class BooleanNode;

    class BlockNode;
    class NumberNode;
    class Node;
    class BinaryOpNode;
    class AssignNode;
    class IdentifierNode;
    class MethodCallNode;
    class ExpressionStatementNode;


#include "bison.tab.h"

#include <iostream>
#include <string>
#include "node.h"

/*

"=="                    value->emplace<int>(yy::parser::token::TCEQUAL); return yy::parser::token::TCEQUAL;
"!="                    value->emplace<int>(yy::parser::token::TCNE); return yy::parser::token::TCNE;
*/

%}

 
%%

" "                     { }
[\n]                    { }
[\t]                    { }
"true"                  value->emplace<int>(yy::parser::token::TTRUE); return yy::parser::token::TTRUE;
"false"                 value->emplace<int>(yy::parser::token::TFALSE); return yy::parser::token::TFALSE;
[a-zA-Z_][a-zA-Z0-9_]*  value->emplace<std::string>(yytext); return yy::parser::token::TIDENTIFIER;
[0-9]+                  value->emplace<std::string>(yytext); return yy::parser::token::TNUMBER;
[0-9]+\.[0-9]*          value->emplace<std::string>(yytext); return yy::parser::token::TNUMBER;
"+"                     value->emplace<int>(yy::parser::token::TPLUS); return yy::parser::token::TPLUS;
"-"                     value->emplace<int>(yy::parser::token::TMINUS); return yy::parser::token::TMINUS;
"*"                     value->emplace<int>(yy::parser::token::TMUL); return yy::parser::token::TMUL;
"/"                     value->emplace<int>(yy::parser::token::TDIV); return yy::parser::token::TDIV;
"<"                     value->emplace<int>(yy::parser::token::TLESS); return yy::parser::token::TLESS;
"<="                    value->emplace<int>(yy::parser::token::TLESSEQUAL); return yy::parser::token::TLESSEQUAL;
">"                     value->emplace<int>(yy::parser::token::TGREATER); return yy::parser::token::TGREATER;
">="                    value->emplace<int>(yy::parser::token::TGREATEREQUAL); return yy::parser::token::TGREATEREQUAL;
"&&"                    value->emplace<int>(yy::parser::token::TAND); return yy::parser::token::TAND;
"||"                    value->emplace<int>(yy::parser::token::TOR); return yy::parser::token::TOR;
"!="                    value->emplace<int>(yy::parser::token::TNOTEQUAL); return yy::parser::token::TNOTEQUAL;
"=="                    value->emplace<int>(yy::parser::token::TEQUAL); return yy::parser::token::TEQUAL;

"!"                     value->emplace<int>(yy::parser::token::TNOT); return yy::parser::token::TNOT;
"("                     value->emplace<int>(yy::parser::token::TOPENBRACKET); return yy::parser::token::TOPENBRACKET;
")"                     value->emplace<int>(yy::parser::token::TCLOSEBRACKET); return yy::parser::token::TCLOSEBRACKET;
","                     value->emplace<int>(yy::parser::token::TCOMMA); return yy::parser::token::TCOMMA;



"="                     value->emplace<int>(yy::parser::token::TASSIGN); return yy::parser::token::TASSIGN;
.                       return yytext[0];
%%

