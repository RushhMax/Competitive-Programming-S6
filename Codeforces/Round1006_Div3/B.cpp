#include <bits/stdc++.h>

#define ll long long

using namespace std;
 

int main(){
    int tc;cin>>tc;
    while(tc--){
        ll n;cin>>n;
        string s;cin>>s;
        ll down = 0;
        ll up = 0;
        for(ll i=0; i<n; i++){
            if(s[i] == '_'){ down++;}
            else up++;
        }

        ll ans = (up/2)*(up-(up/2))*down;
        cout<<ans<<endl;
        // 111
        // 1111 // 8 + 2 + 4 + 1 = 15
    }
    return 0;
}
