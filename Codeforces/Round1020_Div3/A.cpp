#include <bits/stdc++.h>
//#include <iostream>


using namespace std;

int main(){
    int tc; 
    cin>>tc;
    while (tc--){
        int n;cin>>n;
        string s;cin>>s;
        int base = 0;
        int diferencial = 0;
        for(int i=0 ; i< s.size(); i++){
            if(s[i] == '1') base++;
            if(s[i] == '1') diferencial--;
            else diferencial++;
        }

        cout<<(base*n)+diferencial<<endl;
    }
    
}