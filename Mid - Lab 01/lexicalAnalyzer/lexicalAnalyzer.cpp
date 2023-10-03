#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main(){
    string statement; //To Store The String Data for Compiler Use
    int numberOfCharInStatement = 1; //To store size of statement
    int syntaxTableManagerIndex = 0; //Suntax table index manager
    //string temporaryNumericCharacterStorage;
    
    // Taking input of statement
    cout << "Provide input: " ;
    getline(cin, statement); //Requires cctype library
    cout << endl;
    
    // Print statement provided
    cout << "Input String => " << statement << endl;
    
    // Counting the number of characters by using foreach
    for(char i : statement){
        numberOfCharInStatement++;
        // Checking the end of a statement
        if(i == ';'){
            break;
        }
    }
    
    cout << endl;
    
    // Result section
    cout << "Lexical Result => " ;
    
    // Checking characters one by one
    for(int i=0; i < numberOfCharInStatement; i++){
        // Check if the character is Alphabatic of not
        if (isalpha(statement[i])){
            // Checking if the following character is Alphabatic or not. Else print Token
            if (!isalpha(statement[i+1])){
                cout << "<id," << syntaxTableManagerIndex++ << ">";
            }
        }
        
        // Check if the the following character is Numeric or not
        else if (isdigit(statement[i])){
            string temporaryNumericCharacterStorage;
            // Checking if the following character is Numeric or not. Else print Token
            if (!isdigit(statement[i+1])){
                cout << "<" << temporaryNumericCharacterStorage << ">";
                /*
                if (statement[i-1] == '+' || statement[i-1] == '-' || statement[i-1] == '*' || statement[i-1] == '/' || statement[i-1] == '%' || statement[i-1] == '='){
                    cout << "<" << statement[i] << ">";
                }
                else{
                    cout << "<" << statement[i-1] << statement[i] << ">";
                }
                */
            }
        }
        
        // Check if the following is an operator or not
        else if (statement[i] == '+' || statement[i] == '-' || statement[i] == '*' || statement[i] == '/' || statement[i] == '%' || statement[i] == '=' || statement[i] == ';'){
            cout << "<" << statement[i] << ">";
            // Checking the end of a statement
            if(statement[i] == ';'){
                break;
            }
        }
    }
    return 0;
}
