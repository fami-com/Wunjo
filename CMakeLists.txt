cmake_minimum_required(VERSION 3.17)
project(Wunjo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wunjo main.cpp Lexer/Lexer.cpp Lexer/Lexer.h Token/token.cpp Token/token.h Token/type.h Token/predicates.h Token/predicates.cpp Types/Integer.cpp Types/Integer.h Types/Rational.cpp Types/Rational.h Types/Float.cpp Types/Float.h Types/Complex.cpp Types/Complex.h Types/Number.cpp Types/Number.h Lexer/LexerError.h Common/Visitor.h)