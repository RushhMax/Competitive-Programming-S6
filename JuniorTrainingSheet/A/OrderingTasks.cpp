#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void tasks(int a){
    visited[a] = 1;
    //cout<<a<<" ";
    for(int b: adj[a]){
        if(!visited[b]){
            tasks(b);
        }
    }
    cout<<a<<" ";
}


int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m == 0) break;
        adj.assign(n+1,vector<int>());
        for(int i=0; i<m; i++){
            int a,b;cin>>a>>b;
            adj[b].push_back(a);
        }

        visited.assign(n+1,0);
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                tasks(i);
            }
        }
        cout<<endl;

    }
    return 0;
}
