#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n;
    cin>>n;

    set<long> s;
    for(int i=1; i<=n; i++){
        s.insert(i);
    }

    for(int i=0; i<n-1; i++){
        int x;
        cin>>x;
        s.erase(x);
    }

    cout<<*s.begin()<<endl;

    return 0;
}
