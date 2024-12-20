#include <bits/stdc++.h>

using namespace std;

map<char, char> pares = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;cin>>tc;
    while(tc--){
        string s;cin>>s;
        stack<char> pila;

        bool flag = true;
        for(char c:s){
            if(c == '(' || c == '[' || c=='{'){
                pila.push(c);
            }else if(!pila.empty() && pares[pila.top()] == c  ){
                //cout<<c<<" "<<pila.top()<<" "<<pares[pila.top()]<<endl;
                pila.pop();
            }else{
                pila.push(c);
            }
        }

        if(pila.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

// {(([])[])[]]}
// {]}
