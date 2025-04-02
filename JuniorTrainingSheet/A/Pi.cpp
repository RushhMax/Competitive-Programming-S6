#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a%b == 0) return b;
    return gcd(b,a%b);
}


int main ( ){
    int n;
    while(cin>>n){
        if(n == 0) break;
        
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        } 

        int coPrime = 0;
        int total = n*(n-1)/2;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(gcd(v[i], v[j]) == 1){
                    coPrime++;
                }
            }
        }

        double ans = 1;
        if(coPrime == 0){
            cout<<"No estimate for this data set.\n";
        }else{
            cout<<fixed<<setprecision(6);
            cout<<sqrt((6.0*total)/coPrime)<<endl;
        }
    }   
}
