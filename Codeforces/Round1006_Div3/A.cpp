#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,k,p;cin >> n >> k >> p;
        // 21 100 10 // 
        if(abs(n*p) < abs(k)){
            cout << -1 << endl;
        }else{
            if(k%p == 0){ cout<< abs(k/p) << endl; }
            else {cout << abs(k/p) + 1 << endl;}
        }
    }
    return 0;

}
