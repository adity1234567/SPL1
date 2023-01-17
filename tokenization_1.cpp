#include <iostream>
#include <vector>
#include <ctype.h>
#include <cstring>

#define NL std::endl

/**
 * Lexer class for simple math expressions.
 * Recognizes only integer numbers and symbols
 * (operators and grouping).
 */
class Lexer {

private:
    char* m_source;
    int   m_sourceLength;
    int   m_cursor;
    char  m_currentChar;

    void  readNextChar();
    void  skipWhiteSpaces();
    char* readNumber();
    char* readSymbol();

public:
    Lexer(char* source);

    bool isEOF();
    char* readNextToken();
    static std::vector<char*> tokenize(char*);
};

// ---------------------------------
// Lexer implementation.
// ---------------------------------

Lexer::Lexer(char* source) {
    m_source = source;
    m_sourceLength = strlen(source);
    m_cursor = 0;

    readNextChar();
}

bool Lexer::isEOF() {
    return m_cursor > m_sourceLength;
}

/**
 * Reads next char advancing cursor.
 */
void Lexer::readNextChar() {
    skipWhiteSpaces();

    if (isEOF()) {
        m_currentChar = '\0';
        return;
    }

    m_currentChar = m_source[m_cursor++];
}

/**
 * Reads next token: a number or a symbol.
 */
char* Lexer::readNextToken() {
    if (isdigit(m_currentChar))
        return readNumber();

    return readSymbol();
}

/**
 * Reds a number containing digits.
 */
char* Lexer::readNumber() {
    char* number = new char[20];
    int i = 0;
    while (isdigit(m_currentChar)) {
        number[i++] = m_currentChar;
        readNextChar();
    }
    return number;
}

/**
 * Reads a symbol (operator or grouping).
 */
char* Lexer::readSymbol() {
    char* symbol = new char[1];
    symbol[0] = m_currentChar;
    readNextChar();
    return symbol;
}

void Lexer::skipWhiteSpaces() {
    while (isspace(m_source[m_cursor]))
        m_cursor++;
}

/**
* Tokenizes a source expression, returns
* a vector with the tokens.
*/
std::vector<char*> Lexer::tokenize(char* source) {
    std::vector<char*> tokens;
    Lexer lexer(source);
    do {
        tokens.push_back(lexer.readNextToken());
    } while (!lexer.isEOF());
    return tokens;
}

void printTokens(std::vector<char*> tokens) {
    std::cout << "Tokens: [";
    unsigned int size = tokens.size();
    for (unsigned int k = 0; k < size; k++) {
        std::cout << tokens[k] ;
        if (k < size - 1) std::cout << ", ";
    }
    std::cout << "]" << NL << NL;
}

void showExample()
{
    char* example = "15 * (3 + 17)";
    std::cout << "Math expression lexer." << NL << NL;
    std::cout << "Example: " << example << NL;
    printTokens(Lexer::tokenize(example));
}

int main()
{
    showExample();

    char* expression = new char[100];

    std::cout << "Enter expression: ";
    std::cin.getline(expression, 100);

    printTokens(Lexer::tokenize(expression));
    return 0;
}
