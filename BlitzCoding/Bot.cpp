#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        string s;
        getline(cin,s);

        stack<char> pila;
        int flags = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                flags++;
                pila.push(s[i]);
            }else if(s[i]==')'){
                if(flags > 1){
                    queue<char> aux;
                    while(!pila.empty()){
                        if(pila.top() != '('){
                            aux.push(pila.top());
                            pila.pop();
                        }else{
                            while(!aux.empty()){
                                pila.push(aux.front());
                                aux.pop();
                            }
                            break;
                        }
                    }
                    flags--;
                }else{
                    while(!pila.empty()){
                        if(pila.top()!='('){
                            cout<<pila.top();
                        }
                        pila.pop();
                    }
                    flags--;
                }
            }else if(flags>0){
                pila.push(s[i]);
            }else {
                cout<<s[i];
            }
        }

        cout<<endl;
    }
}
