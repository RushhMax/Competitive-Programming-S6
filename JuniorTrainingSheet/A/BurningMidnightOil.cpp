#include <bits/stdc++.h>

using namespace std;

int suma(int v,int k){ // 4 2
    int s = v; // 4
    int k_c = 1;
    int r = v/pow(k,k_c); // 4 
    while(r){
        s += r; // 2
        k_c++; // 2
        r = v/pow(k,k_c);
    }
    return s;
}

int minValue(int n, int k){ // 7 2
    int l = 1;
    int u = n; 
    while(l < u){ // 1 2 3 4 5 6 7
        int m = (l+u)/2;
        int sum = suma(m,k); // 4 2
        
        if(sum == n) return m;
        else if(sum > n) u = m; // l
        else l = m+1; //r
    }
    return l;
}


int main(){
    int n, k;
    cin>>n>>k;
    
    cout<<minValue(n,k)<<endl;
}
