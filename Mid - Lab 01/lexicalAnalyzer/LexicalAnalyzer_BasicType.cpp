#include<iostream>
#include<cctype>

using namespace std;

int main(){
    string statement; //To Store The String Data for Compiler Use
    int numberOfCharInStatement = 1;
    int syntaxTableManagerIndex = 0;
    
    cout << "Provide input: " ;
    getline(cin, statement);
    cout << endl;
    
    cout << "Input String => " << statement << endl;
    
    // counting the number of characters
    for(char i : statement){
        numberOfCharInStatement++;
        if(i == ';'){
            break;
        }
    }
    
    cout << endl;

    for(int i=0; i < numberOfCharInStatement; i++){
        if (isalpha(statement[i])){
            cout << "<id," << syntaxTableManagerIndex++ << ">";
        }
        
        else if (isdigit(statement[i])){
            cout << "<" << statement[i] << ">";
        }
        
        else if (statement[i] == '+' || statement[i] == '-' || statement[i] == '*' || statement[i] == '/' || statement[i] == '%' || statement[i] == '=' || statement[i] == ';'){
            cout << "<" << statement[i] << ">";
            if(statement[i] == ';'){
                break;
            }
        }
    }
    return 0;
}

