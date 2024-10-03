#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

#define vp vector<pair<int, int>>
#define vi vector<int>
#define ll long long

void solve(){
    int n;
    cin>>n;

    map<ll,ll> pointsDOWN, pointsUP;

    ll contT = 0;
    for(int i=0; i<n;i++){
        int x, y;
        cin>>x>>y;
        if(y==0){ 
            if(pointsUP.find(x) != pointsUP.end()) contT += n-2;
            pointsDOWN[x]++;
        }else{
            if(pointsDOWN.find(x) != pointsDOWN.end()) contT += n-2;
            pointsUP[x]++;
        }
    } 

    for(auto it = pointsDOWN.begin(); it != pointsDOWN.end(); it++){
        if(pointsDOWN.find(it->first + 2) != pointsDOWN.end()){
            if(pointsUP.find(it->first + 1) != pointsUP.end()){
                contT++;
            }
        }
    }

    for(auto it = pointsUP.begin(); it != pointsUP.end(); it++){
        if(pointsUP.find(it->first + 2) != pointsUP.end()){
            if(pointsDOWN.find(it->first + 1) != pointsDOWN.end()){
                contT++;
            }
        }
    }

    cout<<contT<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    for(int i=1; i<=t; i++){
        solve();
    }
}
