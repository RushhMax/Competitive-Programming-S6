#include <bits/stdc++.h>

using namespace std;


int palindromo( string s, int init, int fin, int longi,vector<vector<int>>& memo){
    if(init > fin) return longi;
    if(init == fin) return longi+1;
    if(s[init] == s[fin] && (fin-init)%2 == 0){
        return memo[init][fin] = palindromo(s,init+1, fin-1, longi+2, memo);
    }else{
        longi = 0;
        if(memo[init][fin] != -1) return memo[init][fin];
        int first = palindromo(s,init+1, fin, longi,memo);
        int second = palindromo(s,init, fin-1, longi, memo);

        if(first > second) {
            return memo[init][fin] = first;
        }else{
            return memo[init][fin] = second;
        } 
    }
    return 0;
}


int main(){

    int tc;
    cin>>tc;
    while(tc--){
        string s;
        cin>>s;
   
        vector<vector<int>> memo (1001,vector<int>(1001,-1));
        cout<<palindromo(s,0,s.size()-1, 0, memo)<<endl;
    }
}
