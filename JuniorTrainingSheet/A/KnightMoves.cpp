#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define x first
#define y second

vector<pii> knightmoves = {
    {-1,2}, {-2,1}, {-2,-1}, {-1,-2},
    {1, 2}, {2, 1}, {2, -1}, {1, -2}};

bool isValid(int x, int y){
    return x>=1 && x<9 && y>=1 && y<9;
}

int main(){
    string a,b;
    while(cin>>a>>b){
        pii inicial = {a[0]-'a'+1,a[1]-'0'}, final={b[0]-'a'+1, b[1]-'0'};
       
        vector<vector<bool>> used(9, vector<bool>(9, false));

        queue<pair<pii, int>> q;
        q.push({inicial,0});
        used[inicial.x][inicial.y] = 1;
        
        while(!q.empty()){
            pii p = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if(p == final){
                cout<<"To get from "<<a<<" to "<<b<<" takes "<<depth<<" knight moves."<<endl;
                break;
            }
            for(pii & move : knightmoves){
                pii newP = {move.x+p.x, move.y+p.y};
                if(isValid(newP.x, newP.y) && !used[newP.x][newP.y]){
                    q.push({newP, depth+1});
                    used[newP.x][newP.y] = 1;
                }
            }
        }
    }
}
