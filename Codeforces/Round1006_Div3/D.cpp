#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int l = 0, r = 0;
        vector<int> b(n);
        for(int i=0; i<n; i++) {
            int suma = 0;
            for(int j=i+1; j<n; j++){
                if(a[i] > a[j]){
                    suma++;
                }
            }
            b[i] = suma;
            if(suma > b[l]) l = i;
        }

        //for(int i=n-1; i)

        //7   1 4 3 2 5 3 3 // 2 7
        // 1 4 3 2 5 3 3 
        // 1 3 2 5 4 3 3  // 4
        // 1 3 2 5 3 4

        cout<<l<<" "<<r<<endl;
    }
    return 0;
}
