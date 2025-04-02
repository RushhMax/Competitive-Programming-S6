#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll sum(ll k){
    return k*(k+1)/2;
}

ll sum(ll s, ll e){
    if(s <= 1) return sum(e);
    return sum(e) - sum(s-1);
}

ll minSpli(ll n, ll k){
    ll l = 1, u = k;
    while(l < u){ // 1 2 3 4 5 6 7 8 9 10
        ll m = (l+u)/2;
        ll s = sum(m,k);

        if(s == n) return k-m+1;
        if(s > n) l = m+1; //r              
        else u = m; //l
    }
    return k-l+2;
}

int main(){
    ll n, k;
    cin>>n>>k;
    
    if(n == 1) cout<<0<<endl;
    else if( k >= n) cout<<1<<endl;
    else{
        k--; n--;
        
        if(sum(k) < n) cout<<-1<<endl;
        else cout<<minSpli(n, k)<<endl;
    }
}

/*

#include<iostream>
using namespace std;

int o,m;
long long n,k=1;

int main(){
	cin>>n>>m;
	while(m-o && k<n)o++,k+=m-o;
	if(k>=n)cout<<o;else cout<<-1;
}
 */
