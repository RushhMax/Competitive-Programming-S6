#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin>>n>>m>>k;
    
    multiset<int> appli;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        appli.insert(x);
    }

    multiset<int> apart;
    for(int i=0; i<m; i++){
        int x;cin>>x;
        apart.insert(x);
    }

    int ans = 0;
    auto it = appli.begin();
    auto it2 = apart.begin();

    while(it != appli.end() && it2 != apart.end()){
        //cout<<*it<<" "<<*it2<<endl;
        if(*it-k<= *it2 && *it2<=*it+k){
            ans++;
            it++; it2++;
        }else if(*it > *it2){
            it2++;
        }else{
            it++;
        }
    }

    cout<<ans<<endl;



    return 0;
}
