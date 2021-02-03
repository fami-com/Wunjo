//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#include <iostream>
#include "ScannerError.h"

namespace Lexer {
    Error::Error(int line, int column) : line(line), column(column){}

    std::tuple<int, int> Error::get_location() const  {
        return std::make_tuple(line, column);
    }

    std::ostream& operator<<(std::ostream& os, const InvalidCharacter& e) {
        os << "InvalidCharacter(" << int(e.c) << " (" << e.c << "), [line: " << e.line << ", column: " << e.column
           << "])";
        return os;
    }

    InvalidCharacter::InvalidCharacter(int line, int column, char c)
            : Error(line, column), c(c) {}

    std::ostream& operator<<(std::ostream& os, const UnterminatedString& e) {
        os << "UnterminatedString([line: " << e.line << ", column: " << e.column << "])";
        return os;
    }

    UnterminatedString::UnterminatedString(int line, int column)
            : Error(line, column){}

    std::ostream& operator<<(std::ostream& os, const InvalidBase& e) {
        os << "InvalidBase(" << e.base << ", [line: " << e.line << ", column: " << e.column << "])";
        return os;
    }

    InvalidBase::InvalidBase(int line, int column, int base)
        : Error(line, column), base(base){}

    std::ostream& operator<<(std::ostream& os, const InvalidNumericLiteral& e) {
        os << "InvalidNumericLiteral(" << int(e.c) << " (" << e.c << "), " << e.base << ", [line: " << e.line
           << ", column: " << e.column << "])";
        return os;
    }

    InvalidNumericLiteral::InvalidNumericLiteral(int line, int column, char c, int base)
        : Error(line, column), c(c), base(base) {}
}