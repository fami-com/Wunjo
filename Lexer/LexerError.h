//
// Created by V on 2021-01-28.
//

#ifndef WUNJO_LEXERERROR_H
#define WUNJO_LEXERERROR_H

namespace Lexer {
    struct Ok {};
    struct InvalidCharacter {
        char8_t c;
        int line;
        int column;
    };

    using LexerError = std::variant<Ok,InvalidCharacter>;
}
#endif //WUNJO_LEXERERROR_H
