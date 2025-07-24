#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

typedef enum {
    TT_IDENTIFIER,
    TT_KEYWORD,
    TT_STRING,
    TT_INTEGER,
    
    TT_COLON,
    TT_SEMICOLON,
    TT_COMA,
    TT_LEFT_PAREN,
    TT_RIGHT_PAREN,
    TT_DOUBLE_QUOTES,
    TT_PLUS,
    TT_MINUS,
    TT_ASTERISK,
    TT_SLASH,
    TT_EQUAL,
    
    TT_EOF
} TokenType;

typedef struct {
    TokenType type;
    std::string value;
} Token;

class Lexer {
private:
    std::vector<Token> tokens;
    std::vector<std::string> keywords;
    std::string content;
    char current_char;
    size_t position;
    bool isalphanum(char c);
    bool is_keyword(std::string identifier);
    Token make_token(std::string value, TokenType type);
    Token make_identifier();
    Token make_string();
    void advance();
public:
    Lexer(std::string code);
    std::vector<Token> lex();
};

#endif // LEXER_HPP
