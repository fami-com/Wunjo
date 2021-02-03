//
// This file is licensed under MPL 2.0, GNU GPL v2.0+ and GNU LGPL v2.1+
// For more information about the licensing, see the LICENSE file in the project root
// Copyright (c) 2021 - 2021 fami-com
//

#include <iostream>
#include <algorithm>
#include "Lexer/Scanner.h"
#include "Token/Token.h"
#include "Common/Visitor.h"

int main() {
    std::string code = "- + == * ** & int data while for ; + ** 11234 44.33 23rZSER \\ -<-";
    auto lexer = Lexer::Scanner(code);
    lexer.run();
    if(auto v = lexer.get_error()){
        auto err_visitor = overload{
            [](Lexer::InvalidBase& e){std::cout << e << std::endl;},
            [](Lexer::UnterminatedString& e){std::cout << e << std::endl;},
            [](Lexer::InvalidCharacter& e){std::cout << e << std::endl;},
            [](Lexer::InvalidNumericLiteral& e){std::cout << e << std::endl;}
        };

        std::visit(err_visitor, *v);
    } else {
        for(auto& k : lexer.tokens){
            std::cout << k <<std::endl;
        }
    }
}
