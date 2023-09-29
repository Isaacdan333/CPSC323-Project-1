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
    
    //break the "code" string into smaller pieces using " " as delimiter.
    int start = 0;
    int end = code.find(" ");

    //While not at end of "code" string
    while (end != -1)
    {

        //save the substring as "lexeme" and create a Lexical object
        string lexeme = code.substr(start, end-start);
        Lexical lex;
        
        //If the substring is a keyword, push the string as a Keyword into "tokens"
        if (regex_match(lexeme, keyword_regex))
        {
            lex.token = Keyword;
            lex.lexeme = lexeme;
            tokens.push_back(lex);
        }

        //If the substring is a separator, push the string as a Separator into "tokens"
        else if (regex_match(lexeme, separator_regex))
        {
            lex.token = Separator;
            lex.lexeme = lexeme;
            tokens.push_back(lex);
        }

        //If the substring is a identifier, push the string as a Identifier into "tokens"
        else if (regex_match(lexeme, identifier_regex))
        {
            lex.token = Identifier;
            lex.lexeme = lexeme;
            tokens.push_back(lex);
        }

        //If the substring is a real, push the string as a Real into "tokens"
        else if (regex_match(lexeme, realnumber_regex))
        {
            lex.token = Real;
            lex.lexeme = lexeme;
            tokens.push_back(lex);
        }

        //If the substring is a operator, push the string as a Operator into "tokens"
        else if (regex_match(lexeme, operator_regex))
        {
            lex.token = Operator;
            lex.lexeme = lexeme;
            tokens.push_back(lex);
        }

        //If the substring is unknown, push the string as a Unknown into "tokens"
        else
        {
            lex.token = Unknown;
            lex.lexeme = lexeme;
            tokens.push_back(lex);
        }
    }

    return tokens;
}

// Main function 
int main() {
    ifstream inputFile;
    inputFile.open("input_scode.txt");

    if (!inputFile) {
        cerr << "Failed to open the input file!" << endl;
        return 1;
    }

    // reads input string form the input file
    string input_str;
    getline(inputFile, input_str);
    vector<Lexical> Tokens = tokenize(input_str);

    // will print tokens to output.txt
    ofstream outfile("output.txt");
    outfile << "+------------+---------------------+" << endl;
    outfile << "|   Token    |       Lexeme        |" << endl;
    outfile << "+------------+---------------------+" << endl;

    // Works from here
    // ....
}


//input_scode.txt

/*
while ( t < upper ) s = 22.00;

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
