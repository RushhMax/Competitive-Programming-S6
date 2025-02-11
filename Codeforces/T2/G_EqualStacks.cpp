#include "bits/stdc++.h"

#define f(i,n) for(int i=0; i<n; i++)
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2,n3;
    cin>>n1>>n2>>n3;
    stack<int> s1,s2,s3;

    f(i,n1){
        int x; cin>>x;
        s1.push(x);
    }

    f(i,n2){
        int x; cin>>x;
        s2.push(x);
    }

    f(i,n3){
        int x;cin>>x;
        s3.push(x);
    }

    map<ll,ll> mp;
    ll ant = 0;
    while(!s1.empty()){
        ant += s1.top();
        s1.pop();
        mp[ant]++;
    }

    ant = 0;
    while(!s2.empty()){
        ant += s2.top(); s2.pop();
        mp[ant]++;
    }

    ant = 0;
    while(!s3.empty()){
        ant += s3.top(); s3.pop();
        mp[ant]++;
    }

    int max = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        if(it->second == 3){
            if(it->first > max) max = it->first;
        }
    }
    
    cout<<max<<endl;
    return 0;
}
