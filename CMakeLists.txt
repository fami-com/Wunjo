cmake_minimum_required(VERSION 3.17)
project(Wunjo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wunjo main.cpp Lexer/Lexer.cpp Lexer/Lexer.h Token/Token.cpp Token/Token.h Token/TokenType.h Token/predicates.h Token/predicates.cpp Types/Number.cpp Types/Number.h)