#include<iostream>
#include<list>
#include <stack>
using namespace std;

void fix(string s){
    list<char> str;
    bool dir = 1;
    stack<char> pila;
    for(int i=0; i<s.size();i++){
        if(s[i] == '['){
            while(!pila.empty()){
                str.push_front(pila.top());
                pila.pop();
            }
            dir = false;
        }else if(s[i] == ']'){
            while(!pila.empty()){
                str.push_front(pila.top());
                pila.pop();
            }
            dir = true;
        }else{
            if(dir) str.push_back(s[i]);
            else {
                pila.push(s[i]);
            }
        }
    }
    while(!pila.empty()){
        str.push_front(pila.top());
        pila.pop();
    }
    
    for(char c : str){
        cout<<c;
    }
    cout<<endl;
}

int main(){
    string s;
    while(getline(cin, s)){
        fix(s);
    }
}
