#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    stack<int> posters;
    int front1 = 0;
    int ans = 0;

    for(int i=0;i<n; i++){
        int a,b;cin>>a>>b;

        if(!posters.empty()) front1 = posters.top();
        else front1 = 0;

        while(b < front1){
            posters.pop();
            ans++;
            if(!posters.empty()) front1 = posters.top();
            else front1 = 0;
        }

        if(!posters.empty() && posters.top() == b) continue;
        else posters.push(b);    
    }
    while(!posters.empty()){
        ans++;
        posters.pop();
    }

    cout<<ans<<endl;
}
