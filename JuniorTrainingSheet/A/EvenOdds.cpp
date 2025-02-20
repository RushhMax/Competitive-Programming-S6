#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n, k;cin>>n>>k;
    ll middle = (n+1)/2;
    if(k > middle){ // par
        cout<<2*(k-middle)<<endl;
    }else{
        cout<<(2*k)-1<<endl;
    }
    return 0;
}
