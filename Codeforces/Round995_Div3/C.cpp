#include <bits/stdc++.h>


using namespace std;

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n,m,k;
        cin>>n>>m>>k;

        vector<int> a(m);
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        vector<int> q(k);
        for(int i=0;i<k;i++){
            cin>>q[i];
        }

        set<int> notknow;
        int ant;
        for(int i=0;i<k;i++){
            if(i == 0 && q[i] != 1){
                notknow.insert(1);
            }
            if(i != 0 && q[i] != ant+1){
                notknow.insert(ant+1);
            }
            ant = q[i];
        }

        if(n == k){
            for(int i=0; i<a.size(); i++){
                cout<<"1";
            }
            cout<<endl;
            continue;
        }

        for(int i=0; i<a.size(); i++){
            if( notknow.find(a[i]) != notknow.end() && n-k <= 1){
                cout<<"1";                
            }else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
}
