#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,m;cin>>n>>m;

        vector<int> a(n);
        vector<int> b(m);

        for(int i=0 ; i<n ;i++)cin>>a[i];
        for(int i=0 ;i<m ; i++)cin>>b[i];

        int fallo = 0;
        int valorF = 0;
        int ai = 0, bi = 0;
        int lastb = 0;
        while(ai < n){
            if(b[bi] <= a[ai]){
                bi++;
                lastb = ai;
            }
            ai++;
            if(ai == n && bi < m-1){
                ai = lastb;
                fallo++;
                valorF = bi;
            }
        }
        
        if(fallo == 0) cout<<0<<endl;
        if(fallo == 1){
            cout<<valorF<<endl;
        }
        if(fallo > 1) cout<<-1<<endl;
    }
}