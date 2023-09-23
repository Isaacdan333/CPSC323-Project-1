#include <iostream>
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


int main()
{
    cout << "Hello, world!\n";
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