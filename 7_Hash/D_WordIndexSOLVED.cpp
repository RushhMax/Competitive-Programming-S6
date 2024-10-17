#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> memoria;
int ind = 1;

void combinaciones(string comb, char ult, int longMax){
    if(!comb.empty() && memoria.find(comb) == memoria.end()){
        //cout<<"I: "<<comb<<" / "<<ind<<" // ";
        memoria[comb] = ind;
        ind++;
    }

    if(comb.size() == longMax) return;

    for(char c = ult + 1; c<='z'; c++ ){
        combinaciones(comb + c, c , longMax);
    }
}

int main(){
    ind = 1;
    for(int longi = 1; longi <= 5; longi++){
        for(char c = 'a'; c<='z'; c++){
            combinaciones(string(1,c), c, longi);
        }
    }

    string s;
    while(cin>>s){
        if(memoria.find(s) == memoria.end()) cout<<0<<endl;
        else cout<<memoria[s]<<endl;
    }
    
}
