/*
    Project: CPSC 323 - Project 1
    Group members: Hao Ly, ..., ...
    Program: Lexical Analyzer
    Input file: input_scode.txt
    Output file: output.doc
    Language: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

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

// Function takes a string code as input and returns a vector of Token objects
vector<Lexical> tokenize(const string& code) {
    vector<Lexical> tokens;
    regex keyword_regex("while|if|else|for");
    regex separator_regex("[(),;{}]");
    regex identifier_regex("[a-zA-Z_][a-zA-Z0-9_]*");
    regex realnumber_regex("[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?");
    regex operator_regex("[+\\-*/=<>,]");

    // Initialize start and end positions
    int start = 0;
    int end = 0;

    while (end < code.length()) {
        // Find the next space or end of the string
        end = code.find(" ", start);

        // If no space is found, set end to the end of the string
        if (end == string::npos) {
            end = code.length();
        }

        // Extract the substring
        string lexeme = code.substr(start, end - start);
        Lexical lex;

        // Check for token type
        if (regex_match(lexeme, keyword_regex)) {
            lex.token = Keyword;
        } 
        else if (regex_match(lexeme, separator_regex)) {
            lex.token = Separator;
        } 
        else if (regex_match(lexeme, identifier_regex)) {
            lex.token = Identifier;
        } 
        else if (regex_match(lexeme, realnumber_regex)) {
            lex.token = Real;
        } 
        else if (regex_match(lexeme, operator_regex)) {
            lex.token = Operator;
        } 
        else {
            lex.token = Unknown;
        }

        lex.lexeme = lexeme;
        tokens.push_back(lex);

        // Update start position for the next iteration
        start = end + 1;
    }

    return tokens;
}

int main() {
    ifstream inputFile;
    inputFile.open("input_scode.txt");

    if (!inputFile) {
        cerr << "Failed to open the input file!" << endl;
        return 1;
    }

    // Read the entire input file into a string
    string input_str((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    // Open the output file for writing
    ofstream outfile("output.txt");
    outfile << "+-------------------+-------------------+" << endl;
    outfile << "|       Token       |       Lexeme      |" << endl;
    outfile << "+-------------------+-------------------+" << endl;

    // Tokenize the input string
    vector<Lexical> tokens = tokenize(input_str);

    // Process and write tokens to the output file
    for (const Lexical& token : tokens) {
        string tokenTypeStr;

        switch (token.token) {
            case Keyword:
                tokenTypeStr = "Keyword";
                break;
            case Separator:
                tokenTypeStr = "Separator";
                break;
            case Identifier:
                tokenTypeStr = "Identifier";
                break;
            case Real:
                tokenTypeStr = "Real";
                break;
            case Operator:
                tokenTypeStr = "Operator";
                break;
            case Unknown:
                tokenTypeStr = "Unknown";
                break;
        }
        outfile << "|           " << tokenTypeStr << "      |       " << token.lexeme << "      |" << endl;
    }

    inputFile.close();
    outfile.close();
    return 0;
}
