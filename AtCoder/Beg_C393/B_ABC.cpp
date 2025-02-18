#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;cin>>s;
    int n = s.size();
    int cont = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j+j-i<=n; j++){
            //cout<<i<<" "<<j<<" "<<j+(j-i)<<endl;
            if(s[i] == 'A' && s[j] == 'B' && s[j+(j-i)] == 'C'){
                cont++;
            }
        }
    }
    cout<<cont<<endl;
}
