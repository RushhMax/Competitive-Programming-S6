#include <bits/stdc++.h>

using namespace std;


bool isPossible(vector<int> &stalls, int mid, int c){
    int cows = 1;
    int lastCow = stalls[0];
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i] - lastCow >= mid){
            cows++;
            lastCow = stalls[i];
        }
    }
    return cows >= c;
}

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,c; cin>>n>>c;
        vector<int> stalls(n);
        for(int i=0; i<n; i++) cin>>stalls[i];

        sort(stalls.begin(), stalls.end());

        int low = 0, high = stalls.back();
        while(low < high){
            int mid = (low + high + 1)/2.0;
            if(isPossible(stalls, mid, c))low = mid;
            else high = mid-1;
        }

        if(isPossible(stalls, high, c)) cout<<high<<endl;
        else cout<<low<<endl;
    }
}
