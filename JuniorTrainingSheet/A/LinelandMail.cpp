#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> cities(n);
    for(int i=0; i<n; i++){ cin>>cities[i];}
    
    for(int i=0; i<n; i++){
        cout<<(i==0? cities[1]-cities[0] : i==n-1? cities[i]-cities[i-1]:min(cities[i+1]-cities[i],cities[i]-cities[i-1]))<<" ";
        cout<<(i==0? cities[n-1]-cities[0] : i==n-1? cities[i]-cities[0]:max(cities[n-1]-cities[i], cities[i]-cities[0]))<<endl;

    }
    return 0;
}
