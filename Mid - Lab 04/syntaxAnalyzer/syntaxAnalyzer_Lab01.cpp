#include <iostream>

using namespace std;

int main()
{
    string inputToken;
    
    cout << "Provide the token: " ;
    getline(cin, inputToken);
    cout << endl;
    cout << "The token provided: " << inputToken << endl;
    
    char statement[10];
    int inputTokenIndex;
    int statementIndex = 0;
    for(inputTokenIndex = 0; inputTokenIndex < inputToken.length(); inputTokenIndex++){
        if(inputToken[inputTokenIndex] == '<'){
            statement[statementIndex] = inputToken[inputTokenIndex+1];
            statementIndex++;
        }
    }
    
    cout << endl;
    cout << "The generated statement from the token: " << statement << endl;
    
    return 0;
}