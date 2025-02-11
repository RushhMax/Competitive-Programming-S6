#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,c;
    while(cin>>n>>m>>c){
        if(n == 0 && m == 0 && c == 0){
            break;
        }
        n = n - 7;
        m = m - 7;
        if(n%2 == 0 || m%2 == 0){
            cout<<(n*m)/2<<endl;
        }else{
            if(c){
                cout<<((n*m)/2)+1<<endl;
            }else{
                cout<<((n*m)/2)<<endl;
            }
        }
    }
    return 0;
}
