#include <bits/stdc++.h>

#define ll long long


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    ll ant, move = 0;
    for(int i=0; i<n;i++){
        int x;cin>>x;
        if(i==0){
            ant = x;
        }else if(x < ant){
            move += (ant-x);
            ant = ant;
        }else{
            ant = x;
        }
    }

    cout<<move;

    return 0;
}
