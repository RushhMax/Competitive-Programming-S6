#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        int m, a,b,c;cin>>m>>a>>b>>c;
        int sit1 = 0, sit2 = 0;
        sit1 += min(a,m);
        sit2 += min(b,m);
        if(sit1 < m){
            int temp = min(m-sit1, c);
            sit1 += temp;
            c -= temp;
        }
        if(sit2 < m){
            sit2 += min(m-sit2, c);
        }
        
        cout<<sit1+sit2<<endl;
    }
}
