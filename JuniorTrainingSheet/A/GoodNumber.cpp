#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int ans = 0;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        //bool kgood = true;
        set<int> numbers;
        for(int j=0; j<(int)x.size(); j++){
            //if(x[j] > std::to_string(k)[0]){
            //    kgood = false;
            //    break;
            //}else{
            if(x[j] <= std::to_string(k)[0]){
                numbers.insert(x[j]-'0');
            }
        }
        if(numbers.size() == k+1){ ans++;}
    }
    cout<<ans<<endl;
}
