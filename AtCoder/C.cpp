#include <bits/stdc++.h>

using namespace std;

map<int,int> vis;
vector<vector<pair<int,int>>> adj;

int maxi(int index){
    if(index == 0) return 0;
    if(adj[index].size() == 0){
        return 0;
    }

    cout<<"my index is: "<<index<<endl;
    vis[index] = 1;
    int best = 0;
    for(int i=0; adj[index].size();i++){
        cout<<"adj index: "<<adj[index][i].first<<endl;
        if(vis[adj[index][i].first] == 1){
            continue;
        }
        int res = maxi(adj[index][i].first) + adj[index][i].second;
        if(res > best){
            best = res;
        }
    }
    vis[index] = 0;
    return best;
}

int main(){
    int n, m;
    cin>>n>>m;

    adj = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>> ());

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<"agregando";
        adj[a].push_back({b,c});
    }

    cout<<"termino de agregar"<<endl;

    int ans = 0;
    for(int i=0; i<adj.size(); i++){
        int maxTemp = maxi(i+1);
        if(maxTemp > ans){
            ans = maxTemp;
        }
    }
    cout<<ans<<endl;

    return 0;
}
