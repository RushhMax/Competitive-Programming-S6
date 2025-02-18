#include <bits/stdc++.h>

using namespace std;

int m,n;
vector<char> name = {'I', 'E', 'H', 'O', 'V', 'A', '#'};

bool isSafe(int x, int y){
    return (x>=0 && x<m && y>=0 && y<n);
}

int main(){
    int tc;cin>>tc;
    while(tc--){
        cin>>m>>n;
        int fx, fy;
        vector<vector<char>> grid(m, vector<char>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>grid[i][j];
                if(grid[i][j] == '@'){
                    fx = i;
                    fy = j;
                }
            }
        }
        int ind = 0;
        while(ind < 7){
            if(isSafe(fx-1,fy) && grid[fx-1][fy] == name[ind] ){
                cout<<"forth";
                if(ind != 6) cout<<" ";
                fx--;
                ind++;
            }else if(isSafe(fx, fy-1) && grid[fx][fy-1] == name[ind]){
                cout<<"left";
                if(ind != 6) cout<<" ";
                fy--;
                ind++;
            }else if(isSafe(fx, fy+1) && grid[fx][fy+1] == name[ind]){
                cout<<"right";
                if(ind != 6) cout<<" ";
                fy++;
                ind++;
            }
        }
        cout<<endl;
    }
}
