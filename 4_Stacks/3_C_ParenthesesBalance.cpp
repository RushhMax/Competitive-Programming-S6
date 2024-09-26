#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        stack<char> pila;
        bool valido = true;
    
        for(char a : s){
            if(a == '(' || a == '['){
                pila.push(a);
            }
            else if(a == ')'){
                if(!pila.empty() && pila.top() == '('){
                    pila.pop();
                } else {
                    valido = false;
                    break; // Salir del ciclo si no es válido
                }
            }
            else if(a == ']'){
                if(!pila.empty() && pila.top() == '['){
                    pila.pop();
                } else {
                    valido = false;
                    break; // Salir del ciclo si no es válido
                }
            }
        }

        if(pila.empty() && valido) 
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
}
