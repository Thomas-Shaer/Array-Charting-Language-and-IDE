#pragma once




// A Bison parser, made by GNU Bison 3.4.1.

// Locations for Bison parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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
 ** \file location.hh
 ** Define the yy::location class.
 */

#ifndef YY_YY_LOCATION_HH_INCLUDED
# define YY_YY_LOCATION_HH_INCLUDED

# include <algorithm> // std::max
# include <iostream>
# include <string>

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

namespace yy {
#line 59 "location.hh"

    /// A point in a source file.
    class Position
    {
    public:

        /// Current line number.
        unsigned int line = 0;
        /// Current column number.
        unsigned int column = 0;

        Position(const unsigned int _line, const unsigned int _column) : line(_line), column(_column) {}
        Position() {}
    };



    /// Two points in a source file.
    class SourceLocation
    {
    public:


        SourceLocation();
        SourceLocation(const SourceLocation& sl);
        SourceLocation(const Position _begin, const Position _end) : begin(_begin), end(_end) {}


        //SourceLocation& operator=(const SourceLocation& sl);

        /*
        Used to easily combine multiple source location objects together.
        Does this via getting the minimum and maximum row/col of the two objects and
        creating a new one from that.
        */
        SourceLocation operator+(const SourceLocation& sl);

        /*
        Given the source code, highlight the source code in the lines/cols
        corresponding to this location.
        Highlighting is done via ^ characters
        */
        std::string highlightSourceLocation(const std::string& sourceCode) const;

        /*
        Prints out location in clear format (mainly for debugging)
        */
        friend std::ostream& operator<<(std::ostream& output, const SourceLocation& source);

        /// Beginning of the located region.
        Position begin;
        /// End of the located region.
        Position end;
    };




} // yy
#line 321 "location.hh"

#endif // !YY_YY_LOCATION_HH_INCLUDED
