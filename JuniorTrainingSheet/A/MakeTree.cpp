#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> leaders;
vector<int> visitados;

bool SisLeader(int f, int s){
    if(f == s) return true;
    visitados[f] = true;
    for(int i=0; i<leaders[f].size(); i++){
        if(visitados[leaders[f][i]]) continue;
        if(SisLeader(leaders[f][i], s)) return true;
    }
    visitados[f] = false;
    return false;
}

int twoLeaders(int f, int s){
    // -1 first
    // 0 any
    // 1 second
    if(SisLeader(f,s)) return 1;
    return 0;
}

int main(){
    int n,k; cin>>n>>k;
    leaders.resize(n+1);
    visitados.resize(n+1);
    queue<int> q;
    for(int i = 1; i <= k; i++){
        int nW; cin>>nW;
        for(int j=0; j<nW; j++){
            int w;cin>>w;
            leaders[w].push_back(i);
            if(leaders[w].size() > 1){
                q.push(w);
            }
        }
    }

    //cout<<"q "<<q.size()<<endl;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        int subordinado = 0, ind = 0;
        vector<int> v = leaders[cur];

        for(int i=0; i<v.size(); i++){
            int cont = 0;
            for(int j=0; j<v.size(); j++){
                if(i == j) continue;
                int result = twoLeaders(v[i], v[j]);
                    
                if(result == 1){ // si s es lider
                    cont++;
                }
            }
            if(cont > subordinado){
                subordinado = cont;
                ind = i;
            }
        }
        swap(leaders[cur][0], leaders[cur][ind]);
    }

    vector<int> leaders0;

    for(int i = 1; i <= n; i++){
        int size = leaders[i].size();
        if(size == 0){
            leaders0.push_back(i);
        }
    }

    int realLeader = 0;
    for(int i = 1; i<=n; i++){
        if(leaders[i].size() == 0) continue;
        for(int j=0; j<leaders0.size(); j++){
            if(leaders0[j] == leaders[i][0]){
                realLeader = leaders0[j];
                break;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(i == realLeader) cout<<0<<endl;
        else if(leaders[i].size() > 0) cout<<leaders[i][0]<<endl;
        else cout<<realLeader<<endl;
        //cout<<leaders[i][0]<<endl;
    }
}
