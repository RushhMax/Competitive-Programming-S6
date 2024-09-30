#include <iostream>
#include <vector>

using namespace std;

bool isBeautifulBinatyMatrix(vector<vector<int>>M){
    int n = M.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1){
                if(M[i][j]!=1){
                    return false;
                }
            }else if(M[i][j]!=0){
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> convert(string s, int r){
    vector<vector<int>>M;
    int n = s.size();
    int cont = 0;
    for(int i=0; i<r; i++){
        vector<int>row;
        for(int j=0; j<(n/r); j++){
            row.push_back(s[cont]-'0');
            cont++;
        }
        M.push_back(row);
    }
    return M;
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        for(int i=2; i<n; i++){
            if(n%i==0){
                vector<vector<int>>M = convert(s, i);
                if(isBeautifulBinatyMatrix(M)){
                    cout<<"Yes"<<endl;
                    goto END;
                }
            }
        }

        cout<<"No"<<endl;
        END:;
    }
}
