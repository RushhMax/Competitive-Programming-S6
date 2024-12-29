#include<bits/stdc++.h>

#define ll long long

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;cin>>tc;
    while(tc--){
        ll i, j;cin>>i>>j;

        if(max(i,j) == i){
            if(i%2==0){
                ll top = pow(i,2);
                cout<<top-j+1<<endl;
            }else{
                ll down = pow(i-1,2);
                cout<<down+j<<endl;
            }
        }else{
            if(j%2==0){ 
                ll down = pow(j-1,2);
                cout<<down+i<<endl;
            }else{ 
                ll top = pow(j,2);
                cout<<top-i+1<<endl;
            }
        }
    }
}
