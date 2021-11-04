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

#include "bison.tab.h"

#include <iostream>
#include <string>
#include "node.h"


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
"="                     value->emplace<int>(yy::parser::token::TASSIGN); return yy::parser::token::TASSIGN;
.                       return yytext[0];
%%

