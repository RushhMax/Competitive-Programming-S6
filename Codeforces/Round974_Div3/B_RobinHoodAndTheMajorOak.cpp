#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    
    cout<<(((n+1)*n/2 - (n-k)*(n-k+1)/2)  % 2 ? "NO" : "YES")<<endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}
