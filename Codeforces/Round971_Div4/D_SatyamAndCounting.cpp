#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define vp vector<pair<int, int>>

void solve(){
    int n;
    cin>>n;

    vp point;
    int nzeros = 0, nones = 0;
    for(int i=0; i<n;i++){
        int x, y;
        cin>>x>>y;
        point.push_back(make_pair(x, y));
        if(y==0){
            nzeros++;
        }else if(y==1){
            nones++;
        }
    }

    if(nones==0 || nzeros==0){
        cout<<0<<endl;
    }else{
        cout<<(nones+nzeros)-1<<endl;
    }
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
