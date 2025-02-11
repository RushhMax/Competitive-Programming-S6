#include <bits/stdc++.h>

#define pll pair<long long, long>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k; cin>>n>>k;
    priority_queue<pll> pq;
    for(int i=0; i<n; i++){
        ll a,b; cin>>a>>b;
        pq.push({b,a-b});
    }

    ll ans = 0;
    while(k--){
        pll top = pq.top();
        ans += top.first;
        pq.push({top.second,0});
        pq.pop();
    }

    cout<<ans<<endl;
}
