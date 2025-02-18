#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc;cin>>tc;
	while(tc--){
	    int n, m;cin>>n>>m; int menorB = 0;
	    vector<int> a(n),b(m);
	    for(int i = 0; i < n; i++){cin>>a[i];}  
	    for(int j = 0; j < m; j++){cin>>b[j]; if(b[j] < b[menorB]) menorB = j;}
	    
        rotate(b.begin(), b.begin() + menorB, b.end());

        for(int i = 0; i <= n - b.size(); i++){
            bool overwrite = false;
            for(int j = i; j < i+m; j++){ // 0 0
                if(b[j-i] < a[j]){
                    overwrite  = true;
                    break;
                }else if(a[j] < b[j-i]){
                    overwrite = false;
                    break;
                }
            }
            if(overwrite){
                copy(b.begin(), b.end(), a.begin() + i);
            }
        }
        for(int i = 0; i<n; i++){
            cout<<a[i]<<" ";
        }cout<<endl;
	}
}
