#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int print = (n%2==0? n+2 : n+1);
        cout<<print<<endl;
    }
}
