#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<vector<char>> tictactoe(3, vector<char>(3));
vector<vector<bool>> visitados(3, vector<bool>(3));

bool isTotalValid(int x, int y, char c){
    return x>=0 && x<3 && y>=0 && y < 3 && tictactoe[x][y] == c;
}

bool isWinner(int i, int j, char c){
    queue<pair<int, int>> q;
    q.push({i, j});

    bool isWinner = false;
    while(!q.empty()){
        pair<int,int> p = q.front();q.pop();
        int x = p.first, y = p.second;
        visitados[x][y] = true;
        
        for(int k=-1; k<=1; k++){
            for(int l=-1; l<=1; l++){
                if(k == 0 && l == 0) continue;
                if(isTotalValid(x+k, y+l, c)){
                    if(!visitados[x+k][y+l]) q.push({x+k, y+l});

                    if(isTotalValid((x+(2*k)), (y+(2*l)), c)){
                        isWinner = true;
                        if(!visitados[x+(2*k)][y+(2*l)]) q.push({x+(2*k), y+(2*l)});
                    }else if(isTotalValid(x-k, y-l, c)){
                        isWinner = true;
                        if(!visitados[x-k][y-l]) q.push({x-k, y-l});
                    }
                }
            }
        }
    }
    if(isWinner) return true;
    return false;
}

int main(){
    int tc;cin>>tc;
    while(tc--){

        int conX = 0, conO = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                visitados[i][j] = 0;
                cin>>tictactoe[i][j];
                if(tictactoe[i][j] == 'X') conX++;
                if(tictactoe[i][j] == 'O') conO++;
            }
        }

        bool winnerX = false, winnerO = false;
        for(int i=0; i<3; i++){
            for(int j=0; j<3;j++){
                if(visitados[i][j] || tictactoe[i][j] == '.') continue;
                if(tictactoe[i][j] == 'X'){
                    if(isWinner(i, j, 'X')){
                        winnerX = true;
                    }
                }else if(tictactoe[i][j] == 'O'){
                    if(isWinner(i, j, 'O')){
                        winnerO = true;
                    }
                }
            }
        }

        if(winnerX && winnerO) cout<<"no\n";
        else if(winnerX && conX == conO+1) cout<<"yes\n";
        else if(winnerO && conX == conO) cout<<"yes\n";
        else cout<<"no\n";
    }
}
