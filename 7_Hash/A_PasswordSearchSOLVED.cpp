#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    string s;
    while(cin>>n, cin>>s){
        map<string, int> m;
        for(int i=0; i<=s.size()-n; i++){
            m[s.substr(i,n)]++;
        }

        int max = 0;
        string out = m.begin()->first; 
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second >= max){
                max = it->second;
                out = it->first;
            }
        }

        cout<<out<<endl;
    }
}
