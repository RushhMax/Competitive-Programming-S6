#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll factorial(ll n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n, d;cin>>n>>d;
        ll fact = factorial(n);
        cout<<fact<<endl;
        cout<<1<<" ";
        if(fact*d % 3 == 0){ cout<<3<<" ";}
        if(d % 5 == 0){ cout<<5<<" ";}
        if(fact*)
        if(fact*d % 9 == 0){cout<<9;}
        cout<<endl;
    }
}
