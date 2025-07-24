# Lexer

[![GitHub](https://img.shields.io/badge/GitHub-farhaanaliii-blue?logo=github)](https://github.com/farhaanaliii)

A simple, extensible C++ lexer for tokenizing source code. This project is open source and aims to provide a minimal, easy-to-use lexer for educational and practical use cases.

## Features
- Tokenizes identifiers, keywords, strings, integers, operators, and punctuation
- Easily extensible for new token types
- Simple API: just create a `Lexer` and call `lex()`
- Written in modern C++

## Token Types
- Identifiers
- Keywords (customizable)
- Strings (double-quoted)
- Integers
- Parentheses: `(` and `)`
- Semicolons: `;`
- Commas: `,`
- Colons: `:`
- Operators: `+`, `-`, `*`, `/`, `=`
- Double quotes: `"`
- End of file (EOF)

## Usage

### 1. Include the header
```cpp
#include "src/lexer.hpp"
```

### 2. Create a Lexer and tokenize code
```cpp
#include <iostream>
#include "src/lexer.hpp"

int main() {
    std::string code = "let x = 42 + 5;";
    Lexer lexer(code);
    std::vector<Token> tokens = lexer.lex();
    for (const auto& token : tokens) {
        std::cout << "Token: " << token.value << " Type: " << token.type << std::endl;
    }
    return 0;
}
```

## Building
This project is standard C++ and requires no external dependencies. To build:

```
g++ -std=c++11 -o lexer src/lexer.cc src/main.cc
```

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Contributing
Contributions are welcome! Please open issues or pull requests for improvements, bug fixes, or new features. 