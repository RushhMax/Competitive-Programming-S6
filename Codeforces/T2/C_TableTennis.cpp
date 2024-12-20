#include <bits/stdc++.h>
#define __log__ { std::FILE* file = std::freopen("LOG.txt", "w", stdout); }

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //__log__;
    int n; long long k;cin>>n>>k;
    int Kcount = 0;
    int winner;

    queue<int> q;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        q.push(x);
    }

    winner = q.front(); q.pop();
    while(Kcount < k &&  Kcount < q.size()){
        int vs = q.front(); q.pop();
        if(vs>winner){
            q.push(winner);
            winner = vs;
            Kcount = 1;
        }else{
            q.push(vs);
            Kcount++;
        }
    }

    cout<<winner;
}
