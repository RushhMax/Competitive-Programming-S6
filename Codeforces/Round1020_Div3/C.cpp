#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,k;cin>>n>>k;
        vector<int> a(n), b(n);

        int menor = INT_MAX, mayor = -1;
        for(int i=0; i<n ;i++){
            cin>>a[i];
            if(a[i] < menor) menor = a[i];
            if(a[i] > mayor) mayor = a[i];
        }

        for(int i=0; i<n ;i++){
            cin>>b[i];
        }
        
        int ans = -1;
        int suma = -1;
        for(int i=0;  i<n ; i++){
            if(b[i] != -1){
                if(suma == -1){
                    suma = a[i] + b[i];
                }else if(suma != (a[i] + b[i])){
                    ans = 0;
                    break;
                }
            }
        }

        if(ans == 0) { 
            cout<<0<<endl;
            continue;
        }
        if(suma == -1){
            cout<<(menor+k)-mayor+1<<endl;
        }else{
            bool flag = true;
            for(int i=0;  i<n ; i++){
                if(a[i] > suma) { 
                    flag = false;
                    break;
                }
                if(a[i] + k >= suma) continue;
                flag = false;
                break;
            }
            if(flag) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}