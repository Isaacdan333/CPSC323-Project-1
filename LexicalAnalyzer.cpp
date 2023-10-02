/*
    Project: CPSC 323 - Project 1
    Group members: Hao Ly, Darren Cruz, Isaac Perez
    Program: Lexical Analyzer
    Input file: input_scode.txt
    Output file: output.txt
    Language: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Define different types of token
enum TokenType {
    Keyword,
    Separator,
    Identifier,
    Operator,
    Real,
    Unknown
};

// Type of token & lexeme
struct Lexical {
    TokenType token;
    string lexeme;
};

// Function to check if a character is a whitespace
bool isWhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

// Function to check if a character is a terminating character (It means the end of our code or tokens)
bool isTerminatingChar(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == ';' || c == '}');
}

// Lexical Analyzer
vector<Lexical> lexer(const string& inputCode) {
    vector<Lexical> tokens;

    int currentPos = 0; // Keep track the index of each character in our code
    int codeLength = inputCode.length();

    while (currentPos < codeLength) {
        char currentChar = inputCode[currentPos];

        // Skip whitespace characters
        if (isWhitespace(currentChar)) {
            currentPos++;
            continue;
        }

        string lexeme;
        TokenType tokenType = Unknown;

        // Check if the current character is a separator
        if (currentChar == '(' || currentChar == ')' || currentChar == ';' || currentChar == '{' || currentChar == '}') {
            tokenType = Separator;
            lexeme = currentChar;
            currentPos++;
        }

        // Check if the current character is an operator
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '=' || currentChar == '<' || currentChar == '>') {
            tokenType = Operator;
            lexeme = currentChar;
            currentPos++;
        }

        // Check if the current character is a digit (real number)
        else if (isdigit(currentChar)) {
            while (currentPos < codeLength && (isdigit(currentChar) || currentChar == '.')) {
                lexeme += currentChar;
                currentChar = inputCode[++currentPos];
            }
            tokenType = Real;
        }

        // Check if the current character is a letter (identifier or keyword)
        else if (isalpha(currentChar) || currentChar == '_') {
            while (currentPos < codeLength && (isalnum(currentChar) || currentChar == '_')) {
                lexeme += currentChar;
                currentChar = inputCode[++currentPos];
            }

            // Check if the lexeme is a keyword
            if (lexeme == "while" || lexeme == "if" || lexeme == "else" || lexeme == "for") {
                tokenType = Keyword;
            } 
            else {
                tokenType = Identifier;
            }
        }

        // Add the token to the list
        tokens.push_back({ 
            tokenType, 
            lexeme 
        });
    }

    return tokens;
}

int main() {
    ifstream inputFile("input_scode.txt");
    if (!inputFile) {
        cerr << "Failed to open the input file!" << endl;
        return 1;
    }

    // Read the entire input file into a string
    string inputCode((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Tokenize the input string
    vector<Lexical> tokens = lexer(inputCode);

    // Open the output file for writing
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Failed to open the output file!" << endl;
        return 1;
    }

    // Write the header
    outputFile << "+-------------------+-------------------+" << endl;
    outputFile << "|       Token       |       Lexeme      |" << endl;
    outputFile << "+-------------------+-------------------+" << endl;

    // Write the tokens and lexemes
    for (const Lexical& token : tokens) {
        outputFile << "| " << setw(18) << left;
        switch (token.token) {
            case Keyword:
                outputFile << "Keyword";
                break;
            case Separator:
                outputFile << "Separator";
                break;
            case Identifier:
                outputFile << "Identifier";
                break;
            case Operator:
                outputFile << "Operator";
                break;
            case Real:
                outputFile << "Real";
                break;
            case Unknown:
                outputFile << "Unknown";
                break;
        }
        outputFile << "| " << setw(17) << left << token.lexeme << " | " << endl;
    }
    outputFile << "+-------------------+-------------------+" << endl;

    // Close the output file
    outputFile.close();

    cout << "Lexical analysis completed. Results written to 'output.txt'." << endl;
    return 0;
}
