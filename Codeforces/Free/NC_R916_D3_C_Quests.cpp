#include <bits/stdc++.h>

using namespace std;

int max_F(vector<int> a, vector<int> b, int n ,int level, int k, int maxLevel){
    if(level >= n || k == 0) return 0;

    if(level == -1){
        return a[0] + max_F(a, b,n, 0, k-1, maxLevel);
    }
    if(b[level]>maxLevel) maxLevel = b[level];

    int stay = max_F(a, b,n,level, k-1, maxLevel) + maxLevel;
    if(level == n-1) return stay;
    int next = max_F(a, b, n, level+1, k-1, maxLevel) + a[level+1];

    return max(stay, next);
}

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    
    cout<<max_F(a,b,n,-1, k,0)<<endl;
}


int main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}
