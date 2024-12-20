#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;

    while(tc--){
        int k,p,s;
        cin>>k>>p>>s;

        double newPrize = (1.0*k*p/100)+ k;
        // 33 / 20 = 1.65 // 33 + 1.65 = 34.65
        // 33 * 5 = 165
        // 33 /  
        // 100/34.65 = 2.88
        int cont = s/newPrize;
        cout<<cont<<endl;
    }
    return 0;

}

// 33 100
// 0 105
