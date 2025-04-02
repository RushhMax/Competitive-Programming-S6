#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    int ans = -2;
    int ant = INT_MAX; 
    bool notSort = false;
    while(n--){
        int a,b;cin>>a>>b;
        if(a!=b){ ans = 1; }
        if(a > ant){ notSort = true;}
        ant = a;
    }

    if(ans == -2 && notSort) ans = -1;
    else if(ans == -2) ans = 0;

    if(ans == 1) cout<<"rated"<<endl;
    else if(ans == 0) cout<<"maybe"<<endl;
    else cout<<"unrated"<<endl;

    return 0;
}
