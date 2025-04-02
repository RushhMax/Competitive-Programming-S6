#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

unordered_map<int, unordered_map<int, int>> mapa;


int main(){
    int x0, y0, x1, y1; cin>>x0>>y0>>x1>>y1;
    int n;cin>>n;
    for(int i=0; i<n; i++){
        int ri, ai, bi; cin>>ri>>ai>>bi;
        for(int j=ai; j<=bi; j++){
            mapa[ri][j] = 1;
        }
    }

    queue<pair<pii,int>> q;
    q.push({{x0, y0},0});
    mapa[x0][y0] = -1;

    while(!q.empty()){
        pii p = q.front().first;
        int depth = q.front().second;
        q.pop();

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i == 0 && j == 0) continue;
                pii newP = {p.first+i, p.second+j};
                if(newP.first == x1 && newP.second == y1) {cout<<depth+1<<endl; return 0;}
                if(mapa[newP.first][newP.second] == 1){
                    q.push({{newP.first, newP.second},depth+1});
                    mapa[newP.first][newP.second] = -1;
                }
            }
        }
    }

    cout<<-1<<endl;
}
