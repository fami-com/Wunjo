//
// Created by V on 2021-01-22.
//

#ifndef WUNJO_LEXER_H
#define WUNJO_LEXER_H

#include <string>
#include <vector>
#include "../Token/token.h"
#include "LexerError.h"

namespace Lexer {
    using namespace Token;

    class Lexer{
        const std::u8string code;

        int start;
        int pos;
        int column;
        int line;

        bool end();

        LexerError scan_once();

        char8_t advance();
        bool consume(char8_t expect);
        char8_t peek();
        void add_token(type type);
        void add_token(type type, const std::any& data);

        int64_t match_integer();
        double match_float();
        std::u8string match_string();
        std::u8string match_identifier();

        static inline bool is_digit(char8_t c);
        static inline bool is_alpha(char8_t c);
        static inline bool is_alnum(char8_t c);

        static inline bool is_id_start(char8_t c);
        static inline bool is_id_cont(char8_t c);

        public:
        std::vector<token> tokens;
        explicit Lexer(std::u8string& input) noexcept;
        LexerError run();
    };
}
#endif //WUNJO_LEXER_H
