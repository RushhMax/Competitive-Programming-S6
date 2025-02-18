#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        ll n;cin>>n;
        stack<pair<ll,int>> coins;
        ll ans = 0;
        coins.push({n,1});
        while(coins.size() > 0){
            pair<ll,int> x = coins.top();
            coins.pop();
            if(x.first > 3){
                coins.push({x.first/4, x.second*2});
            }else{
                ans+=x.second;
            }
        }
        cout<<ans<<endl;
    }

}
