#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int n;cin>>n; //500000
    string s;cin>>s; 
    ll sum1 = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '1') sum1++;
    }

    // 010100100   1
    ll ans = 0;
    ll sumaP1 = 0; 
    for(int indL = 0;indL<n; indL++){
        if(s[indL] == '1'){
            sumaP1++;
        }else {
            ans += min(sumaP1, sum1-sumaP1);

        }
    }
    cout<<ans<<endl;
    return 0;
}
