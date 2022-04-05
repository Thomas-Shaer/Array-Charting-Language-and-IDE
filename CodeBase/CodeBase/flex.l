%option noyywrap noinput nounput
%option nodefault
%option nounistd
%option reentrant
 

%{

    #include <map>
    class Expression;
    class Statement;
    class BooleanNode;
    class StringNode;
    class KeywordNode;

    class BlockNode;
    class NumberNode;
    class Node;
    class BinaryOpNode;
    class AssignNode;
    class IdentifierNode;
    class MethodCallNode;
    class ExpressionStatementNode;
    class IfStatementNode;
    class TernaryNode;



#include "bison.tab.h"

#include <iostream>
#include <string>
#include "node.h"


#define YY_USER_ACTION \
    location->begin.line = location->end.line; \
    location->begin.column = location->end.column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            location->end.line++; \
            location->end.column = 0; \
        } \
        else if(yytext[i] == '\t') { \
            location->end.column += 4; \
        } \
        else { \
            location->end.column++; \
        } \
    }

%}

 

%x SINGLE_LINE_COMMENT
%x SINGLE_STRING

%%
\"                          BEGIN(SINGLE_STRING);
<SINGLE_STRING>{
  \n                        {}
  <<EOF>>                   {return yytext[0];}
  ([^\\\"]|\\.)*            {value->emplace<std::string>(yytext); return yy::parser::token::TSTRING;}
  \"                        BEGIN(INITIAL);
  .                         ;
}

"//"                              { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>"\n"         { BEGIN(INITIAL); }
<SINGLE_LINE_COMMENT>\n			  { }
<SINGLE_LINE_COMMENT>.			  { }
" "                     { }
[\n]                    { }
[\t]                    { }
"and"                   value->emplace<int>(yy::parser::token::TAND); return yy::parser::token::TAND;
"or"                    value->emplace<int>(yy::parser::token::TOR); return yy::parser::token::TOR;
"not"                   value->emplace<int>(yy::parser::token::TNOT); return yy::parser::token::TNOT;
"if"                    value->emplace<int>(yy::parser::token::TIF); return yy::parser::token::TIF;
"true"                  value->emplace<int>(yy::parser::token::TTRUE); return yy::parser::token::TTRUE;
"false"                 value->emplace<int>(yy::parser::token::TFALSE); return yy::parser::token::TFALSE;
"{"                     value->emplace<int>(yy::parser::token::TOPENBLOCK); return yy::parser::token::TOPENBLOCK;
"}"                     value->emplace<int>(yy::parser::token::TCLOSEBLOCK); return yy::parser::token::TCLOSEBLOCK;
[a-zA-Z_][a-zA-Z0-9_]*  value->emplace<std::string>(yytext); return yy::parser::token::TIDENTIFIER;
[0-9]+                  value->emplace<std::string>(yytext); return yy::parser::token::TNUMBER;
[0-9]+\.[0-9]*          value->emplace<std::string>(yytext); return yy::parser::token::TFLOAT;

"+="                    value->emplace<int>(yy::parser::token::TPLUSASSIGN); return yy::parser::token::TPLUSASSIGN;
"-="                    value->emplace<int>(yy::parser::token::TMINUSASSIGN); return yy::parser::token::TMINUSASSIGN;
"*="                    value->emplace<int>(yy::parser::token::TMULASSIGN); return yy::parser::token::TMULASSIGN;
"/="                    value->emplace<int>(yy::parser::token::TDIVASSIGN); return yy::parser::token::TDIVASSIGN;
"^="                    value->emplace<int>(yy::parser::token::TPOWASSIGN); return yy::parser::token::TPOWASSIGN;
"%="                    value->emplace<int>(yy::parser::token::TMODASSIGN); return yy::parser::token::TMODASSIGN;

"+"                     value->emplace<int>(yy::parser::token::TPLUS); return yy::parser::token::TPLUS;
"-"                     value->emplace<int>(yy::parser::token::TMINUS); return yy::parser::token::TMINUS;
"^"                     value->emplace<int>(yy::parser::token::TPOW); return yy::parser::token::TPOW;
"%"                     value->emplace<int>(yy::parser::token::TMOD); return yy::parser::token::TMOD;
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

"?"                     value->emplace<int>(yy::parser::token::TQUESTIONMARK); return yy::parser::token::TQUESTIONMARK;
":"                     value->emplace<int>(yy::parser::token::TCOLON); return yy::parser::token::TCOLON;




"="                     value->emplace<int>(yy::parser::token::TASSIGN); return yy::parser::token::TASSIGN;
.                       return yytext[0];
%%

