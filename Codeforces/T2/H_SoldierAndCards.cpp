#include <bits/stdc++.h>

#define f(i,n) for(int i=0; i<n; i++)

using namespace std;

void solve(){
    queue<int> ori1, ori2, p1, p2;
    int n;cin>>n;
    int k1, k2;

    cin>>k1;
    f(i,k1){
        int x; cin>>x;
        p1.push(x);
    }

    cin>>k2;
    f(i,k2){
        int x;cin>>x;
        p2.push(x);
    }

    ori1 = p1;
    ori2 = p2;
    int fights = 0;
    do{
        int x = p1.front(); p1.pop();
        int y = p2.front(); p2.pop();
        if(x>y){
            p1.push(y);
            p1.push(x);
        }else{
            p2.push(x);
            p2.push(y);
        }
        fights++;
        if(ori1 == p1 && ori2 == p2 || fights > n*n*n) break;
    }while(!p1.empty() && !p2.empty());
    
    if(!p1.empty() && !p2.empty()){
        cout<<-1<<endl;
    }else{
        cout<<fights<<" "<<(p1.empty() ? 2 : 1 )<<endl; 
    }
    
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    solve();

    return 0;
}
