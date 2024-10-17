#include <bits/stdc++.h>

#define FOR_LOOP(val,i, len) for (int i = val; i < len; ++i)
#define REVERSE_FOR_LOPP(i, start, end) for(int i = (end) - 1; i >= start; i--)


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases; cin >> cases;
    while(cases --){
        int n, k; cin >> n >> k;
        vector<long long> arr(n); 
        vector<long long> arr2(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            cin >> arr2[i];
        }

        long long current = arr[0]; 
        long long maximo = arr2[0]; 
        long long ans = arr[0] + arr2[0]*(k-1); 
        long long compare = 0;
        int top = min(n,k);
        for(int i = 1; i < top; i++){
            maximo = max(maximo, arr2[i]); 
            current += arr[i];
            compare = current + maximo*(k - i - 1); 
            if(compare > ans){
                ans = compare;
            }
        }

        cout << ans << "\n";

    }
}
