#include <bits/stdc++.h>

#define vi vector<int>

#define f(i,n) for(int i=0;i<n;i++)

using namespace std;



int main(){
    int n;cin>>n;
    if(2<=n && n<=3){
        cout<<"NO SOLUTION";
        return 0;
    }
    vi v;
    int first = 1;
    int last = n;

    int mid = n%2==0? n/2 : n/2+1;
    bool flag = true;
    v.push_back(mid);

    f(i,n-1){ // 0 1 2 
        if(flag){ v.push_back(last); last--; flag = false;}
        else{ v.push_back(first); first++; flag = true;}
    }

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }

    // 1 2 3 4
    // 2 4 1 3

    // 1 2 3 4 5
    // 3 1 5 2 4


    // 1 2 3 4 5 // 5 / 2 = 2 
    // 3 5 1 4 2
    
    // 1 2 3 4 5 6 7
    // 4 2 6 1 5 3 7
    
    // 1 2 3 4 5 6 // 3
    // 4 2 6 1 5 3
    // 3 6 1 5 2 4
    
    // 1 2 3 4 5 6 7 8
    // 5 2 7 4 1 6 3 8
    // 1 2 3 4
    // 3 2 1 4 // 4 2 1 3


    return 0;
}
