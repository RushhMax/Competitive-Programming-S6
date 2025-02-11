#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){ cin>>a[i];}

    for(int i=0; i<k; i++){
        int x;cin>>x;
        int low = 0, high = n-1, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(a[mid] == x){
                break;
            }
            if(a[mid] > x) high = mid-1;
            else low = mid+1;
        }

        bool flag = false;
        while(x > a[mid]){
            if(mid > n-1) {
                cout<<n+1<<endl;
                flag = true;
                break;
            }
            mid++;
        }
        if(!flag) cout<<mid+1<<endl;
    }

    return 0;
}
