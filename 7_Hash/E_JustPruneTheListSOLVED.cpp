#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <list>                                                                                            
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    map<int, int> numbers1;
    map<int, int> numbers2;

    int aux;
    for(int i=0;i<n;i++){
        cin>> aux;
        numbers1[aux]++;
    }

    for(int i=0;i<m;i++){
        cin>>aux;
        numbers2[aux]++;
    }   

    int cont = 0;
    map<int, int> done;

    for (const auto &pair : numbers1) {
        bool found = false;
        for (const auto &pair2 : numbers2) {
            if(pair.first == pair2.first) found = true;
            if(!(done.find(pair.first) != done.end())){
                if(pair.first == pair2.first && pair.second != pair2.second){
                    cont = cont + abs(pair.second - pair2.second);  
                    done[pair.first]++;  
                }
            }
        }
        if(!found && !(done.find(pair.first) != done.end())){
            cont += pair.second;
            done[pair.first]++;
        }
    }

    for (const auto &pair : numbers2) {
        bool found = false;
        for (const auto &pair2 : numbers1) {
            if(pair.first == pair2.first) found = true;
            if(!(done.find(pair.first) != done.end())){
                if(pair.first == pair2.first && pair.second != pair2.second){
                    cont = cont + abs(pair.second - pair2.second);  
                    done[pair.first]++;   
                }
            }
        }
        if(!found && !(done.find(pair.first) != done.end())){
            cont += pair.second;
            done[pair.first]++;
        }
    }
    cout<<cont<<endl;
}


int main() {
    int tc;
    cin>>tc;

    while (tc--) {
        solve();
    }

}


//
// 5 5
// 1 2 3 2 1
// 1 2 5 2 3
