#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;cin>>n;
    multimap<int,bool> customers;
    for(int i=0; i<n; i++){
        int a,b;cin>>a>>b;
        customers.insert({a,true});
        customers.insert({b,false});
    }

    int cont = 0;
    int max = 0;

    for(auto it = customers.begin(); it!=customers.end(); it++){
        if((*it).second) cont++;
        else cont--;
        if(cont > max) max = cont;
    }

    cout<<max<<endl;


    return 0;
}
