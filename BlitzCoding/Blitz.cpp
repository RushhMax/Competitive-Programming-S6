#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;

    while(tc--){
        int x;cin>>x;
        if( 0 <= x  && x <= 1199 ){
            cout<<"Plomo"<<endl;
        }else if( 1200 <= x && x <= 1499 ){
            cout<<"Verde"<<endl;
        }else if( 1500 <= x && x <= 1899 ){
            cout<<"Azul"<<endl;
        }else if( 1900 <= x  && x <= 2199 ){
            cout<<"Amarillo"<<endl;
        }else if( 2200 <= x ){
            cout<<"Rojo"<<endl;
        }
    }

}
