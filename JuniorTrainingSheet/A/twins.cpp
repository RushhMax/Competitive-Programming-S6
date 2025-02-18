#include <bits/stdc++.h>

using namespace std;

// TWINS
// https://codeforces.com/problemset/problem/160/A

int suma(vector<int>& coins, int i, int j){
    int suma = 0;
    for(int k=i; k<j; k++){
        suma += coins[k];
    }
    return suma;
}

int main(){
    int n;
    cin>>n;
    std::vector<int> coins(n);

    for(int i=0; i<n; i++){
        cin>>coins[i]; 
    }

    sort(coins.begin(), coins.end(),greater<int>());

    for(int i=0; i<n; i++){
        if(suma(coins, 0, i) > suma(coins, i, n)){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
}
