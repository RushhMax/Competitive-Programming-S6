#include <bits/stdc++.h>

using namespace std;

struct Rectangle{
    //double rx, ry, lx, ly;
    pair<double, double> ld, ru, lu, rd;
    Rectangle(double _lx, double _ly, double _rx, double _ry){
        ld = make_pair(_lx, _ly);
        ru = make_pair(_rx, _ry);
        lu = make_pair(_lx, _ry);
        rd = make_pair(_rx, _ly);
    }
};

bool isOverlapped(Rectangle &r1, Rectangle &r2, pair<double, double> &ld, pair<double, double> &ru){
    ld.first = max(r1.ld.first, r2.ld.first);
    ld.second = max(r1.ld.second, r2.ld.second);
    ru.first = min(r1.ru.first, r2.ru.first);
    ru.second = min(r1.ru.second, r2.ru.second);
    if(ld.first < ru.first && ld.second < ru.second) return true;
    return false;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int lx, ly, rx, ry;
        pair<double, double> ld, ru;
        cin>>lx>>ly>>rx>>ry;
        Rectangle r1(lx, ly, rx, ry);
        cin>>lx>>ly>>rx>>ry;
        Rectangle r2(lx, ly, rx, ry);
        if(isOverlapped(r1, r2, ld, ru)){
            cout<<ld.first<<" "<<ld.second<<" "<<ru.first<<" "<<ru.second<<"\n";
        }else cout<<"No Overlap\n";
        if(tc) cout<<"\n";
    }
}
