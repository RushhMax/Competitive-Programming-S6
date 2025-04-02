#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> chimps(n);
    for(int i=0; i<n; i++) cin>>chimps[i];
    cin>>n;

    for(int i=0; i<n; i++){
        int q;cin>>q;
        auto low = lower_bound(all(chimps), q);
        auto up = upper_bound(all(chimps), q);
        if(low == chimps.end()) cout<<chimps.back()<<" ";
        else if(low == chimps.begin()) cout<<"X ";
        else cout<<*(--low)<<" ";
        if(up != chimps.end()) cout<<*up<<"\n";
        else cout<<"X\n";
    }
    return 0;
}
