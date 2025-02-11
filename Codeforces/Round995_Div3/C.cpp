#include <bits/stdc++.h>


using namespace std;

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n,m,k;
        cin>>n>>m>>k;

        map<int,int> questions;
        for(int i=0; i<n; i++){
            questions[i+1] ++;
        }

        vector<int> ai(m);
        for(int i=0; i<m; i++){
            cin>>ai[i];
        }

        for(int i=0; i<k; i++){
            int aux; cin>>aux;
            questions[aux]++;
        }

        for(int i=0; i<m; i++){
            if(questions[ai[i]] == 2 && n-k == 0){
                cout<<1;
            }else if(questions[ai[i]] == 1 && n-k <= 1){
                cout<<1;
            }else{
                cout<<0;
            }
        }

        cout<<endl;
    }
    

    return 0;
}
