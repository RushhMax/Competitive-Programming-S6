#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> stewards;
    for(int i=0 ; i<n; i++){
        int x;cin>>x;
        stewards.push_back(x);
    }

    sort(stewards.begin(), stewards.end());
    stewards.erase(stewards.begin(), upper_bound(stewards.begin(), stewards.end(), stewards[0]));
    stewards.erase(lower_bound(stewards.begin(), stewards.end(), stewards.back()), stewards.end());


    if(stewards.size()>=0){
        cout<<stewards.size()<<endl;
    }else{
        cout<<0<<endl;
    }
}
