#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;cin>>tc;
    while(tc--){
        int x;cin>>x;

        if(x>0) cout<<1<<endl;
        else if(x<0) cout<<-1<<endl;
        else cout<<0<<endl;
    }
}
