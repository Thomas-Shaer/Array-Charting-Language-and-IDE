// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 14 "bison.y"

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

#line 63 "bison.tab.cpp"


#include "bison.tab.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 160 "bison.tab.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t scanner_yyarg, std::string* errorReturn_yyarg, BlockNode** inputnode_yyarg, yy::SourceLocation** errorLocation_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      errorReturn (errorReturn_yyarg),
      inputnode (inputnode_yyarg),
      errorLocation (errorLocation_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_assign: // assign
        value.copy< AssignNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.copy< BlockNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean: // boolean
        value.copy< BooleanNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.copy< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.copy< ExpressionStatementNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.copy< IdentifierNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.copy< IfStatementNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword: // keyword
        value.copy< KeywordNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_method: // method
        value.copy< MethodCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.copy< NumberNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string: // string
        value.copy< StringNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ternary: // ternary
        value.copy< TernaryNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TPOW: // "^"
      case symbol_kind::S_TMOD: // "%"
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TPLUSASSIGN: // "+="
      case symbol_kind::S_TMINUSASSIGN: // "-="
      case symbol_kind::S_TMULASSIGN: // "*="
      case symbol_kind::S_TDIVASSIGN: // "/="
      case symbol_kind::S_TMODASSIGN: // "%="
      case symbol_kind::S_TPOWASSIGN: // "^="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
      case symbol_kind::S_TIF: // "if"
      case symbol_kind::S_TOPENBLOCK: // "{"
      case symbol_kind::S_TCLOSEBLOCK: // "}"
      case symbol_kind::S_TCOLON: // ":"
      case symbol_kind::S_TQUESTIONMARK: // "?"
      case symbol_kind::S_assignoptokens: // assignoptokens
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_call_params_keywords: // call_params_keywords
        value.copy< std::vector<Expression*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< BlockNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_boolean: // boolean
        value.move< BooleanNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< Expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.move< ExpressionStatementNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< IdentifierNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.move< IfStatementNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_keyword: // keyword
        value.move< KeywordNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_method: // method
        value.move< MethodCallNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.move< NumberNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< Statement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_string: // string
        value.move< StringNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ternary: // ternary
        value.move< TernaryNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TPOW: // "^"
      case symbol_kind::S_TMOD: // "%"
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TPLUSASSIGN: // "+="
      case symbol_kind::S_TMINUSASSIGN: // "-="
      case symbol_kind::S_TMULASSIGN: // "*="
      case symbol_kind::S_TDIVASSIGN: // "/="
      case symbol_kind::S_TMODASSIGN: // "%="
      case symbol_kind::S_TPOWASSIGN: // "^="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
      case symbol_kind::S_TIF: // "if"
      case symbol_kind::S_TOPENBLOCK: // "{"
      case symbol_kind::S_TCLOSEBLOCK: // "}"
      case symbol_kind::S_TCOLON: // ":"
      case symbol_kind::S_TQUESTIONMARK: // "?"
      case symbol_kind::S_assignoptokens: // assignoptokens
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_call_params_keywords: // call_params_keywords
        value.move< std::vector<Expression*> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assign: // assign
        value.YY_MOVE_OR_COPY< AssignNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.YY_MOVE_OR_COPY< BlockNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean: // boolean
        value.YY_MOVE_OR_COPY< BooleanNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.YY_MOVE_OR_COPY< ExpressionStatementNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.YY_MOVE_OR_COPY< IfStatementNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword: // keyword
        value.YY_MOVE_OR_COPY< KeywordNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_method: // method
        value.YY_MOVE_OR_COPY< MethodCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.YY_MOVE_OR_COPY< NumberNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string: // string
        value.YY_MOVE_OR_COPY< StringNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ternary: // ternary
        value.YY_MOVE_OR_COPY< TernaryNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TPOW: // "^"
      case symbol_kind::S_TMOD: // "%"
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TPLUSASSIGN: // "+="
      case symbol_kind::S_TMINUSASSIGN: // "-="
      case symbol_kind::S_TMULASSIGN: // "*="
      case symbol_kind::S_TDIVASSIGN: // "/="
      case symbol_kind::S_TMODASSIGN: // "%="
      case symbol_kind::S_TPOWASSIGN: // "^="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
      case symbol_kind::S_TIF: // "if"
      case symbol_kind::S_TOPENBLOCK: // "{"
      case symbol_kind::S_TCLOSEBLOCK: // "}"
      case symbol_kind::S_TCOLON: // ":"
      case symbol_kind::S_TQUESTIONMARK: // "?"
      case symbol_kind::S_assignoptokens: // assignoptokens
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_call_params_keywords: // call_params_keywords
        value.YY_MOVE_OR_COPY< std::vector<Expression*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< BlockNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean: // boolean
        value.move< BooleanNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.move< ExpressionStatementNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< IdentifierNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.move< IfStatementNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword: // keyword
        value.move< KeywordNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_method: // method
        value.move< MethodCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.move< NumberNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string: // string
        value.move< StringNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ternary: // ternary
        value.move< TernaryNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TPOW: // "^"
      case symbol_kind::S_TMOD: // "%"
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TPLUSASSIGN: // "+="
      case symbol_kind::S_TMINUSASSIGN: // "-="
      case symbol_kind::S_TMULASSIGN: // "*="
      case symbol_kind::S_TDIVASSIGN: // "/="
      case symbol_kind::S_TMODASSIGN: // "%="
      case symbol_kind::S_TPOWASSIGN: // "^="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
      case symbol_kind::S_TIF: // "if"
      case symbol_kind::S_TOPENBLOCK: // "{"
      case symbol_kind::S_TCLOSEBLOCK: // "}"
      case symbol_kind::S_TCOLON: // ":"
      case symbol_kind::S_TQUESTIONMARK: // "?"
      case symbol_kind::S_assignoptokens: // assignoptokens
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_call_params_keywords: // call_params_keywords
        value.move< std::vector<Expression*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assign: // assign
        value.copy< AssignNode* > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.copy< BlockNode* > (that.value);
        break;

      case symbol_kind::S_boolean: // boolean
        value.copy< BooleanNode* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.copy< Expression* > (that.value);
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.copy< ExpressionStatementNode* > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.copy< IdentifierNode* > (that.value);
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.copy< IfStatementNode* > (that.value);
        break;

      case symbol_kind::S_keyword: // keyword
        value.copy< KeywordNode* > (that.value);
        break;

      case symbol_kind::S_method: // method
        value.copy< MethodCallNode* > (that.value);
        break;

      case symbol_kind::S_numeric: // numeric
        value.copy< NumberNode* > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< Statement* > (that.value);
        break;

      case symbol_kind::S_string: // string
        value.copy< StringNode* > (that.value);
        break;

      case symbol_kind::S_ternary: // ternary
        value.copy< TernaryNode* > (that.value);
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TPOW: // "^"
      case symbol_kind::S_TMOD: // "%"
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TPLUSASSIGN: // "+="
      case symbol_kind::S_TMINUSASSIGN: // "-="
      case symbol_kind::S_TMULASSIGN: // "*="
      case symbol_kind::S_TDIVASSIGN: // "/="
      case symbol_kind::S_TMODASSIGN: // "%="
      case symbol_kind::S_TPOWASSIGN: // "^="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
      case symbol_kind::S_TIF: // "if"
      case symbol_kind::S_TOPENBLOCK: // "{"
      case symbol_kind::S_TCLOSEBLOCK: // "}"
      case symbol_kind::S_TCOLON: // ":"
      case symbol_kind::S_TQUESTIONMARK: // "?"
      case symbol_kind::S_assignoptokens: // assignoptokens
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_call_params_keywords: // call_params_keywords
        value.copy< std::vector<Expression*> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (that.value);
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< BlockNode* > (that.value);
        break;

      case symbol_kind::S_boolean: // boolean
        value.move< BooleanNode* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.move< Expression* > (that.value);
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.move< ExpressionStatementNode* > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< IdentifierNode* > (that.value);
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.move< IfStatementNode* > (that.value);
        break;

      case symbol_kind::S_keyword: // keyword
        value.move< KeywordNode* > (that.value);
        break;

      case symbol_kind::S_method: // method
        value.move< MethodCallNode* > (that.value);
        break;

      case symbol_kind::S_numeric: // numeric
        value.move< NumberNode* > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< Statement* > (that.value);
        break;

      case symbol_kind::S_string: // string
        value.move< StringNode* > (that.value);
        break;

      case symbol_kind::S_ternary: // ternary
        value.move< TernaryNode* > (that.value);
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TPOW: // "^"
      case symbol_kind::S_TMOD: // "%"
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TPLUSASSIGN: // "+="
      case symbol_kind::S_TMINUSASSIGN: // "-="
      case symbol_kind::S_TMULASSIGN: // "*="
      case symbol_kind::S_TDIVASSIGN: // "/="
      case symbol_kind::S_TMODASSIGN: // "%="
      case symbol_kind::S_TPOWASSIGN: // "^="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
      case symbol_kind::S_TIF: // "if"
      case symbol_kind::S_TOPENBLOCK: // "{"
      case symbol_kind::S_TCLOSEBLOCK: // "}"
      case symbol_kind::S_TCOLON: // ":"
      case symbol_kind::S_TQUESTIONMARK: // "?"
      case symbol_kind::S_assignoptokens: // assignoptokens
        value.move< int > (that.value);
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_call_params_keywords: // call_params_keywords
        value.move< std::vector<Expression*> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_assign: // assign
        yylhs.value.emplace< AssignNode* > ();
        break;

      case symbol_kind::S_stmts: // stmts
        yylhs.value.emplace< BlockNode* > ();
        break;

      case symbol_kind::S_boolean: // boolean
        yylhs.value.emplace< BooleanNode* > ();
        break;

      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< Expression* > ();
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        yylhs.value.emplace< ExpressionStatementNode* > ();
        break;

      case symbol_kind::S_identifier: // identifier
        yylhs.value.emplace< IdentifierNode* > ();
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        yylhs.value.emplace< IfStatementNode* > ();
        break;

      case symbol_kind::S_keyword: // keyword
        yylhs.value.emplace< KeywordNode* > ();
        break;

      case symbol_kind::S_method: // method
        yylhs.value.emplace< MethodCallNode* > ();
        break;

      case symbol_kind::S_numeric: // numeric
        yylhs.value.emplace< NumberNode* > ();
        break;

      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< Statement* > ();
        break;

      case symbol_kind::S_string: // string
        yylhs.value.emplace< StringNode* > ();
        break;

      case symbol_kind::S_ternary: // ternary
        yylhs.value.emplace< TernaryNode* > ();
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TPOW: // "^"
      case symbol_kind::S_TMOD: // "%"
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TPLUSASSIGN: // "+="
      case symbol_kind::S_TMINUSASSIGN: // "-="
      case symbol_kind::S_TMULASSIGN: // "*="
      case symbol_kind::S_TDIVASSIGN: // "/="
      case symbol_kind::S_TMODASSIGN: // "%="
      case symbol_kind::S_TPOWASSIGN: // "^="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
      case symbol_kind::S_TIF: // "if"
      case symbol_kind::S_TOPENBLOCK: // "{"
      case symbol_kind::S_TCLOSEBLOCK: // "}"
      case symbol_kind::S_TCOLON: // ":"
      case symbol_kind::S_TQUESTIONMARK: // "?"
      case symbol_kind::S_assignoptokens: // assignoptokens
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_call_params: // call_params
      case symbol_kind::S_call_params_keywords: // call_params_keywords
        yylhs.value.emplace< std::vector<Expression*> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: stmts
#line 100 "bison.y"
                { 
				   *inputnode = yystack_[0].value.as < BlockNode* > ();
				}
#line 1348 "bison.tab.cpp"
    break;

  case 3: // stmts: stmt
#line 105 "bison.y"
             { yylhs.value.as < BlockNode* > () = new BlockNode(yy::SourceLocation()); yylhs.value.as < BlockNode* > ()->statementNodes.push_back(yystack_[0].value.as < Statement* > ()); }
#line 1354 "bison.tab.cpp"
    break;

  case 4: // stmts: stmts stmt
#line 106 "bison.y"
                   { yystack_[1].value.as < BlockNode* > ()->statementNodes.push_back(yystack_[0].value.as < Statement* > ()); yylhs.value.as < BlockNode* > () = yystack_[1].value.as < BlockNode* > (); }
#line 1360 "bison.tab.cpp"
    break;

  case 5: // stmts: %empty
#line 107 "bison.y"
                      { yylhs.value.as < BlockNode* > () = new BlockNode(yy::SourceLocation()); }
#line 1366 "bison.tab.cpp"
    break;

  case 6: // stmt: assign
#line 110 "bison.y"
              {yylhs.value.as < Statement* > () = yystack_[0].value.as < AssignNode* > ();}
#line 1372 "bison.tab.cpp"
    break;

  case 7: // stmt: exprstmt
#line 111 "bison.y"
                {yylhs.value.as < Statement* > () = yystack_[0].value.as < ExpressionStatementNode* > ();}
#line 1378 "bison.tab.cpp"
    break;

  case 8: // stmt: ifstmt
#line 112 "bison.y"
              {yylhs.value.as < Statement* > () = yystack_[0].value.as < IfStatementNode* > ();}
#line 1384 "bison.tab.cpp"
    break;

  case 9: // exprstmt: method
#line 115 "bison.y"
                  {yylhs.value.as < ExpressionStatementNode* > () = new ExpressionStatementNode(yystack_[0].value.as < MethodCallNode* > (), yystack_[0].value.as < MethodCallNode* > ()->sourceLocation);}
#line 1390 "bison.tab.cpp"
    break;

  case 10: // exprstmt: ternary
#line 116 "bison.y"
                   {yylhs.value.as < ExpressionStatementNode* > () = new ExpressionStatementNode(yystack_[0].value.as < TernaryNode* > (), yystack_[0].value.as < TernaryNode* > ()->sourceLocation);}
#line 1396 "bison.tab.cpp"
    break;

  case 11: // ifstmt: "if" "(" expr ")" "{" stmts "}"
#line 119 "bison.y"
                                                                          { 
										yylhs.value.as < IfStatementNode* > () = new IfStatementNode(yystack_[4].value.as < Expression* > (), yystack_[1].value.as < BlockNode* > (), yystack_[6].location + yystack_[0].location);
									  }
#line 1404 "bison.tab.cpp"
    break;

  case 12: // identifier: TIDENTIFIER
#line 124 "bison.y"
                         {yylhs.value.as < IdentifierNode* > () = new IdentifierNode(yystack_[0].value.as < std::string > (), yystack_[0].location);}
#line 1410 "bison.tab.cpp"
    break;

  case 13: // assignoptokens: "+="
#line 127 "bison.y"
                 { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1416 "bison.tab.cpp"
    break;

  case 14: // assignoptokens: "-="
#line 127 "bison.y"
                               { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1422 "bison.tab.cpp"
    break;

  case 15: // assignoptokens: "*="
#line 127 "bison.y"
                                              { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1428 "bison.tab.cpp"
    break;

  case 16: // assignoptokens: "/="
#line 127 "bison.y"
                                                           { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1434 "bison.tab.cpp"
    break;

  case 17: // assignoptokens: "%="
#line 127 "bison.y"
                                                                        { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1440 "bison.tab.cpp"
    break;

  case 18: // assignoptokens: "^="
#line 127 "bison.y"
                                                                                     { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1446 "bison.tab.cpp"
    break;

  case 19: // assign: TIDENTIFIER "=" expr
#line 130 "bison.y"
                                  {yylhs.value.as < AssignNode* > () = new AssignNode(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Expression* > (), yystack_[2].location + yystack_[0].value.as < Expression* > ()->sourceLocation);}
#line 1452 "bison.tab.cpp"
    break;

  case 20: // assign: TIDENTIFIER assignoptokens expr
#line 131 "bison.y"
                                         {yylhs.value.as < AssignNode* > () = new AssignNode(yystack_[2].value.as < std::string > (), 
												new MethodCallNode("operator" + token_name(assign_op_converter.at(yystack_[1].value.as < int > ())),
													{ new IdentifierNode(yystack_[2].value.as < std::string > (), yystack_[2].location), yystack_[0].value.as < Expression* > ()},
													yystack_[2].location + yystack_[0].value.as < Expression* > ()->sourceLocation),
										yystack_[2].location + yystack_[0].value.as < Expression* > ()->sourceLocation);
									  }
#line 1463 "bison.tab.cpp"
    break;

  case 21: // expr: numeric
#line 139 "bison.y"
               { yylhs.value.as < Expression* > () = yystack_[0].value.as < NumberNode* > (); }
#line 1469 "bison.tab.cpp"
    break;

  case 22: // expr: boolean
#line 140 "bison.y"
               {yylhs.value.as < Expression* > ()=yystack_[0].value.as < BooleanNode* > ();}
#line 1475 "bison.tab.cpp"
    break;

  case 23: // expr: string
#line 141 "bison.y"
              {yylhs.value.as < Expression* > ()=yystack_[0].value.as < StringNode* > ();}
#line 1481 "bison.tab.cpp"
    break;

  case 24: // expr: method
#line 142 "bison.y"
              {yylhs.value.as < Expression* > ()=yystack_[0].value.as < MethodCallNode* > ();}
#line 1487 "bison.tab.cpp"
    break;

  case 25: // expr: identifier
#line 143 "bison.y"
                  {yylhs.value.as < Expression* > () = yystack_[0].value.as < IdentifierNode* > (); }
#line 1493 "bison.tab.cpp"
    break;

  case 26: // expr: "(" expr ")"
#line 144 "bison.y"
                                       {yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 1499 "bison.tab.cpp"
    break;

  case 27: // expr: ternary
#line 145 "bison.y"
               {yylhs.value.as < Expression* > () =  yystack_[0].value.as < TernaryNode* > (); }
#line 1505 "bison.tab.cpp"
    break;

  case 28: // expr: expr "*" expr
#line 146 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()},  yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1511 "bison.tab.cpp"
    break;

  case 29: // expr: expr "/" expr
#line 147 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1517 "bison.tab.cpp"
    break;

  case 30: // expr: expr "+" expr
#line 148 "bison.y"
                       {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1523 "bison.tab.cpp"
    break;

  case 31: // expr: expr "-" expr
#line 149 "bison.y"
                        {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1529 "bison.tab.cpp"
    break;

  case 32: // expr: expr "<" expr
#line 150 "bison.y"
                       {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1535 "bison.tab.cpp"
    break;

  case 33: // expr: expr "^" expr
#line 151 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1541 "bison.tab.cpp"
    break;

  case 34: // expr: expr "%" expr
#line 152 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1547 "bison.tab.cpp"
    break;

  case 35: // expr: expr "<=" expr
#line 153 "bison.y"
                            {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1553 "bison.tab.cpp"
    break;

  case 36: // expr: expr ">" expr
#line 154 "bison.y"
                          {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1559 "bison.tab.cpp"
    break;

  case 37: // expr: expr ">=" expr
#line 155 "bison.y"
                               {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1565 "bison.tab.cpp"
    break;

  case 38: // expr: expr "!=" expr
#line 156 "bison.y"
                           {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1571 "bison.tab.cpp"
    break;

  case 39: // expr: expr "==" expr
#line 157 "bison.y"
                        {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1577 "bison.tab.cpp"
    break;

  case 40: // expr: expr "||" expr
#line 158 "bison.y"
                     {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1583 "bison.tab.cpp"
    break;

  case 41: // expr: expr "&&" expr
#line 159 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}, yystack_[2].value.as < Expression* > ()->sourceLocation + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1589 "bison.tab.cpp"
    break;

  case 42: // expr: "+" expr
#line 160 "bison.y"
                  {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[0].value.as < Expression* > ()}, yystack_[1].location + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1595 "bison.tab.cpp"
    break;

  case 43: // expr: "-" expr
#line 161 "bison.y"
                   {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[0].value.as < Expression* > ()}, yystack_[1].location + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1601 "bison.tab.cpp"
    break;

  case 44: // expr: "!" expr
#line 162 "bison.y"
                 {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[0].value.as < Expression* > ()}, yystack_[1].location + yystack_[0].value.as < Expression* > ()->sourceLocation); }
#line 1607 "bison.tab.cpp"
    break;

  case 45: // keyword: TIDENTIFIER "=" expr
#line 165 "bison.y"
                                   {yylhs.value.as < KeywordNode* > () = new KeywordNode(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Expression* > (), yystack_[2].location + yystack_[0].value.as < Expression* > ()->sourceLocation);}
#line 1613 "bison.tab.cpp"
    break;

  case 46: // ternary: expr "?" expr ":" expr
#line 168 "bison.y"
                                              { yylhs.value.as < TernaryNode* > () = new TernaryNode(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > (), yystack_[4].value.as < Expression* > ()->sourceLocation + yystack_[2].value.as < Expression* > ()->sourceLocation); }
#line 1619 "bison.tab.cpp"
    break;

  case 47: // numeric: TNUMBER
#line 172 "bison.y"
                  { yylhs.value.as < NumberNode* > () = new NumberNode(atoi(yystack_[0].value.as < std::string > ().c_str()), yystack_[0].location); }
#line 1625 "bison.tab.cpp"
    break;

  case 48: // numeric: TFLOAT
#line 173 "bison.y"
                 { yylhs.value.as < NumberNode* > () = new NumberNode(atof(yystack_[0].value.as < std::string > ().c_str()), yystack_[0].location); }
#line 1631 "bison.tab.cpp"
    break;

  case 49: // boolean: "FALSE"
#line 176 "bison.y"
                 { yylhs.value.as < BooleanNode* > () = new BooleanNode(false, yystack_[0].location); }
#line 1637 "bison.tab.cpp"
    break;

  case 50: // boolean: "TRUE"
#line 177 "bison.y"
                { yylhs.value.as < BooleanNode* > () = new BooleanNode(true, yystack_[0].location); }
#line 1643 "bison.tab.cpp"
    break;

  case 51: // string: TSTRING
#line 180 "bison.y"
                 { yylhs.value.as < StringNode* > () = new StringNode(yystack_[0].value.as < std::string > ().c_str(), yystack_[0].location);}
#line 1649 "bison.tab.cpp"
    break;

  case 52: // method: TIDENTIFIER "(" ")"
#line 184 "bison.y"
                                                          {yylhs.value.as < MethodCallNode* > () = new MethodCallNode(yystack_[2].value.as < std::string > (), std::vector<Expression*>(), yystack_[2].location + yystack_[0].location);}
#line 1655 "bison.tab.cpp"
    break;

  case 53: // method: TIDENTIFIER "(" call_params ")"
#line 185 "bison.y"
                                                            {yylhs.value.as < MethodCallNode* > () = new MethodCallNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Expression*> > (), yystack_[3].location + yystack_[0].location);}
#line 1661 "bison.tab.cpp"
    break;

  case 54: // method: TIDENTIFIER "(" call_params_keywords ")"
#line 186 "bison.y"
                                                                     {yylhs.value.as < MethodCallNode* > () = new MethodCallNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Expression*> > (), yystack_[3].location + yystack_[0].location);}
#line 1667 "bison.tab.cpp"
    break;

  case 55: // call_params: expr
#line 191 "bison.y"
                   { yylhs.value.as < std::vector<Expression*> > () = std::vector<Expression*>(); yylhs.value.as < std::vector<Expression*> > ().push_back(yystack_[0].value.as < Expression* > ()); }
#line 1673 "bison.tab.cpp"
    break;

  case 56: // call_params: call_params "," expr
#line 192 "bison.y"
                                      { yystack_[2].value.as < std::vector<Expression*> > ().push_back(yystack_[0].value.as < Expression* > ()); yylhs.value.as < std::vector<Expression*> > () = yystack_[2].value.as < std::vector<Expression*> > (); }
#line 1679 "bison.tab.cpp"
    break;

  case 57: // call_params: call_params "," call_params_keywords
#line 193 "bison.y"
                                                      { 
                std::vector<Expression*> combinedParamList = yystack_[2].value.as < std::vector<Expression*> > ();
                std::vector<Expression*> newParamList = yystack_[0].value.as < std::vector<Expression*> > ();
                combinedParamList.insert(combinedParamList.end(), newParamList.begin(), newParamList.end());
                yylhs.value.as < std::vector<Expression*> > () = combinedParamList;
              }
#line 1690 "bison.tab.cpp"
    break;

  case 58: // call_params_keywords: keyword
#line 201 "bison.y"
                               { yylhs.value.as < std::vector<Expression*> > () = std::vector<Expression*>(); yylhs.value.as < std::vector<Expression*> > ().push_back(yystack_[0].value.as < KeywordNode* > ()); }
#line 1696 "bison.tab.cpp"
    break;

  case 59: // call_params_keywords: call_params_keywords "," keyword
#line 202 "bison.y"
                                                           { yystack_[2].value.as < std::vector<Expression*> > ().push_back(yystack_[0].value.as < KeywordNode* > ()); yylhs.value.as < std::vector<Expression*> > () = yystack_[2].value.as < std::vector<Expression*> > (); }
#line 1702 "bison.tab.cpp"
    break;


#line 1706 "bison.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -65;

  const signed char parser::yytable_ninf_ = -28;

  const short
  parser::yypact_[] =
  {
     170,   -65,    45,   -65,   -65,   202,   202,   202,   202,   -65,
     -65,    -6,    25,   170,   -65,   -65,   -65,   -65,   -65,   179,
     233,   -65,   -65,   -65,   247,   202,   -65,   -65,   -65,   -65,
     -65,   -65,     4,   202,    -2,   134,   -65,   -65,   134,     3,
      93,   202,   -65,   -65,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   179,
       6,   -65,   179,   -65,   -12,   -10,   179,   -65,   120,   134,
     134,     3,     3,   179,   179,   109,   109,   109,   109,   281,
     265,   297,   297,   147,   202,   -65,   208,   -65,    22,    -4,
     202,   179,   179,     8,    17,   -65,   170,   179,    56,   -65
  };

  const signed char
  parser::yydefact_[] =
  {
       5,    47,    12,    48,    51,     0,     0,     0,     0,    50,
      49,     0,     0,     2,     3,     7,     8,    25,     6,     0,
      10,    21,    22,    23,     9,     0,    13,    14,    15,    16,
      17,    18,     0,     0,    12,    42,    27,    24,    43,    44,
       0,     0,     1,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      12,    52,    55,    58,     0,     0,    20,    26,     0,    30,
      31,    28,    29,    33,    34,    32,    35,    36,    37,    41,
      40,    38,    39,     0,     0,    53,     0,    54,     0,     0,
       0,    45,    56,    57,     0,    59,     5,    46,     0,    11
  };

  const signed char
  parser::yypgoto_[] =
  {
     -65,   -65,   -64,    -7,   -65,   -65,   -65,   -65,   -65,    -3,
     -48,     0,   -65,   -65,   -65,     1,   -65,   -29
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,    33,    18,    19,
      63,    36,    21,    22,    23,    37,    64,    65
  };

  const signed char
  parser::yytable_[] =
  {
      20,    24,    35,    38,    39,    40,    43,     1,    60,     3,
       4,     5,     6,    20,    24,    48,    49,    84,    85,    86,
      87,    88,    59,    41,     7,    42,    94,    32,    84,    62,
      66,    96,    98,     8,    61,    32,     9,    10,    68,    88,
      95,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    25,    93,     0,     1,
       2,     3,     4,     5,     6,     0,     0,     0,    26,    27,
      28,    29,    30,    31,    32,     0,     7,     0,     0,     0,
       0,    91,     0,    92,     0,     8,     0,    97,     9,    10,
      11,    43,    99,     0,     0,     0,    20,    24,    20,    24,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,     0,    56,    57,    44,    45,    46,    47,
       0,    48,    49,    67,     0,     0,     0,    44,    45,    46,
      47,    58,    48,    49,    50,    51,    52,    53,    54,    55,
       0,    56,    57,    46,    47,     0,    48,    49,     0,     0,
      89,     0,     0,     0,    44,    45,    46,    47,    58,    48,
      49,    50,    51,    52,    53,    54,    55,     0,    56,    57,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     0,     0,    90,    58,    44,    45,    46,    47,
       7,    48,    49,    50,    51,    52,    53,    54,    55,     8,
      56,    57,     9,    10,    11,     1,    34,     3,     4,     5,
       6,     1,    60,     3,     4,     5,     6,    58,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     7,     0,
       0,     8,     0,     0,     9,    10,     0,     8,     0,     0,
       9,    10,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,     0,   -27,   -27,   -24,   -24,     0,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,
       0,   -27,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,     0,   -24,    56,    57,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,     0,
       0,     0,    56,    57,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,    53
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     0,     5,     6,     7,     8,    13,     3,     4,     5,
       6,     7,     8,    13,    13,    12,    13,    11,    30,    31,
      30,    31,    25,    29,    20,     0,     4,    29,    11,    32,
      33,    35,    96,    29,    30,    29,    32,    33,    41,    31,
      88,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    11,    86,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    20,    -1,    -1,    -1,
      -1,    84,    -1,    86,    -1,    29,    -1,    90,    32,    33,
      34,    98,    36,    -1,    -1,    -1,    96,    96,    98,    98,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,     7,     8,     9,    10,
      -1,    12,    13,    30,    -1,    -1,    -1,     7,     8,     9,
      10,    38,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,     9,    10,    -1,    12,    13,    -1,    -1,
      30,    -1,    -1,    -1,     7,     8,     9,    10,    38,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    37,    38,     7,     8,     9,    10,
      20,    12,    13,    14,    15,    16,    17,    18,    19,    29,
      21,    22,    32,    33,    34,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    38,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    29,    -1,    -1,    32,    33,    -1,    29,    -1,    -1,
      32,    33,     9,    10,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      -1,    38,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    -1,    38,    21,    22,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    21,    22,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    20,    29,    32,
      33,    34,    40,    41,    42,    43,    44,    45,    47,    48,
      50,    51,    52,    53,    54,    11,    23,    24,    25,    26,
      27,    28,    29,    46,     4,    48,    50,    54,    48,    48,
      48,    29,     0,    42,     7,     8,     9,    10,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    22,    38,    48,
       4,    30,    48,    49,    55,    56,    48,    30,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    11,    30,    31,    30,    31,    30,
      37,    48,    48,    56,     4,    49,    35,    48,    41,    36
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    39,    40,    41,    41,    41,    42,    42,    42,    43,
      43,    44,    45,    46,    46,    46,    46,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    50,    51,    51,    52,
      52,    53,    54,    54,    54,    55,    55,    55,    56,    56
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     0,     1,     1,     1,     1,
       1,     7,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     5,     1,     1,     1,
       1,     1,     3,     4,     4,     1,     3,     3,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "TNUMBER",
  "TIDENTIFIER", "TFLOAT", "TSTRING", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"=\"", "\"^\"", "\"%\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"",
  "\"&&\"", "\"||\"", "\"!\"", "\"!=\"", "\"==\"", "\"+=\"", "\"-=\"",
  "\"*=\"", "\"/=\"", "\"%=\"", "\"^=\"", "\"(\"", "\")\"", "\",\"",
  "\"TRUE\"", "\"FALSE\"", "\"if\"", "\"{\"", "\"}\"", "\":\"", "\"?\"",
  "$accept", "program", "stmts", "stmt", "exprstmt", "ifstmt",
  "identifier", "assignoptokens", "assign", "expr", "keyword", "ternary",
  "numeric", "boolean", "string", "method", "call_params",
  "call_params_keywords", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   100,   100,   105,   106,   107,   110,   111,   112,   115,
     116,   119,   124,   127,   127,   127,   127,   127,   127,   130,
     131,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   165,   168,   172,   173,   176,
     177,   180,   184,   185,   186,   191,   192,   193,   201,   202
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
    };
    // Last valid token kind.
    const int code_max = 293;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2326 "bison.tab.cpp"

#line 207 "bison.y"

void yy::parser::error(const location_type &l,  const std::string& msg) {
    **errorLocation = l;
    *errorReturn = msg;
}



std::string token_name(int t) {
    return yy::parser::symbol_name(yy::parser::by_kind((yy::parser::token_type)t).type_get());
}

