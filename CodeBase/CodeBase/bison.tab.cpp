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
#line 10 "bison.y"


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
	#include "node.h"


#line 60 "bison.tab.cpp"


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
#line 138 "bison.tab.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t scanner_yyarg, BlockNode** inputnode_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      inputnode (inputnode_yyarg)
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

      case symbol_kind::S_method: // method
        value.copy< MethodCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.copy< NumberNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params: // call_params
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

      case symbol_kind::S_method: // method
        value.move< MethodCallNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.move< NumberNode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< Statement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_call_params: // call_params
        value.move< std::vector<Expression*> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

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
    : super_type (YY_MOVE (that.state))
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

      case symbol_kind::S_method: // method
        value.YY_MOVE_OR_COPY< MethodCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.YY_MOVE_OR_COPY< NumberNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params: // call_params
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
    : super_type (s)
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

      case symbol_kind::S_method: // method
        value.move< MethodCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.move< NumberNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_params: // call_params
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

      case symbol_kind::S_method: // method
        value.copy< MethodCallNode* > (that.value);
        break;

      case symbol_kind::S_numeric: // numeric
        value.copy< NumberNode* > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< Statement* > (that.value);
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_call_params: // call_params
        value.copy< std::vector<Expression*> > (that.value);
        break;

      default:
        break;
    }

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

      case symbol_kind::S_method: // method
        value.move< MethodCallNode* > (that.value);
        break;

      case symbol_kind::S_numeric: // numeric
        value.move< NumberNode* > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< Statement* > (that.value);
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_call_params: // call_params
        value.move< std::vector<Expression*> > (that.value);
        break;

      default:
        break;
    }

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
            << ' ' << yysym.name () << " (";
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, scanner));
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

      case symbol_kind::S_method: // method
        yylhs.value.emplace< MethodCallNode* > ();
        break;

      case symbol_kind::S_numeric: // numeric
        yylhs.value.emplace< NumberNode* > ();
        break;

      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< Statement* > ();
        break;

      case symbol_kind::S_TPLUS: // "+"
      case symbol_kind::S_TMINUS: // "-"
      case symbol_kind::S_TMUL: // "*"
      case symbol_kind::S_TDIV: // "/"
      case symbol_kind::S_TASSIGN: // "="
      case symbol_kind::S_TLESS: // "<"
      case symbol_kind::S_TLESSEQUAL: // "<="
      case symbol_kind::S_TGREATER: // ">"
      case symbol_kind::S_TGREATEREQUAL: // ">="
      case symbol_kind::S_TAND: // "&&"
      case symbol_kind::S_TOR: // "||"
      case symbol_kind::S_TNOT: // "!"
      case symbol_kind::S_TNOTEQUAL: // "!="
      case symbol_kind::S_TEQUAL: // "=="
      case symbol_kind::S_TOPENBRACKET: // "("
      case symbol_kind::S_TCLOSEBRACKET: // ")"
      case symbol_kind::S_TCOMMA: // ","
      case symbol_kind::S_TTRUE: // "TRUE"
      case symbol_kind::S_TFALSE: // "FALSE"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_call_params: // call_params
        yylhs.value.emplace< std::vector<Expression*> > ();
        break;

      default:
        break;
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
#line 73 "bison.y"
                { 
				   *inputnode = yystack_[0].value.as < BlockNode* > ();
				}
#line 1079 "bison.tab.cpp"
    break;

  case 3: // stmts: stmt
#line 78 "bison.y"
             { yylhs.value.as < BlockNode* > () = new BlockNode(); yylhs.value.as < BlockNode* > ()->statementNodes.push_back(yystack_[0].value.as < Statement* > ()); }
#line 1085 "bison.tab.cpp"
    break;

  case 4: // stmts: stmts stmt
#line 79 "bison.y"
                   { yystack_[1].value.as < BlockNode* > ()->statementNodes.push_back(yystack_[0].value.as < Statement* > ()); yylhs.value.as < BlockNode* > () = yystack_[1].value.as < BlockNode* > (); }
#line 1091 "bison.tab.cpp"
    break;

  case 5: // stmts: %empty
#line 80 "bison.y"
                      { yylhs.value.as < BlockNode* > () = new BlockNode(); }
#line 1097 "bison.tab.cpp"
    break;

  case 6: // stmt: assign
#line 83 "bison.y"
              {yylhs.value.as < Statement* > () = yystack_[0].value.as < AssignNode* > ();}
#line 1103 "bison.tab.cpp"
    break;

  case 7: // stmt: exprstmt
#line 84 "bison.y"
                {yylhs.value.as < Statement* > () = yystack_[0].value.as < ExpressionStatementNode* > ();}
#line 1109 "bison.tab.cpp"
    break;

  case 8: // exprstmt: method
#line 87 "bison.y"
                  {yylhs.value.as < ExpressionStatementNode* > () = new ExpressionStatementNode(yystack_[0].value.as < MethodCallNode* > ());}
#line 1115 "bison.tab.cpp"
    break;

  case 9: // identifier: TIDENTIFIER
#line 90 "bison.y"
                         {yylhs.value.as < IdentifierNode* > () = new IdentifierNode(yystack_[0].value.as < std::string > ());}
#line 1121 "bison.tab.cpp"
    break;

  case 10: // assign: TIDENTIFIER "=" expr
#line 94 "bison.y"
                                  {yylhs.value.as < AssignNode* > () = new AssignNode(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Expression* > ());}
#line 1127 "bison.tab.cpp"
    break;

  case 11: // expr: numeric
#line 97 "bison.y"
               { yylhs.value.as < Expression* > () = yystack_[0].value.as < NumberNode* > (); }
#line 1133 "bison.tab.cpp"
    break;

  case 12: // expr: boolean
#line 98 "bison.y"
               {yylhs.value.as < Expression* > ()=yystack_[0].value.as < BooleanNode* > ();}
#line 1139 "bison.tab.cpp"
    break;

  case 13: // expr: method
#line 99 "bison.y"
              {yylhs.value.as < Expression* > ()=yystack_[0].value.as < MethodCallNode* > ();}
#line 1145 "bison.tab.cpp"
    break;

  case 14: // expr: identifier
#line 100 "bison.y"
                  {yylhs.value.as < Expression* > () = yystack_[0].value.as < IdentifierNode* > (); }
#line 1151 "bison.tab.cpp"
    break;

  case 15: // expr: expr "*" expr
#line 101 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1157 "bison.tab.cpp"
    break;

  case 16: // expr: expr "/" expr
#line 102 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1163 "bison.tab.cpp"
    break;

  case 17: // expr: expr "+" expr
#line 103 "bison.y"
                       {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1169 "bison.tab.cpp"
    break;

  case 18: // expr: expr "-" expr
#line 104 "bison.y"
                        {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1175 "bison.tab.cpp"
    break;

  case 19: // expr: expr "<" expr
#line 105 "bison.y"
                       {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1181 "bison.tab.cpp"
    break;

  case 20: // expr: expr "<=" expr
#line 106 "bison.y"
                            {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1187 "bison.tab.cpp"
    break;

  case 21: // expr: expr ">" expr
#line 107 "bison.y"
                          {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1193 "bison.tab.cpp"
    break;

  case 22: // expr: expr ">=" expr
#line 108 "bison.y"
                               {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1199 "bison.tab.cpp"
    break;

  case 23: // expr: expr "!=" expr
#line 109 "bison.y"
                           {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1205 "bison.tab.cpp"
    break;

  case 24: // expr: expr "==" expr
#line 110 "bison.y"
                        {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1211 "bison.tab.cpp"
    break;

  case 25: // expr: expr "||" expr
#line 111 "bison.y"
                     {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1217 "bison.tab.cpp"
    break;

  case 26: // expr: expr "&&" expr
#line 112 "bison.y"
                      {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()}); }
#line 1223 "bison.tab.cpp"
    break;

  case 27: // expr: "+" expr
#line 113 "bison.y"
                  {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[0].value.as < Expression* > ()}); }
#line 1229 "bison.tab.cpp"
    break;

  case 28: // expr: "-" expr
#line 114 "bison.y"
                   {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[0].value.as < Expression* > ()}); }
#line 1235 "bison.tab.cpp"
    break;

  case 29: // expr: "!" expr
#line 115 "bison.y"
                 {yylhs.value.as < Expression* > () =  new MethodCallNode("operator" + token_name(yystack_[1].value.as < int > ()), {yystack_[0].value.as < Expression* > ()}); }
#line 1241 "bison.tab.cpp"
    break;

  case 30: // expr: "(" expr ")"
#line 116 "bison.y"
                                       {yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 1247 "bison.tab.cpp"
    break;

  case 31: // numeric: TNUMBER
#line 120 "bison.y"
                  { yylhs.value.as < NumberNode* > () = new NumberNode(atoi(yystack_[0].value.as < std::string > ().c_str())); }
#line 1253 "bison.tab.cpp"
    break;

  case 32: // boolean: "FALSE"
#line 123 "bison.y"
                 { yylhs.value.as < BooleanNode* > () = new BooleanNode(false); }
#line 1259 "bison.tab.cpp"
    break;

  case 33: // boolean: "TRUE"
#line 124 "bison.y"
                { yylhs.value.as < BooleanNode* > () = new BooleanNode(true); }
#line 1265 "bison.tab.cpp"
    break;

  case 34: // method: TIDENTIFIER "(" call_params ")"
#line 127 "bison.y"
                                                            {yylhs.value.as < MethodCallNode* > () = new MethodCallNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Expression*> > ());}
#line 1271 "bison.tab.cpp"
    break;

  case 35: // call_params: %empty
#line 130 "bison.y"
                         { yylhs.value.as < std::vector<Expression*> > () = std::vector<Expression*>(); }
#line 1277 "bison.tab.cpp"
    break;

  case 36: // call_params: expr
#line 131 "bison.y"
                 { yylhs.value.as < std::vector<Expression*> > () = std::vector<Expression*>(); yylhs.value.as < std::vector<Expression*> > ().push_back(yystack_[0].value.as < Expression* > ()); }
#line 1283 "bison.tab.cpp"
    break;

  case 37: // call_params: call_params "," expr
#line 132 "bison.y"
                                    { yystack_[2].value.as < std::vector<Expression*> > ().push_back(yystack_[0].value.as < Expression* > ()); yylhs.value.as < std::vector<Expression*> > () = yystack_[2].value.as < std::vector<Expression*> > (); }
#line 1289 "bison.tab.cpp"
    break;


#line 1293 "bison.tab.cpp"

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
        error (YY_MOVE (msg));
      }


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

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


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
    error (yyexc.what ());
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


  const signed char parser::yypact_ninf_ = -10;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      12,     0,    34,    12,   -10,   -10,   -10,   -10,    -2,    -2,
     -10,   -10,   -10,    21,    -2,    -2,    -2,    -2,   -10,   -10,
     -10,    47,   -10,   -10,   -10,    47,    56,    82,    82,    47,
      31,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,   -10,    -2,   -10,    82,    82,   -10,   -10,
       5,     5,     5,     5,    75,    61,    89,    89,    47
  };

  const signed char
  parser::yydefact_[] =
  {
       5,     0,     0,     2,     3,     7,     6,     8,     0,    35,
       1,     4,    31,     9,     0,     0,     0,     0,    33,    32,
      14,    10,    11,    12,    13,    36,     0,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    30,    17,    18,    15,    16,
      19,    20,    21,    22,    26,    25,    23,    24,    37
  };

  const signed char
  parser::yypgoto_[] =
  {
     -10,   -10,   -10,    44,   -10,   -10,   -10,    -9,   -10,   -10,
      15,   -10
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     5,    20,     6,    21,    22,    23,
      24,    26
  };

  const signed char
  parser::yytable_[] =
  {
      25,    12,    13,    14,    15,    27,    28,    29,    30,     8,
      31,    32,    33,    34,    16,     7,     1,    17,     7,     9,
      18,    19,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    10,    58,    31,    32,    33,    34,
       9,    35,    36,    37,    38,    39,    40,    11,    41,    42,
       0,    45,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    43,    44,    41,    42,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    33,
      34,     0,    41,    42,    31,    32,    33,    34,     0,    35,
      36,    37,    38
  };

  const signed char
  parser::yycheck_[] =
  {
       9,     3,     4,     5,     6,    14,    15,    16,    17,     9,
       5,     6,     7,     8,    16,     0,     4,    19,     3,    19,
      22,    23,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,    44,     5,     6,     7,     8,
      19,    10,    11,    12,    13,    14,    15,     3,    17,    18,
      -1,    20,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    20,    21,    17,    18,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,     7,
       8,    -1,    17,    18,     5,     6,     7,     8,    -1,    10,
      11,    12,    13
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,    25,    26,    27,    28,    30,    34,     9,    19,
       0,    27,     3,     4,     5,     6,    16,    19,    22,    23,
      29,    31,    32,    33,    34,    31,    35,    31,    31,    31,
      31,     5,     6,     7,     8,    10,    11,    12,    13,    14,
      15,    17,    18,    20,    21,    20,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    24,    25,    26,    26,    26,    27,    27,    28,    29,
      30,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    32,    33,    33,    34,    35,    35,    35
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     0,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     1,     1,     1,     4,     0,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "TNUMBER",
  "TIDENTIFIER", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"=\"", "\"<\"",
  "\"<=\"", "\">\"", "\">=\"", "\"&&\"", "\"||\"", "\"!\"", "\"!=\"",
  "\"==\"", "\"(\"", "\")\"", "\",\"", "\"TRUE\"", "\"FALSE\"", "$accept",
  "program", "stmts", "stmt", "exprstmt", "identifier", "assign", "expr",
  "numeric", "boolean", "method", "call_params", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    73,    73,    78,    79,    80,    83,    84,    87,    90,
      94,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   120,   123,   124,   127,   130,   131,   132
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
    };
    // Last valid token kind.
    const int code_max = 278;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1843 "bison.tab.cpp"

#line 135 "bison.y"

void yy::parser::error( const std::string& msg) {
    std::cout << msg << std::endl;
}



std::string token_name(int t) {
    return yy::parser::symbol_name(yy::parser::by_kind((yy::parser::token_type)t).type_get());
}

