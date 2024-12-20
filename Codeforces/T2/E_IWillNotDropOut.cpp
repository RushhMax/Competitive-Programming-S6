#include <bits/stdc++.h>

#define pii pair<int,int>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,k;
    cin>>n>>k;

    multiset<pair<ll,ll>> set;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        set.insert({a,b});
    }
    
    ll suma = 0;
    while(k>0){
        if(set.size() < 1) break;
        if(set.size() == 1){
            if(k>1) suma+=set.begin()->first;
            else suma+=set.begin()->second;
            break;
        }
        auto fi = --set.end();
        auto se = --(--set.end());
        int a = (k>1? fi->first : se->second);
        int b = fi->second;
        cout<<"f"<<fi->first<<" "<<fi->second<<endl;
        cout<<"a"<<a<<" b"<<b<<endl;
        cout<<"n"<<se->first<<" "<<se->second<<endl;
        if(k>1) b += se->second;

        cout<<"a"<<a<<" b"<<b<<" "<<k<<endl;

        if(a>b){
            if(k>1) set.erase(fi);
            else set.erase(se);
            suma += a;
        }else{
            if(k>1) {
                set.erase(se);
                set.erase(fi);
            }else{
                set.erase(fi);
            }
            suma += b;
        }
        k -= 2;
        cout<<"SUMA "<<suma<<endl;
    }

    cout<<suma<<endl;

}
