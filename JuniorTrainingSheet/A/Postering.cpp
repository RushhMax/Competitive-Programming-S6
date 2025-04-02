#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);

    queue<int> menores;
    int menor = INT_MAX;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        cin>>v[i];
        if(v[i] < menor) menor = v[i];
    }
    menores.push(menor);

    int ans = 0;
    while(accumulate(v.begin(), v.end(), 0) > 0){
        bool flag = false;

        if(menores.empty()) break;
        menor = menores.front();
        menores.pop(); //1 2
        for(int i=0; i<n; i++){
            if(menor == 0) continue;
            if(v[i] < menor && flag) { 
                flag = false;
                if(menores.empty()) { break;}
                menor = menores.front();
                menores.pop();
            }
            if(v[i] >= menor){
                if(menor == 0)continue;
                if(!flag) { ans++;}
                flag = true;
                v[i] -= menor;
            }
        }

        menor = INT_MAX;
        for(int i=0; i<n; i++){
            if(v[i] == 0){ 
                if(menor != 0 && menor!=INT_MAX) menores.push(menor);
                menor = INT_MAX;
                continue; 
            }
            if(v[i] < menor) menor = v[i];
        }
        if(v[n-1] != 0) menores.push(menor);
    }
    cout<<ans<<endl;
}
