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

using namespace std;

//Lexer Pseudocode
/*
function lexer()
{
    repeat
        getchar();
        if input char terminates a token
            AND it is an accepting state then
                isolate the token/lexeme
                decrement the CP if necessary
        else lookup FSM (current state, input char);
    until (token found) or (no more input)

    if token found then
        return(token)
}
*/

// Our code
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
    regex realnumber_regex("[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?");
    regex operator_regex("[+\\-*/=]");

    // Works from here
    // ....
}

// Main function 
int main() {
    ifstream inputFile;
    inputFile.open("input_scode.txt");

    if (!inputFile) {
        cerr << "Failed to open the input file!" << endl;
        return 1;
    }

    ofstream outfile("output.txt");
    outfile << "+------------+---------------------+" << endl;
    outfile << "|   Token    |       Lexeme        |" << endl;
    outfile << "+------------+---------------------+" << endl;

    // Works from here
    // ....
}


//input_scode.txt

/*
while(t<upper)s=22.00;

output:
Token       Lexeme
keyword     while
separator   (
identifier  t
operator    <
identifier  upper
separator   )
identifier  s
operator    =
real        22.00
separator   ;
*/
