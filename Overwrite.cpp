
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

        int last = -1;
        int flag = 0;
        for(int i = 0; i <= n - b.size(); i++){
            if(flag > 0){
                a[i] = b[0];
                if(b[0]<a[i])
                    flag = b.size();
                flag--;
            }
            if(b[0] < a[i]){ 
                flag = b.size()-1;
                if(i == n-b.size()){ 
                    if(b[0] == a[i]){
                        last = 1;
                    }else{ last = 0; }
                }
                a[i] = b[0];
            }else if(b[0] == a[i]){
                
            }
        }
        if(last != -1){
            int flag = -1;
            if(last == 0) flag = 0;
            for(int i = n-b.size(); i < n; i++){
                if(flag != -1){
                    if(flag == 0){
                        a[i] = b[i-n+b.size()];
                    }
                }else{
                    if(a[i] > b[i-n+b.size()]){
                        flag = 0;
                        a[i] = b[i-n+b.size()];
                    }else if(a[i] < b[i-n+b.size()]){
                        flag = 1;
                    }
                }
            }
        }

        for(int i = 0; i<n; i++){
            cout<<a[i]<<" ";
        }cout<<endl;
	}
}
