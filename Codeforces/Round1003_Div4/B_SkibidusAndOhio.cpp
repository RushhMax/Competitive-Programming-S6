#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;cin>>tc;
    while(tc--){
        string s;cin>>s;
        bool flag = false;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]) {
                cout<<1<<endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout<<s.size()<<endl;
    }
    return 0;
}
