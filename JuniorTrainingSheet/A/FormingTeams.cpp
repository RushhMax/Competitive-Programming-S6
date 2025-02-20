#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visitados;

int ciclo(int j, int Naristas, int ant){
    visitados[j] = true;
    for(int k = 0; k<adj[j].size(); k++){
        if(ant == adj[j][k]) continue;
        if(visitados[adj[j][k]])  return Naristas+1;
        int tamCiclo = ciclo(adj[j][k], Naristas+1, j);
        if (tamCiclo > 0) return tamCiclo;
    }
    visitados[j] = false;
    return 0;
}

int main(){
    int n, m;cin>>n>>m;
    adj.resize(n+1);
    visitados.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(visitados[i]) continue;
        int nAristas = ciclo(i, 0, 0);
        if(nAristas % 2 != 0 && nAristas != 1){
            ans++;
        }
    }
    if((n-ans) % 2 != 0) {ans++;}
    cout<<ans<<endl;

    return 0;
}
