#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;cin>>tc;
    while(tc--){
        int a,b,l,n;cin>>a>>b>>l>>n;
        int ans = 0;

        ans += 2*l + b*(n-1)*2 + a*(n*2-1);
        cout<<ans<<endl;
    }

}
