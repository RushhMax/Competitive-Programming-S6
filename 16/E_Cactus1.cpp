#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 10000
#define MAXE 10000

int E, to[MAXE], nxt[MAXE], last[MAXN];

void add_edge(int u, int v){
    to[E] = v; nxt[E] = last[u]; last[u] = E++;
}

int n, cont, parent[MAXN], level[MAXN], sons[MAXN], back[MAXN];
bool done[MAXN], hasForwardEdge, cross;  

void dfs(int pos, int lvl){
    level[pos] = lvl;
    sons[pos] = 0;
    ++cont;
    
    for(int e = last[pos]; e != -1; e = nxt[e]){
        int x = to[e];
        
        if(done[x]) 
            cross = true;
        else if(parent[x] != -1){
            if(level[x] > level[pos]) 
                hasForwardEdge = true; 
            else 
                back[pos] = (back[pos] == -1 ? level[x] : -2);
        } else {
            parent[x] = pos;
            ++sons[pos];
            dfs(x, lvl + 1);
        }
    }
    
    done[pos] = true;
}

bool is_cactus(){
    if(cont < n || hasForwardEdge || cross)  
        return false;
    
    for(int i = 0; i < n; ++i)
        if(back[i] == -2) 
            return false;
    
    for(int i = 0; i < n; ++i)
        if(i != 0 && sons[i] > 1 && back[i] == -1)
            return false;
    
    for(int i = 0; i < n; ++i){
        if(sons[i] == 0){
            int e = level[i], pos = i;
            
            while(pos != 0){
                if(level[pos] == e){
                    if(back[pos] == -1) return false;
                    e = back[pos];
                } else if(back[pos] != -1) return false;
                
                pos = parent[pos];
            }
        }
    }
    
    return true;
}

int main(){
    int T, m;
    
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &n, &m);
        
        memset(last, -1, sizeof last);
        E = 0;
        
        for(int i = 0, u, v; i < m; ++i){
            scanf("%d %d", &u, &v);
            add_edge(u, v);
        }
        
        memset(back, -1, sizeof back);
        memset(parent, -1, sizeof parent);
        memset(done, false, sizeof done);
        hasForwardEdge = cross = false; 
        parent[0] = -2;
        cont = 0;
        
        dfs(0, 0);
        
        puts(is_cactus() ? "YES" : "NO");
    }
    
    return 0;
}

Rushell Vanessa Zavalaga Orozco
Estructura de Datos Avanzados - Grupo B (Profesor Wilber)
