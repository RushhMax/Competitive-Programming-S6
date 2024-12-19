#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;cin>>tc;
    while(tc--){
        string a;cin>>a;
        for(int i=a.size()-1;i>=0;i--){
            char c = a[i];
            if(c == 'p') cout<<"q";
            else if(c == 'q')cout<<"p";
            else{cout<<c;}
        }
        cout<<endl;
    }
    return 0;
}
