#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n, x;cin>>n>>x;
        // menore mayores y por ultimo el x;
        int falta = n;
        for(int i=0; i< n; i++){
            if(i < x){
                if(falta > 0){
                    cout<<i<<" ";
                    falta--;
                }
            }else if(i > x && falta > 1){
                cout<<i<<" ";
                falta--;
            }
        }
        if(falta == 1){
            cout<<x;
        }
        cout<<endl;
    }
}