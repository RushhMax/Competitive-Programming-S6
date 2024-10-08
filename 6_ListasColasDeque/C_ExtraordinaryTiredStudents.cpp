#include <bits/stdc++.h>

using namespace std;

bool any_sleep(vector<vector<int>> v, int index){
    for(vector<int> vector : v){
        if(index < vector.size() && vector[index] == 1) return true;
    }
    return false;
}

void solve(int n, int tc){

    vector<vector<int>> v;
    vector<pair<int,int>> data;
    for(int i = 0; i < n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        data.push_back({a,b});
    
        vector<int> temp(a+b, 0);
        fill(temp.begin(), temp.begin() + a, 0);
        fill(temp.begin() + a, temp.begin() + a + b, 1);

        temp.erase(temp.begin(), temp.begin()+(c-1));

        v.push_back(temp);
    }

    int index = 0;
    int max_time = 100;
    while(index < max_time && any_sleep(v, index)){
        int students = v.size();
        for(int i = 0; i < students; i++){
            if(index >= v[i].size() /*|| v[i][index] == 0*/){   
                //cout<<"I:"<<index<<" en "<<i<<endl;
                index += (data[i].first-1);
                int suma = 0;
                for(int j=0; j < students; j++){
                    if(index < v[j].size()) suma += v[j][index];
                }

                if(suma > students/2){
                    v[i].insert(v[i].end(), data[i].first, 0);
                    v[i].insert(v[i].end(), data[i].second, 1);
                }else{
                    v[i].insert(v[i].end(), (data[i].first)*2 , 0);
                }
                index -= (data[i].first+1);
            }                                           
        }
        index++;
        // for(vector<int> vector : v){
        //     for(int i : vector){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    if(index >= max_time) cout<<"Case "<<tc<<": "<<-1<<endl;
    else cout<<"Case "<<tc<<": "<<index+1<<endl;
}

int main(){
    int n;
    int tc = 1;
    while(cin>>n && n!=0){
        solve(n, tc);
        tc++;
    }
}
