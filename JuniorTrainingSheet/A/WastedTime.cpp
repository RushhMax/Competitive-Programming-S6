#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, k;
    cin>>n>>k;
    double signatureSize = 0;
    int x1, y1; cin>>x1>>y1;
    for(int i=0; i<n-1; i++){
        int x, y;cin>>x>>y;
        signatureSize += sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
        x1 = x;
        y1 = y;
    }
    cout<<fixed<<setprecision(6)<<(signatureSize/50)*k<<endl;
}
