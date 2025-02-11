#include <bits/stdc++.h>

using namespace std;

struct Fecha{
    int d;
    int m;
    int y;
    int c;
    Fecha(int _d, int _m, int _y, int _c):d(_d), m(_m), y(_y), c(_c) {}
};

set<int> treintayuno = {1,3,5,7,8,10,12};
set<int> treinta = {4, 6, 9, 11};

bool esBisiesto(int año) {
    return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
}
bool isConsecutive(Fecha& f1, Fecha& f2){
    if(f1.y != f2.y){
        if(f1.y+1 != f2.y) return false;
        if(f1.m == 12 && f2.m == 1 
                && f1.d == 31 && f2.d == 1){
                return true;
        }return false;
    }
    if(f1.m != f2.m){
        if(f1.m+1 != f2.m) return false;
        if(f1.m == 2){
            if(esBisiesto(f1.y)){
                return f1.d == 29 && f2.d == 1;
            }else{
                return f1.d == 28 && f2.d == 1;
            }
        }else if(treintayuno.find(f1.m) != treintayuno.end()){
            return f1.d == 31 && f2.d == 1;
        }
        return f1.d == 30 && f2.d == 1;
    }
    if(f1.d+1 == f2.d) return true;
    return false;
}
int main(){
    int n;
    while(cin>>n && n!=0){
        int ansDate = 0, ansCons = 0;
        Fecha f1 (0,0,0,0);
        for(int i=0; i<n; i++){
            int d,m,y,c;cin>>d>>m>>y>>c;
            Fecha f2(d,m,y,c);
            if(isConsecutive(f1,f2)){
                ansDate++;
                ansCons += f2.c - f1.c;
            }
            f1 = f2;
        }
        cout<<ansDate<<" "<<ansCons<<endl;
    }
}
