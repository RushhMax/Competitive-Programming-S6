#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, h,x;
    cin>>n>>h>>x;
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        if(a+h >= x){
            //ans = i+1;
            if(i+1 < ans){
                ans = i+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
