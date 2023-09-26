#include<iostream>
#include<cctype>

using namespace std;

int main(){
    char statement[12];

    // for Input
    //for(int i=0; i < 11; i++){
    //    cin >> statement[i] ;
    //}

    cout << "Provide input: " ;
    cin.getline(statement, 12);
    cout << endl;

    // for output
    /*
    cout << "Input String => " ;
    for(int i=0; i < 11; i++){
        cout << statement[i] ;
    }
    cout << endl;
    */

    int syntaxTableManagerIndex = 0;

    for(int i=0; i < 11; i++){
        //if (isalpha(statement[i]) || statement[i] == '+' || statement[i] == '-' || statement[i] == '*' || statement[i] == '/' || statement[i] == '%' || statement[i] == '=' || statement[i] == ';'){
        if (isalpha(statement[i])){
            cout << "<id," << syntaxTableManagerIndex++ << ">" << endl;
        }

            /*
        else if (isdigit(statement[i]))){
            cout << "<" << statement[i] << ">" << endl;
        }
        */

        else if (isdigit(statement[i]) || statement[i] == '+' || statement[i] == '-' || statement[i] == '*' || statement[i] == '/' || statement[i] == '%' || statement[i] == '=' || statement[i] == ';'){
            cout << "<" << statement[i] << ">" << endl;
            if(statement[i] == ';')
                break;
        }
        //}
    }


    return 0;
}
