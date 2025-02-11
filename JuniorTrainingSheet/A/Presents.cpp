#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;

    map<int,int> friends;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        friends[x] = i; // 2 1      3 2     4 3     1 4
    }

    for(int i=1; i<=friends.size(); i++){
        cout<<friends[i]<<" ";
    }
    cout<<endl;

    return 0;
}
