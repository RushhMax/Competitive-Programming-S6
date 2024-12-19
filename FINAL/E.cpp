#include <bits/stdc++.h>


#define mpiii map<pair<int,int>,int>
using namespace std;


int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> adj(n+1);

    for(int i=0; i<n-1; i++){
        int u,v; 
        cin>>u>>v;
        adj[u].push_back(v);
    }

    mpiii vis;
    int min = INT_MAX;
    function<int(int)> dfs = [&](int u){
        if(u == 1 && adj[u].size() == 1){
            min = 1;
        }
        if(adj[u].size() == 0){
            return 1;
        }
        int ans = 0;
        for(int v: adj[u]){
            if(!vis[{u,v}]){
                vis[{u,v}] = 1;
                int dfs_ans = dfs(v);
                //cout<<"Desde "<<u<<" hacia v "<<v<<" : "<<dfs_ans<<endl;
                if(u!=1) ans += dfs_ans;
                else if(dfs_ans+1 < min){
                    //cout<<"Actualizando minimo a "<<dfs_ans+1<<endl;
                    min = dfs_ans+1;
                }
            }
        } 
        //cout<<"Suma en "<<u<<": "<<ans<<endl;
        return ans+1;
    };


    dfs(1);
    cout<<min<<endl;
}
