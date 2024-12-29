#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        int moda = 1;
        map<int, int> modas; 
        vector<int> b(n,0);
        for(int i=0;i<n; i++){
            int a;cin>>a;
            cout<<a<<" "<<modas[a]<<" "<<moda<<endl;
            if(modas[a] < moda){
                cout<<"entra1"<<endl;
                int j = i;
                while(moda - modas[a] > 0){
                    if(j < 0) break;
                    
                    b[j] = a;
                    modas[a]++;

                    if(b[j] != 0){
                        modas[b[j]]--;
                        moda =  max(modas[a], modas[b[j]]);
                    }else{
                        moda =  max(moda,modas[a]);
                    }
                    j--;
                }
            }else{
                cout<<"entra2"<<endl;
                b[i] = a;
                modas[a]++;
                moda = modas[a];
                cout<<"moda "<<moda<<endl;
            }
        }

        for(int i=0; i<n; i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}
