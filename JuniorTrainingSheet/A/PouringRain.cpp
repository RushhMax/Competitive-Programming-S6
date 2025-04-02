#include <bits/stdc++.h>

using namespace std;

double const pi_4 = 0.7853981634;

int main(){
    double d,h, v, e;
    cin>>d>>h>>v>>e;
    
    double area = pi_4*d*d;
    double hb = v/area;;
    //cout<<"hb "<<hb<<endl;
    // sd = hb * A 
    if(hb > e){
        cout<<"YES\n"<<h/(hb-e)<<endl;
    }else{
        cout<<"NO\n";
    }
}
