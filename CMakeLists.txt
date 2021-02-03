cmake_minimum_required(VERSION 3.17)
project(Wunjo)

set(CMAKE_CXX_STANDARD 20)

include_directories(Common Lexer Token Types)

# Types/Integer.cpp Types/Integer.h Types/Rational.cpp Types/Rational.h Types/Float.cpp Types/Float.h Types/Complex.cpp Types/Complex.h Types/Common.h
add_executable(Wunjo main.cpp Lexer/Scanner.cpp Lexer/Scanner.h Token/Token.cpp Token/Token.h Token/Type.h Lexer/ScannerError.h Common/Visitor.h Lexer/ScannerError.cpp Token/Type.cpp)