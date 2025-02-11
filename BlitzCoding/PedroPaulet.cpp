#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string s;
        cin>>s;
    
        int max = -1;
        int ind = 0;
        for(int i=0; i<s.size(); i++){
            string c(1,s[i]);
            int aux = stoi(c);
            if(aux > max){
                ind = i;
                max = aux;
            }
        }

        cout<<ind<<endl;
        
    }
    return 0;
}
