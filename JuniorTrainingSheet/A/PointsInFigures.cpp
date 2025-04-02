#include <bits/stdc++.h>

using namespace std;

struct Rectangle{
    int nro;
    double rx, ry, lx, ly;
    Rectangle(int _nro, double _lx, double _ly, double _rx, double _ry){
        rx = _rx;
        ry = _ry;
        lx = _lx;
        ly = _ly;
        nro = _nro;
    }

    bool isInside(double x, double y){
        if(lx < x && x < rx && ry < y && y < ly) return true;
        return false;
    }
};

int main(){
    char a;
    vector<Rectangle> figures;
    int n = 1;
    while(cin>>a && a == 'r'){
        double rx, ry, lx, ly;
        cin>>rx>>ry>>lx>>ly;
        figures.push_back(Rectangle(n,rx,ry,lx,ly));
        n++;
    }
    double x,y;
    n = 1;
    while(cin>>x>>y ){
        if(x == 9999.9 && y == 9999.9) break;
        bool flag = false;
        for(int i=0; i<(int)figures.size(); i++){
            if(figures[i].isInside(x,y)){
                flag = true;
                cout<<"Point "<<n<<" is contained in figure "<<figures[i].nro<<"\n";
            }
        }
        if(!flag) cout<<"Point "<<n<<" is not contained in any figure\n";
        n++;
    }
}
