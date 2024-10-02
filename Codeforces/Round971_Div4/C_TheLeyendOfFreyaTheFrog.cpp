#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void solve(){
    long long x,y,k;
    cin>>x>>y>>k;
    
    long long maxa = (x+k-1)/k;
    long long maxb = (y+k-1)/k;
    if(maxa > maxb)
        cout<<(maxa*2)-1<<endl;
    else
        cout<<maxb*2<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    for(int i=1; i<=t; i++){
        solve();
    }
}
