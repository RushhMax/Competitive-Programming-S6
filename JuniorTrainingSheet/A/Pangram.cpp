#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    set<char> alf;
    for(int i=0; i<s.size(); i++){
        alf.insert(tolower(s[i]));
    }
    if(alf.size() >= 26) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}
