#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;


void solve(int tc){
    string s;
    int p,q;

    map<string,vector<int>> words;
    int cont = 1;
    
    while(getline(cin,s) && s != "END"){    
        for(char & c : s){
            if(c < 'a' || c > 'z'){
                c = ' ';
            }
        }

        stringstream ss(s);
        while(ss>>s){
            words[s].push_back(cont);
            cont++;
        }

        // for(auto & p : words){
        //     cout<<p.first<<":";
        //     for(int i=0; i<p.second.size(); i++){
        //         cout<<" "<<p.second[i];
        //         if(i+1 < p.second.size()){
        //             cout<<",";
        //         }
        //     }
        //     cout<<"\n";
        // }

    }
    vector<int> rango;
    for(auto & p : words){
        if(p.second.size() > 1){
            
        }
    }


    cout<<"Document "<<tc<<": ";

}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=1; i<=n; i++){
        solve(i);
    }    
}
