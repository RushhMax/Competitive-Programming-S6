#include <iostream>

using namespace std;


void solve(){
    int n, k;
    cin>>n>>k;
    int RobinMoney = 0;
    int cont = 0;
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(a >= k) RobinMoney += a;
        if(a == 0) {
            if(RobinMoney > 0) {
                cont++;
                RobinMoney--;
            }
        }
    }

    cout<<cont<<endl;
}

int main(){
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        solve();
    }
}
