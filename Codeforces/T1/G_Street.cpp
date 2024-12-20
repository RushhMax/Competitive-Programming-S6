#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        int a,b; cin>>a>>b;
        if(a==b) {
            cout<<0<<endl;
            continue;
        }

        int min,may;
        if(a%2==0){
            min = a-3; 
            may = a+2;
        }else{
            min = a-2;
            may = a+3;
        }
        if(min <= b && b <= may)cout<<1<<endl;
        else {
            may = (a>b? a:b);
            min = (a<b? a:b);
            bool parA = min%2==0; 
            bool parB = may%2==0;
            if(parA && !parB){
                min--;
            }else if(!parA && parB){
                min++;
            }
            cout<<(may-min)/2<<endl;
        }
    }
    return 0;
}
