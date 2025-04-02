#include <bits/stdc++.h>

using namespace std;

#define pdd pair<double, double>
#define x first
#define y second

int main(){
    pdd p1,p2, p3, p4;
    while(cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y){
        if(p1 == p3){
            swap(p1,p2);
        }else if(p1 == p4){
            swap(p3,p4);
            swap(p1,p2);
        }else if(p2 == p4){
            swap(p3,p4);
        }
        //p1+p3-p2;
        pdd ans;
        ans.x = p1.x+p4.x-p2.x;
        ans.y = p1.y+p4.y-p2.y;
        cout<<fixed<<setprecision(3)<<ans.x<<" "<<ans.y<<endl;
    }
}
