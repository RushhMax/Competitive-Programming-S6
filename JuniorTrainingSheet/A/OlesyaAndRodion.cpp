#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;cin>>n>>t;
    
    for(int i=0; i<n; i++){
        if(t == 10){
            if(n-1 == 0){ cout<<-1; break;}
            if(i == n-1){ cout<<0; }
            else cout<<1;
        }else{
            cout<<t;
        }
    }
    cout<<endl;
    return 0;
}
