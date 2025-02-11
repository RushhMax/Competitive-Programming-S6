#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    multiset<int> tickets;
    for(int i=0; i<n; i++){
        int h;cin>>h;
        tickets.insert(h);
    }

    for(int i=0; i<m; i++){
        int t;cin>>t;
        auto itlow = tickets.lower_bound(t);
        if(*itlow == t){
            cout<<*itlow<<endl;
            tickets.erase(itlow);
            continue;
        }
        if(itlow != tickets.begin()){
            itlow--;
            cout<<*itlow<<endl;
            tickets.erase(itlow);
        }else{
            cout<<-1<<endl;
        }
    }


    
    return 0;

}
