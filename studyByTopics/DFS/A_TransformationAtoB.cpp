#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b;cin>>a>>b;

    vector<ll> ans;
    function<bool(ll, ll)> solve = [&](ll a, ll b){
        if(a > b) return false;
        if(a == b) return true;
        if(solve(a*2,b)){
            ans.push_back(a*2);
            return true;
        }else if(solve(a*10+1,b)){
            ans.push_back(a*10+1);
            return true;
        }
        return false;
    };

    if(solve(a,b)){
        cout<<"YES\n";
        cout<<ans.size()+1<<endl;
        cout<<a<<" ";
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i]<<" ";
        }
    }else{
        cout<<"NO\n";
    }
    return 0;
}
