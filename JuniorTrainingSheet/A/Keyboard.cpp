#include <bits/stdc++.h>

using namespace std;

int main(){
    string keyboard = ("qwertyuiopasdfghjkl;zxcvbnm,./");
    char dir;cin>>dir;
    string s;cin>>s;
    for(int i=0; i<s.size(); i++){
        if(dir == 'R') cout<<keyboard[keyboard.find(s[i])-1];
        else cout<<keyboard[keyboard.find(s[i])+1];
    }
}
