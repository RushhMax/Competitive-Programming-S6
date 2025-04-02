#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,x; cin>>n>>x;

        multiset<int> s;
        bitset<100000> bits = x;
        bitset<100000> bits1 = 0;

        for(int i=0; i<n; i++){ 
            bitset<100000> bits2 = i;
            bits2 = bits2 | bits;
            if(bits2 == bits){ 
                s.insert(i);
                bits2 = i;
                bits1 = bits1 | bits2;
            }
        }

        if(bits1 != bits){
            while(s.size() >= n){
               if(!s.empty()) s.erase(--s.end()); 
            }
            s.insert(x);
        }
        
        n = n-s.size();
        for(int i=0; i<n; i++){
            s.insert(0);
        }

        for (auto i : s){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
