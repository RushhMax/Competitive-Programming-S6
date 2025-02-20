#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    int p;cin>>p;
    set<int> levels;
    for(int i=0; i<p; i++){
        int x;cin>>x;
        levels.insert(x);
    }
    cin>>p;
    for(int i=0; i<p; i++){
        int x;cin>>x;
        levels.insert(x);
    }
    if(levels.size() == n) cout<<"I become the guy."<<endl;
    else cout<<"Oh, my keyboard!"<<endl;
    return 0;
}
