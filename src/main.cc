#include <iostream>
#include "lexer.hpp"

const char* token_type_to_string(TokenType type) {
    switch(type) {
        case TT_IDENTIFIER: return "IDENTIFIER";
        case TT_KEYWORD: return "KEYWORD";
        case TT_STRING: return "STRING";
        case TT_INTEGER: return "INTEGER";
        case TT_COLON: return "COLON";
        case TT_SEMICOLON: return "SEMICOLON";
        case TT_COMA: return "COMA";
        case TT_LEFT_PAREN: return "LEFT_PAREN";
        case TT_RIGHT_PAREN: return "RIGHT_PAREN";
        case TT_DOUBLE_QUOTES: return "DOUBLE_QUOTES";
        case TT_PLUS: return "PLUS";
        case TT_MINUS: return "MINUS";
        case TT_ASTERISK: return "ASTERISK";
        case TT_SLASH: return "SLASH";
        case TT_EQUAL: return "EQUAL";
        case TT_EOF: return "EOF";
        default: return "UNKNOWN";
    }
}

int main() {
    std::string code = R"(
        var1 = 42;
        str = "hello, world";
        foo(bar, baz);
        x = y + z - 3 * 7 / 2;
        : ; , ( )  = + - * /
    )";

    Lexer lexer(code);
    std::vector<Token> tokens = lexer.lex();
    for (const auto& token : tokens) {
        std::cout << "Token: '" << token.value << "'\tType: " << token_type_to_string(token.type) << std::endl;
    }
    return 0;
} 