#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned int j,i,n,k;
    unsigned int a;
    cin>>n>>k;
    unordered_map<unsigned int,unsigned int> divs;
    vector<vector<unsigned int>> nums(n);

    for(i=0; i<n; i++){
        cin>>a;
        for(j=1;j*j<=a;j++){
            if(a%j == 0){
                divs[j]++;
                nums[i].push_back(j);
                if(j!=a/j){
                    divs[a/j]++;
                    nums[i].push_back(a/j);
                }
            }
        }

        sort(nums[i].begin(), nums[i].end());
    }

    for(const auto &sets: nums){
        for(unsigned int d : sets){
            if(divs[d] >= k){
                cout<<d<<endl;
                break;
            }
        }
    }
	return 0;
}
