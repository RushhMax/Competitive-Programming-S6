#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    map<int,int> cont;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        cont[x]++;
    }

    int min = 0;
    for(auto it = cont.begin(); it!= cont.end(); it++){
        if(it->second > it->first){
            min += (it->second - it->first);
        }else if(it->second < it->first){
            min += it->second; 
        }
    }

    cout<<min<<endl;
}
