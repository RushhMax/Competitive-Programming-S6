#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        set<char> dulces;
        for(int i=0; i<n; i++){
            char c;
            cin>>c;
            dulces.insert(c);
        }

        cout<< (n/2 < dulces.size()?  n/2 : dulces.size())<<endl;
        
    }
}
