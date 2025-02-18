#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    bool bS1 = (s1 == "fine"? 1: 0); 
    bool bS2 = (s2 == "fine"? 1: 0);
    if(bS1 == bS2){
        if(!bS1)cout<<1<<endl;
        else cout<<4<<endl;
    }else if(!bS1){
        cout<<2<<endl;
    }else  cout<<3<<endl;
    return 0;
}
