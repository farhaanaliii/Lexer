#include "lexer.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>

using namespace std;

Lexer::Lexer(string code) {
    tokens = {};
    content = code;
    position = 0;
    current_char = content[position];
}

void Lexer::advance() {
    position++;
    if (position < content.length())
        current_char = content[position];
    else
        current_char = '\0';
}

Token Lexer::make_token(string value, TokenType type) {
    Token token;
    token.value = value;
    token.type = type;
    return token;
}

bool Lexer::isalphanum(char c) {
    return isalnum(c) || c == '_';
}

bool Lexer::is_keyword(string identifier) {
    for (const auto& keyword : keywords) {
        if (keyword == identifier) return true;
    }
    return false;
}

Token Lexer::make_identifier() {
    string value = "";
    while (isalphanum(current_char)) {
        value += current_char;
        advance();
    }
    TokenType type = is_keyword(value) ? TT_KEYWORD : TT_IDENTIFIER;
    return make_token(value, type);
}

Token Lexer::make_string() {
    string value = "";
    advance();
    while (current_char != '"' && position < content.length()) {
        if (current_char == '\n') {
            cerr << "Unterminated string literal at position " << position << "\n";
            exit(EXIT_FAILURE);
        }
        value += current_char;
        advance();
    }
    if (current_char != '"') {
        cerr << "Unterminated string at position " << position << ": did you forget a closing quote?\n";
        exit(EXIT_FAILURE);
    }
    advance();
    return make_token(value, TT_STRING);
}

vector<Token> Lexer::lex() {
    while (position < content.length()) {
        if (isspace(current_char)) {
            advance();
        }
        else if (isalphanum(current_char)) {
            tokens.push_back(make_identifier());
        }
        else if (isdigit(current_char)) {
            string value = "";
            while (isdigit(current_char)) {
                value += current_char;
                advance();
            }
            tokens.push_back(make_token(value, TT_INTEGER));
        }
        else if (current_char == '(') {
            tokens.push_back(make_token("(", TT_LEFT_PAREN));
            advance();
        }
        else if (current_char == ')') {
            tokens.push_back(make_token(")", TT_RIGHT_PAREN));
            advance();
        }
        else if (current_char == '"') {
            tokens.push_back(make_string());
        }
        else if (current_char == ',') {
            tokens.push_back(make_token(",", TT_COMA));
            advance();
        }
        else if (current_char == ':') {
            tokens.push_back(make_token(":", TT_COLON));
            advance();
        }
        else if (current_char == ';') {
            tokens.push_back(make_token(";", TT_SEMICOLON));
            advance();
        }
        else if (current_char == '+') {
            tokens.push_back(make_token("+", TT_PLUS));
            advance();
        }
        else if (current_char == '-') {
            tokens.push_back(make_token("-", TT_MINUS));
            advance();
        }
        else if (current_char == '*') {
            tokens.push_back(make_token("*", TT_ASTERISK));
            advance();
        }
        else if (current_char == '/') {
            tokens.push_back(make_token("/", TT_SLASH));
            advance();
        }
        else if (current_char == '=') {
            tokens.push_back(make_token("=", TT_EQUAL));
            advance();
        }
        else {
            cerr << "Unexpected token \"" << current_char << "\" at position " << position << "\n";
            exit(EXIT_FAILURE);
        }
    }
    tokens.push_back(make_token("", TT_EOF));
    return tokens;
}
