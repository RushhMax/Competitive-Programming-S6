#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    int index = 0;
    vector<int> garden(n,0);
    for(int i = 0; i < n; i++){
        cin>>garden[i];
        if(garden[i] < garden[index]){
            index = i;
        }
    }

    vector<int> maxGarden;
    for(int i = 0; i < n; i++){
        if(garden[i] == garden[index]){
            maxGarden.push_back(i);
        }
    }


    int best = 0;
    for(int k=0; k<maxGarden.size(); k++){
        int right = 1;
        int aux = maxGarden[k];
        for(int i = aux + 1; i < n && garden[i] >= garden[aux]; i++, aux++){
            right++;
        }
        int left = 1;
        aux = maxGarden[k];
        for(int i = aux - 1; i >= 0 && garden[i] >= garden[aux]; i--, aux--){
            left++;
        }
    
        int ans = left > right? left : right;

        if(ans > best) best = ans;
    }
    cout<<best<<endl;

    return 0;
}
