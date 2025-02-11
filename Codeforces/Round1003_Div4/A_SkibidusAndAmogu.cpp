#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string s;cin>>s;
        cout<<s.substr(0, s.size()-2)<<"i"<<endl;
    }
    return 0;
}
