#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;

    while(tc--){
        int n;cin>>n;
        vector<int> a(n);
        vector<int> b(n+1);        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        b[n] = 0;

        int suma = 0;
        for(int i=0;i<n;i++){
            if(a[i] > b[i+1]){
                suma += (a[i] - b[i+1]);
            }
        }
        cout<<suma<<endl;


    }
}
