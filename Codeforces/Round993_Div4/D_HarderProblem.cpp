#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define __log__ { std::FILE* file = std::freopen("LOG.txt", "w", stdout); }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //__log__;
    int tc;cin>>tc;
    while(tc--){
        ll n;cin>>n;
        ll maxi = 1;
        map<ll,ll> cont;
        vector<ll> b(n);
        for(ll i=0;i<n; i++){
            ll a;cin>>a;
            cout<<" INsertando "<<a<<" "<<maxi<<endl;
            if(cont[a] < maxi){
                cout<<"Entra"<<endl;
                ll j = i;
                while(cont[a] < maxi){
                    cont[b[j-1]]--;
                    maxi = cont[b[j-1]];
                    b[j] = a;
                    cont[a]++;
                    j--;
                }
            }else{
                cout<<"No entra"<<endl;
                b[i] = a;
                cont[a]++;
                maxi = cont[a];
            }
        }

        for(int i=0; i<n; i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}
