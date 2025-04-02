#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1); // 0 1 2 3 

    for(int i=0; i<m; i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int,int>> eliminar;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 1){
            eliminar.push_back({i,adj[i][0]});
        }   
    }

    int cont = 0;
    while(eliminar.size() > 0){
        for(auto [v,u] : eliminar){
            adj[v].clear();
            adj[u].erase(
                    remove(adj[u].begin(), adj[u].end(), v),
                    adj[u].end()
            );
        }
        cont++;
        eliminar.clear();
        for(int i=0; i<adj.size(); i++){
            if(adj[i].size() == 1){
                eliminar.push_back({i,adj[i][0]});
            }   
        }
    }

    cout<<cont<<endl;


}
