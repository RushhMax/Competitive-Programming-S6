#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n, k;cin>>n>>k;

    priority_queue<ll, vector<ll>, greater<ll>> cookies;
    for(int i=0; i<n; i++){
        ll c; cin>>c;
        cookies.push(c);;
    }
    
    ll cont = 0;
    while(cookies.size() > 1){
        ll least = cookies.top();
        if(least >= k){
            break;
        }
        cookies.pop();
        ll second = cookies.top();
        cookies.pop();
        ll newCookie = least + 2*second;
        cookies.push(newCookie);
        cont++;
    }

    if(cookies.top() < k){
        cout<<-1<<endl;
        return 0;
    }
    cout<<cont<<endl;
    return 0;
}
