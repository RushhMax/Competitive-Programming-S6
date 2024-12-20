#include <bits/stdc++.h>


using namespace std;

int main(){
    string n;
    cin>>n;

    if(n.size() < 2 ) {cout<<0<<endl; return 0;}
    cout<<n[n.size()-2]<<endl;
    return 0;
}
