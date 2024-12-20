#include <bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    cin>>tc;
    while(tc--){

        int a,b,n;
        cin>>a>>b>>n;

        int x,y;

        x = a*n;
        y = b*n;
        if(y>=100){
            x += y/100;
            y = y%100;
        }

        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
