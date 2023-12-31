#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main(){
    string statement; //To Store The String Data for Compiler Use
    int numberOfCharInStatement = 1;
    int syntaxTableManagerIndex = 0;
    
    // Arrays to store necessary data regarding the tree generation
    string lexicalStatement;
    char variableReplacer[50];
    int childrenCounter[50];
    char syntaxTree[50];
    
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
            if (!isalpha(statement[i+1])){
                //string outputLexamOfIsAlphaPart1 = "<id,";
                //string outputLexamOfIsAlphaPart2 = to_string(syntaxTableManagerIndex++);
                //string outputLexamOfIsAlphaPart3 = ">";
                string outputLexamOfIsAlpha = "<id," + to_string(syntaxTableManagerIndex++) + ">";
                cout << outputLexamOfIsAlpha;
                lexicalStatement = lexicalStatement + outputLexamOfIsAlpha;
            }
        }
        
        /*   
        else if (isdigit(statement[i])){
            if (!isdigit(statement[i+1])){
                cout << "<" << statement[i-1] << statement[i] << ">";
            }
        }
        */
        
        else if (statement[i] == '+' || statement[i] == '-' || statement[i] == '*' || statement[i] == '/' || statement[i] == '%' || statement[i] == '=' || statement[i] == ';'){
            //char tempStorage = statement[i];
            if (statement[i] == '+'){
                string outputLexamOfIsOperator = "<+>";
                cout << outputLexamOfIsOperator;
                lexicalStatement = lexicalStatement + outputLexamOfIsOperator;
            }
            else if (statement[i] == '-'){
                string outputLexamOfIsOperator = "<->";
                cout << outputLexamOfIsOperator;
                lexicalStatement = lexicalStatement + outputLexamOfIsOperator;
            }
            else if (statement[i] == '*'){
                string outputLexamOfIsOperator = "<*>";
                cout << outputLexamOfIsOperator;
                lexicalStatement = lexicalStatement + outputLexamOfIsOperator;
            }
            else if (statement[i] == '/'){
                string outputLexamOfIsOperator = "</>";
                cout << outputLexamOfIsOperator;
                lexicalStatement = lexicalStatement + outputLexamOfIsOperator;
            }
            else if (statement[i] == '%'){
                string outputLexamOfIsOperator = "<%>";
                cout << outputLexamOfIsOperator;
                lexicalStatement = lexicalStatement + outputLexamOfIsOperator;
            }
            else if (statement[i] == '='){
                string outputLexamOfIsOperator = "<=>";
                cout << outputLexamOfIsOperator;
                lexicalStatement = lexicalStatement + outputLexamOfIsOperator;
            }
            else if (statement[i] == ';'){
                string outputLexamOfIsOperator = "<;>";
                cout << outputLexamOfIsOperator;
                lexicalStatement = lexicalStatement + outputLexamOfIsOperator;
                break;
            }
            /*
            //cout << "<" << statement[i] << ">";
            if(statement[i] == ';'){
                break;
            }
            */
        }
    }
    
    cout << endl;
    cout << endl;
    
    cout << "Lexical Statement => " << lexicalStatement;
    
    // ********************************
    // Lexical Analyzer ENDS here
    // ********************************
    
    // ********************************
    // Syntax Analyzer STARTS from here
    // ********************************
    
    char tempStatementForSyntaxAnalyzer[100];
    char statementForSyntaxAnalyzer[10];
    int tempStatementForSyntaxAnalyzerCounter = 0;
    int statementForSyntaxAnalyzerCounter = 0;
    
    for(char i : lexicalStatement){
        tempStatementForSyntaxAnalyzer[tempStatementForSyntaxAnalyzerCounter] = i;
        tempStatementForSyntaxAnalyzerCounter++;
        if(i == ';'){
            tempStatementForSyntaxAnalyzer[tempStatementForSyntaxAnalyzerCounter] = '>';
            break;
        }
    }
    
    /*
    cout << "Temp check => ";
    
    for(int i = 0 ; i < 101 ; i++){
        cout << tempStatementForSyntaxAnalyzer[i];
        if(i == ';'){
            cout << tempStatementForSyntaxAnalyzer[i+1];
            break;
        }
    }
    */

    for(int i = 0 ; i < 101 ; i++){
        if(tempStatementForSyntaxAnalyzer[i] == '<'){
            if(tempStatementForSyntaxAnalyzer[i+1] == 'i'){
                statementForSyntaxAnalyzer[statementForSyntaxAnalyzerCounter] = 'i';
                statementForSyntaxAnalyzerCounter++;
            }
        }
        
        else if(tempStatementForSyntaxAnalyzer[i] == '='){
            statementForSyntaxAnalyzer[statementForSyntaxAnalyzerCounter] = tempStatementForSyntaxAnalyzer[i];
            statementForSyntaxAnalyzerCounter++;
        }
        
        else if(tempStatementForSyntaxAnalyzer[i] == '+'){
            statementForSyntaxAnalyzer[statementForSyntaxAnalyzerCounter] = tempStatementForSyntaxAnalyzer[i];
            statementForSyntaxAnalyzerCounter++;
        }
        
        else if(tempStatementForSyntaxAnalyzer[i] == ';'){
            statementForSyntaxAnalyzer[statementForSyntaxAnalyzerCounter] = tempStatementForSyntaxAnalyzer[i];
            statementForSyntaxAnalyzerCounter++;
            if(i == ';'){
                break;
            }
        }
    }
    
    cout << endl;
    cout << endl;
    
    cout << "Statement Prepared for Syntax Analyzer => ";
    
    for(int i = 0 ; i < 11 ; i++){
        cout << statementForSyntaxAnalyzer[i];
        if(statementForSyntaxAnalyzer[i] == ';'){
            break;
        }
    }
    
    char rule1 = {'A', '-', '>', 'B', 'C', 'D', 'E', 'D', 'F', ';'};
    char rule2 = {'B', '-', '>', 'i'};
    char rule3 = {'C', '-', '>', '='};
    char rule4 = {'D', '-', '>', 'i'};
    char rule5 = {'D', '-', '>', '0'};
    char rule6 = {'D', '-', '>', '1'};
    char rule7 = {'D', '-', '>', '2'};
    char rule8 = {'D', '-', '>', '3'};
    char rule9 = {'D', '-', '>', '4'};
    char rule10 = {'D', '-', '>', '5'};
    char rule11 = {'D', '-', '>', '6'};
    char rule12 = {'D', '-', '>', '7'};
    char rule13 = {'D', '-', '>', '8'};
    char rule14 = {'D', '-', '>', '9'};
    char rule15 = {'E', '-', '>', '+'};
    char rule16 = {'E', '-', '>', '-'};
    char rule17 = {'E', '-', '>', '*'};
    char rule18 = {'E', '-', '>', '/'};
    char rule19 = {'E', '-', '>', '%'};
    char rule20 = {'F', '-', '>', ';'};
    
    return 0;
}