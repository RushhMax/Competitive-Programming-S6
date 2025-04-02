#include <bits/stdc++.h>


using namespace std;

int main(){
    int v,e;
    int tc = 1;
    while(cin>>v>>e){
        if(v == e && v == 0) break;

        vector<int> time(v+1);
        int allTImes = 0;
        for(int i=1; i<=v;i++){
            cin>>time[i];
            allTImes += time[i];
        }

        vector<vector<int>> adj(v+1);
        vector<vector<int>> dependencias(v+1);

        for(int i=0; i<e; i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            dependencias[b].push_back(a);
        }

        int querys;cin>>querys;
        cout<<"Case #"<<tc++<<":"<<endl;
        while(querys--){
            int query;cin>>query;
            // todos los que no dependan de el
            int Max = allTImes - time[query];
            queue <int> q;
            vector<bool> used(v+1, false);
            q.push(query);
            used[query] = true;

            while(!q.empty()){
                int p = q.front();q.pop();

                for(int j=0; j<dependencias[p].size(); j++){
                    if(used[dependencias[p][j]]) continue;
                    q.push(dependencias[p][j]);
                    used[dependencias[p][j]] = true;
                    Max -= time[dependencias[p][j]];
                }
            }

            // el minimo para hacerlo 
            int Min = 0;
            used.assign(v+1, false);
            q.push(query);
            used[query] = true;

            while(!q.empty()){
                int p = q.front();
                q.pop();

                for(int j=0; j<adj[p].size(); j++){
                    if(used[adj[p][j]]) continue;
                    q.push(adj[p][j]);
                    used[adj[p][j]] = true;
                    Min += time[adj[p][j]];
                }
            }


            cout<<(Max>Min? Max-Min : Min-Max )<<endl;
        }
        cout<<endl;
    }
}
