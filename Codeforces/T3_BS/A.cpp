#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<k; i++){
        ll x;cin>>x;
        if(x < a[0] || x > a[n-1]){
            cout<<"NO"<<endl;
            continue;
        }
        ll low = 0, high = n-1;
        bool flag = false;
        while(low <= high){
            ll mid = low + (high - low) / 2 ;
            if(a[mid] == x) {
                cout<<"YES\n";;
                flag = true;
                break;
            }else if( x < a[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        if(!flag) cout<<"NO\n";
    }
}
