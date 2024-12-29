#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;cin>>tc;
    while(tc--){
        int n,a,b,c; cin>>n>>a>>b>>c;
        int kilo[3] = {a,b,c};
        int sumaK = a+b+c;
        int i = 0;
        int j = (sumaK>= n? 0 : (n/sumaK)*3);
        int reco = (sumaK>= n? 0:((n/sumaK)*sumaK));

        while(reco < n){
            reco += kilo[i];
            i = (i+1)%3;
            j++;
        }

        cout<<j<<endl;

    }
}

