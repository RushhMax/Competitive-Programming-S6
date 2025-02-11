#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;

    set<int> s;
    for(int i=0; i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    for(auto x:s){
        if(s.find(x+1) == s.end()){
            cout<<x+1<<endl;
            break;
        }
    }

    return 0;
}
