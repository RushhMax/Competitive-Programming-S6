#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        
        n = n%7;

        if(n == 1){
            cout<<"LUNES"<<endl;
        }else if(n == 2){
            cout<<"MARTES"<<endl;
        }else if(n == 3){
            cout<<"MIERCOLES"<<endl;
        }else if(n == 4){
            cout<<"JUEVES"<<endl;
        }else if(n == 5){
            cout<<"VIERNES"<<endl;
        }else if(n == 6){
            cout<<"SABADO"<<endl;
        }else if(n == 0){
            cout<<"DOMINGO"<<endl;
        }


    }
}
