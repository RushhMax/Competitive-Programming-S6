#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l;cin>>n>>l;
    vector<int> lanterns(n);
    for(int i=0; i<n; i++)cin>>lanterns[i];

    sort(lanterns.begin(), lanterns.end());

    double maxDistancia = lanterns[0] - 0 > l - lanterns[n-1]? lanterns[0] - 0 : l - lanterns[n-1];
    for(int i=1; i<n; i++){
        maxDistancia = maxDistancia > (lanterns[i] - lanterns[i-1])/2? maxDistancia : (lanterns[i] - lanterns[i-1])/2.0;
    }

    cout<<fixed<<setprecision(10);
    cout<<maxDistancia<<endl;
    
}
