#include <bits/stdc++.h>

using namespace std;

char mapa[100][100];
char visitados[100][100];
int n;

void family(int i, int j, bool isShip, bool &isAlive){
    if(i >= 0 && j >= 0 && i < n && j < n && !visitados[i][j]){ 
        bool isActShip = false;
        if(mapa[i][j] == 'x' || mapa[i][j] == '@') {
            isActShip = true;
            if(mapa[i][j] == 'x') isAlive = true;
        }
        
        visitados[i][j] = 1;
        
        if(isActShip){
            family(i-1, j, isActShip, isAlive); 
            family(i, j-1, isActShip, isAlive);
            family(i+1, j, isActShip, isAlive);
            family(i, j+1, isActShip, isAlive);
        }
    }
}

int main(){
    int tc;cin>>tc;
    for(int t=1; t<=tc; t++){
        cin>>n;
        cin.ignore();

        memset(mapa, 0, sizeof(mapa));
        memset(visitados, 0, sizeof(visitados));

        for(int i=0; i<n; i++){
            cin>>mapa[i];
        }

        int cont = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((mapa[i][j] == 'x' || mapa[i][j] == '@') && !visitados[i][j]){
                    bool isAlive = false;
                    if(mapa[i][j] == 'x') isAlive = true;
                    family(i,j,  true, isAlive);
                    if(isAlive) cont++;
                }
            }
        }
        cout<<"Case "<<t<<": "<<cont<<endl;

    }
    return 0;
}
