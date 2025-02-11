#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,x;
    cin>>n>>x;

    multiset<int> children;
    for(int i=0; i<n; i++){
        int p;cin>>p;
        children.insert(p);
    }

    int ans = 0;
    auto begin = children.begin();
    auto end = children.end();
    end--;

    while(begin != end){
        //cout<<*begin<<" "<<*end<<endl;
        if(*begin + *end <= x){
            ans++;
            begin++;
            if(begin == end) break;
            end--;
        }else{
            end--;
            ans++;
        }

        if(begin == end) ans++;
    }

    cout<<ans<<endl;


    return 0;
}
