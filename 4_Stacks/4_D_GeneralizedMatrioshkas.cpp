#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        stringstream secuencia(s);
        int n;

        stack<int> pila;
        bool valido = true;
        stack<int> sumas;

        while(secuencia>>n){
            if(n < 0){
                pila.push(abs(n));
                sumas.push(0);
            }
            else if ( n > 0 && !pila.empty()){
                if(pila.top() == n){
                    int suma = 0;
                    while(sumas.top()!=0){
                        suma += sumas.top();
                        sumas.pop();
                    }
                    sumas.pop();
                    sumas.push(n);
                    pila.pop();
                    
                    if(suma >= n){
                        valido = false;
                        break;
                    }
                }else{
                    valido = false;
                    break;
                }
            }else{
                valido =false;
                break;
            }
        }
        if (!pila.empty()) {
            valido = false;
        }

        if (valido) {
            cout << ":-) Matrioshka!" << endl;
        } else {
            cout << ":-( Try again." << endl;
        }
    }
}
