#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    stack<int> ans;
    for(int i=0; i<n; i++){
        string s;cin>>s;
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            if(!ans.empty()){
                int se = ans.top(); ans.pop();
                int fi = ans.top(); ans.pop();
                if(s == "+") ans.push(fi+se);
                if(s == "-") ans.push(fi-se);
                if(s == "*") ans.push(fi*se);
                if(s == "/") ans.push(fi/se);
            }
        }else{
            ans.push(stoi(s));
        }
    }

    cout<<ans.top();
}
