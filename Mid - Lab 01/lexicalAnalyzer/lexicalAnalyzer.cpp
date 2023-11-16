#include<iostream>
#include<cctype>

using namespace std;

int main(){
    string statement; //To Store The String Data for Compiler Use
    int numberOfCharInStatement = 1; //To store size of statement
    int syntaxTableManagerIndex = 0; //Syntax table index manager
    int digitLengthCounter = 0; //Length of numeric variables
    
    // Taking input of statement
    cout << "Provide input: " ;
    getline(cin, statement);
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
            // Checking if the following character is Numeric or not. Else print Token
            if (!isdigit(statement[i+1])){
                string tempDigitStorage; // Temporary storage for the numeric variable
                // From the beginning of the numeric variable to the end of the variable the following loop will operate
                for (int x = (i - digitLengthCounter); x <= i; x++ ){
                    tempDigitStorage = tempDigitStorage + statement[x];
                }
                cout << "<" << tempDigitStorage << ">";
            }
            //If the immediate next index does not consist a digit, increase the digit length counter
            digitLengthCounter++;
        }
        
        // Check if the following is an operator or not
        else if (statement[i] == '+' || statement[i] == '-' || statement[i] == '*' 
                || statement[i] == '/' || statement[i] == '%' || statement[i] == '=' 
                || statement[i] == ';'){
                cout << "<" << statement[i] << ">";
                
                // Checking the end of a statement        
                if(statement[i] == ';'){
                    break;
                }
        }
    }
    return 0;
}
