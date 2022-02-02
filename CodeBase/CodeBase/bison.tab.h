// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file bison.tab.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
// "%code requires" blocks.
#line 32 "bison.y"

  typedef void* yyscan_t;

#line 53 "bison.tab.h"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 182 "bison.tab.h"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // assign
      char dummy1[sizeof (AssignNode*)];

      // stmts
      char dummy2[sizeof (BlockNode*)];

      // boolean
      char dummy3[sizeof (BooleanNode*)];

      // expr
      char dummy4[sizeof (Expression*)];

      // exprstmt
      char dummy5[sizeof (ExpressionStatementNode*)];

      // identifier
      char dummy6[sizeof (IdentifierNode*)];

      // ifstmt
      char dummy7[sizeof (IfStatementNode*)];

      // method
      char dummy8[sizeof (MethodCallNode*)];

      // numeric
      char dummy9[sizeof (NumberNode*)];

      // stmt
      char dummy10[sizeof (Statement*)];

      // string
      char dummy11[sizeof (StringNode*)];

      // ternary
      char dummy12[sizeof (TernaryNode*)];

      // "+"
      // "-"
      // "*"
      // "/"
      // "="
      // "^"
      // "%"
      // "<"
      // "<="
      // ">"
      // ">="
      // "&&"
      // "||"
      // "!"
      // "!="
      // "=="
      // "("
      // ")"
      // ","
      // "TRUE"
      // "FALSE"
      // "if"
      // "{"
      // "}"
      // ":"
      // "?"
      char dummy13[sizeof (int)];

      // TNUMBER
      // TIDENTIFIER
      // TFLOAT
      // TSTRING
      char dummy14[sizeof (std::string)];

      // call_params
      char dummy15[sizeof (std::vector<Expression*>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    TNUMBER = 258,                 // TNUMBER
    TIDENTIFIER = 259,             // TIDENTIFIER
    TFLOAT = 260,                  // TFLOAT
    TSTRING = 261,                 // TSTRING
    TPLUS = 262,                   // "+"
    TMINUS = 263,                  // "-"
    TMUL = 264,                    // "*"
    TDIV = 265,                    // "/"
    TASSIGN = 266,                 // "="
    TPOW = 267,                    // "^"
    TMOD = 268,                    // "%"
    TLESS = 269,                   // "<"
    TLESSEQUAL = 270,              // "<="
    TGREATER = 271,                // ">"
    TGREATEREQUAL = 272,           // ">="
    TAND = 273,                    // "&&"
    TOR = 274,                     // "||"
    TNOT = 275,                    // "!"
    TNOTEQUAL = 276,               // "!="
    TEQUAL = 277,                  // "=="
    TOPENBRACKET = 278,            // "("
    TCLOSEBRACKET = 279,           // ")"
    TCOMMA = 280,                  // ","
    TTRUE = 281,                   // "TRUE"
    TFALSE = 282,                  // "FALSE"
    TIF = 283,                     // "if"
    TOPENBLOCK = 284,              // "{"
    TCLOSEBLOCK = 285,             // "}"
    TCOLON = 286,                  // ":"
    TQUESTIONMARK = 287            // "?"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 33, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_TNUMBER = 3,                           // TNUMBER
        S_TIDENTIFIER = 4,                       // TIDENTIFIER
        S_TFLOAT = 5,                            // TFLOAT
        S_TSTRING = 6,                           // TSTRING
        S_TPLUS = 7,                             // "+"
        S_TMINUS = 8,                            // "-"
        S_TMUL = 9,                              // "*"
        S_TDIV = 10,                             // "/"
        S_TASSIGN = 11,                          // "="
        S_TPOW = 12,                             // "^"
        S_TMOD = 13,                             // "%"
        S_TLESS = 14,                            // "<"
        S_TLESSEQUAL = 15,                       // "<="
        S_TGREATER = 16,                         // ">"
        S_TGREATEREQUAL = 17,                    // ">="
        S_TAND = 18,                             // "&&"
        S_TOR = 19,                              // "||"
        S_TNOT = 20,                             // "!"
        S_TNOTEQUAL = 21,                        // "!="
        S_TEQUAL = 22,                           // "=="
        S_TOPENBRACKET = 23,                     // "("
        S_TCLOSEBRACKET = 24,                    // ")"
        S_TCOMMA = 25,                           // ","
        S_TTRUE = 26,                            // "TRUE"
        S_TFALSE = 27,                           // "FALSE"
        S_TIF = 28,                              // "if"
        S_TOPENBLOCK = 29,                       // "{"
        S_TCLOSEBLOCK = 30,                      // "}"
        S_TCOLON = 31,                           // ":"
        S_TQUESTIONMARK = 32,                    // "?"
        S_YYACCEPT = 33,                         // $accept
        S_program = 34,                          // program
        S_stmts = 35,                            // stmts
        S_stmt = 36,                             // stmt
        S_exprstmt = 37,                         // exprstmt
        S_ifstmt = 38,                           // ifstmt
        S_identifier = 39,                       // identifier
        S_assign = 40,                           // assign
        S_expr = 41,                             // expr
        S_ternary = 42,                          // ternary
        S_numeric = 43,                          // numeric
        S_boolean = 44,                          // boolean
        S_string = 45,                           // string
        S_method = 46,                           // method
        S_call_params = 47                       // call_params
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_assign: // assign
        value.move< AssignNode* > (std::move (that.value));
        break;

      case symbol_kind::S_stmts: // stmts
        value.move< BlockNode* > (std::move (that.value));
        break;

      case symbol_kind::S_boolean: // boolean
        value.move< BooleanNode* > (std::move (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< Expression* > (std::move (that.value));
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.move< ExpressionStatementNode* > (std::move (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< IdentifierNode* > (std::move (that.value));
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.move< IfStatementNode* > (std::move (that.value));
        break;

      case symbol_kind::S_method: // method
        value.move< MethodCallNode* > (std::move (that.value));
        break;

      case symbol_kind::S_numeric: // numeric
        value.move< NumberNode* > (std::move (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< Statement* > (std::move (that.value));
        break;

      case symbol_kind::S_string: // string
        value.move< StringNode* > (std::move (that.value));
        break;

      case symbol_kind::S_ternary: // ternary
        value.move< TernaryNode* > (std::move (that.value));
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
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_call_params: // call_params
        value.move< std::vector<Expression*> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AssignNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AssignNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BlockNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BlockNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BooleanNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BooleanNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Expression*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Expression*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExpressionStatementNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExpressionStatementNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IdentifierNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IdentifierNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IfStatementNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IfStatementNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, MethodCallNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const MethodCallNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NumberNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NumberNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Statement*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Statement*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StringNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StringNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TernaryNode*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TernaryNode*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Expression*>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Expression*>& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_assign: // assign
        value.template destroy< AssignNode* > ();
        break;

      case symbol_kind::S_stmts: // stmts
        value.template destroy< BlockNode* > ();
        break;

      case symbol_kind::S_boolean: // boolean
        value.template destroy< BooleanNode* > ();
        break;

      case symbol_kind::S_expr: // expr
        value.template destroy< Expression* > ();
        break;

      case symbol_kind::S_exprstmt: // exprstmt
        value.template destroy< ExpressionStatementNode* > ();
        break;

      case symbol_kind::S_identifier: // identifier
        value.template destroy< IdentifierNode* > ();
        break;

      case symbol_kind::S_ifstmt: // ifstmt
        value.template destroy< IfStatementNode* > ();
        break;

      case symbol_kind::S_method: // method
        value.template destroy< MethodCallNode* > ();
        break;

      case symbol_kind::S_numeric: // numeric
        value.template destroy< NumberNode* > ();
        break;

      case symbol_kind::S_stmt: // stmt
        value.template destroy< Statement* > ();
        break;

      case symbol_kind::S_string: // string
        value.template destroy< StringNode* > ();
        break;

      case symbol_kind::S_ternary: // ternary
        value.template destroy< TernaryNode* > ();
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
        value.template destroy< int > ();
        break;

      case symbol_kind::S_TNUMBER: // TNUMBER
      case symbol_kind::S_TIDENTIFIER: // TIDENTIFIER
      case symbol_kind::S_TFLOAT: // TFLOAT
      case symbol_kind::S_TSTRING: // TSTRING
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_call_params: // call_params
        value.template destroy< std::vector<Expression*> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v)
        : super_type(token_type (tok), std::move (v))
#else
      symbol_type (int tok, const int& v)
        : super_type(token_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type(token_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type(token_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    parser (yyscan_t scanner_yyarg, BlockNode** inputnode_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TNUMBER (std::string v)
      {
        return symbol_type (token::TNUMBER, std::move (v));
      }
#else
      static
      symbol_type
      make_TNUMBER (const std::string& v)
      {
        return symbol_type (token::TNUMBER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIDENTIFIER (std::string v)
      {
        return symbol_type (token::TIDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_TIDENTIFIER (const std::string& v)
      {
        return symbol_type (token::TIDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TFLOAT (std::string v)
      {
        return symbol_type (token::TFLOAT, std::move (v));
      }
#else
      static
      symbol_type
      make_TFLOAT (const std::string& v)
      {
        return symbol_type (token::TFLOAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TSTRING (std::string v)
      {
        return symbol_type (token::TSTRING, std::move (v));
      }
#else
      static
      symbol_type
      make_TSTRING (const std::string& v)
      {
        return symbol_type (token::TSTRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TPLUS (int v)
      {
        return symbol_type (token::TPLUS, std::move (v));
      }
#else
      static
      symbol_type
      make_TPLUS (const int& v)
      {
        return symbol_type (token::TPLUS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMINUS (int v)
      {
        return symbol_type (token::TMINUS, std::move (v));
      }
#else
      static
      symbol_type
      make_TMINUS (const int& v)
      {
        return symbol_type (token::TMINUS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMUL (int v)
      {
        return symbol_type (token::TMUL, std::move (v));
      }
#else
      static
      symbol_type
      make_TMUL (const int& v)
      {
        return symbol_type (token::TMUL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TDIV (int v)
      {
        return symbol_type (token::TDIV, std::move (v));
      }
#else
      static
      symbol_type
      make_TDIV (const int& v)
      {
        return symbol_type (token::TDIV, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TASSIGN (int v)
      {
        return symbol_type (token::TASSIGN, std::move (v));
      }
#else
      static
      symbol_type
      make_TASSIGN (const int& v)
      {
        return symbol_type (token::TASSIGN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TPOW (int v)
      {
        return symbol_type (token::TPOW, std::move (v));
      }
#else
      static
      symbol_type
      make_TPOW (const int& v)
      {
        return symbol_type (token::TPOW, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMOD (int v)
      {
        return symbol_type (token::TMOD, std::move (v));
      }
#else
      static
      symbol_type
      make_TMOD (const int& v)
      {
        return symbol_type (token::TMOD, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TLESS (int v)
      {
        return symbol_type (token::TLESS, std::move (v));
      }
#else
      static
      symbol_type
      make_TLESS (const int& v)
      {
        return symbol_type (token::TLESS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TLESSEQUAL (int v)
      {
        return symbol_type (token::TLESSEQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_TLESSEQUAL (const int& v)
      {
        return symbol_type (token::TLESSEQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TGREATER (int v)
      {
        return symbol_type (token::TGREATER, std::move (v));
      }
#else
      static
      symbol_type
      make_TGREATER (const int& v)
      {
        return symbol_type (token::TGREATER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TGREATEREQUAL (int v)
      {
        return symbol_type (token::TGREATEREQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_TGREATEREQUAL (const int& v)
      {
        return symbol_type (token::TGREATEREQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAND (int v)
      {
        return symbol_type (token::TAND, std::move (v));
      }
#else
      static
      symbol_type
      make_TAND (const int& v)
      {
        return symbol_type (token::TAND, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOR (int v)
      {
        return symbol_type (token::TOR, std::move (v));
      }
#else
      static
      symbol_type
      make_TOR (const int& v)
      {
        return symbol_type (token::TOR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TNOT (int v)
      {
        return symbol_type (token::TNOT, std::move (v));
      }
#else
      static
      symbol_type
      make_TNOT (const int& v)
      {
        return symbol_type (token::TNOT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TNOTEQUAL (int v)
      {
        return symbol_type (token::TNOTEQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_TNOTEQUAL (const int& v)
      {
        return symbol_type (token::TNOTEQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TEQUAL (int v)
      {
        return symbol_type (token::TEQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_TEQUAL (const int& v)
      {
        return symbol_type (token::TEQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOPENBRACKET (int v)
      {
        return symbol_type (token::TOPENBRACKET, std::move (v));
      }
#else
      static
      symbol_type
      make_TOPENBRACKET (const int& v)
      {
        return symbol_type (token::TOPENBRACKET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCLOSEBRACKET (int v)
      {
        return symbol_type (token::TCLOSEBRACKET, std::move (v));
      }
#else
      static
      symbol_type
      make_TCLOSEBRACKET (const int& v)
      {
        return symbol_type (token::TCLOSEBRACKET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCOMMA (int v)
      {
        return symbol_type (token::TCOMMA, std::move (v));
      }
#else
      static
      symbol_type
      make_TCOMMA (const int& v)
      {
        return symbol_type (token::TCOMMA, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TTRUE (int v)
      {
        return symbol_type (token::TTRUE, std::move (v));
      }
#else
      static
      symbol_type
      make_TTRUE (const int& v)
      {
        return symbol_type (token::TTRUE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TFALSE (int v)
      {
        return symbol_type (token::TFALSE, std::move (v));
      }
#else
      static
      symbol_type
      make_TFALSE (const int& v)
      {
        return symbol_type (token::TFALSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIF (int v)
      {
        return symbol_type (token::TIF, std::move (v));
      }
#else
      static
      symbol_type
      make_TIF (const int& v)
      {
        return symbol_type (token::TIF, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOPENBLOCK (int v)
      {
        return symbol_type (token::TOPENBLOCK, std::move (v));
      }
#else
      static
      symbol_type
      make_TOPENBLOCK (const int& v)
      {
        return symbol_type (token::TOPENBLOCK, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCLOSEBLOCK (int v)
      {
        return symbol_type (token::TCLOSEBLOCK, std::move (v));
      }
#else
      static
      symbol_type
      make_TCLOSEBLOCK (const int& v)
      {
        return symbol_type (token::TCLOSEBLOCK, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCOLON (int v)
      {
        return symbol_type (token::TCOLON, std::move (v));
      }
#else
      static
      symbol_type
      make_TCOLON (const int& v)
      {
        return symbol_type (token::TCOLON, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TQUESTIONMARK (int v)
      {
        return symbol_type (token::TQUESTIONMARK, std::move (v));
      }
#else
      static
      symbol_type
      make_TQUESTIONMARK (const int& v)
      {
        return symbol_type (token::TQUESTIONMARK, v);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 282,     ///< Last index in yytable_.
      yynnts_ = 15,  ///< Number of nonterminal symbols.
      yyfinal_ = 35 ///< Termination state number.
    };


    // User arguments.
    yyscan_t scanner;
    BlockNode** inputnode;

  };


} // yy
#line 2007 "bison.tab.h"


// "%code provides" blocks.
#line 36 "bison.y"

      #define YY_DECL \
        int yylex(yy::parser::semantic_type* value, yyscan_t yyscanner)
	YY_DECL;
    std::string token_name(int t);
 

#line 2019 "bison.tab.h"


#endif // !YY_YY_BISON_TAB_H_INCLUDED
