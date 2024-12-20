#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string expression;
    cin >> expression;

    int i ;
    for(i=0; i<expression.size(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            break;
        }
    }

    string fNumber = expression.substr(i+1);
    string sNumber = expression.substr(0,i);

    int firstNumber = stoi(fNumber);
    int secondNumber = stoi(sNumber);

    char c = expression[i];
    if(c == '+'){
        cout<<firstNumber + secondNumber<<endl;
    }else if(c == '-'){
        cout<<secondNumber - firstNumber <<endl;
    }else if(c == '*'){
        cout<<firstNumber * secondNumber<<endl;
    }else if(c == '/'){
        cout<<static_cast<int> (secondNumber/ firstNumber)<<endl;
    }

    


    return 0;
}
