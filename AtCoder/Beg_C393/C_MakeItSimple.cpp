#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;cin>>n>>m;
    map<pair<int,int>, int> mapa;
    int cont = 0;
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        if(a == b) {
            cont++;
            continue;
        }else{
            if(a < b) {
                mapa[{a,b}]++;
                if(mapa[{a,b}] > 1) cont++;
            } 
            else {
                mapa[{b,a}]++;
                if(mapa[{b,a}] > 1) cont++;
            }
        }
    }
    cout<<cont<<endl;
    return 0;
}
