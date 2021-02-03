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
