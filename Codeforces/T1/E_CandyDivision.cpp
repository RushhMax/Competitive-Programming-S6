#include <bits/stdc++.h>

using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,k;cin>>n>>k;
    
        cout<<(n%k == 0? 0 : k-(n%k))<<endl;
    }
    return 0;
}
