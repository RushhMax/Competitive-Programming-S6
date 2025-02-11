#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n && n!=0){
        if(sqrt(n) == (int)sqrt(n)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;

}
