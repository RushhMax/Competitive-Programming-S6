#include <iostream>
#include <algorithm>
#include <functional>  
#include <vector>

using namespace std;

int main(){
    int n, m;
    while(cin>>n>>m && n!=0 && m!=0){
        vector<int> M;
        for(int i=0; i<n; i++){
            int aux;
            cin>>aux;
            M.push_back(aux);
        }

        sort(M.begin(), M.end(), [m](int a, int b){
            if(a%m != b%m){
                return a%m < b%m;
            }else{
                if(a%2!=0 && b%2==0){
                    return true;
                }else if(a%2==0 && b%2!=0){
                    return false;
                }else if(a%2!=0 && b%2!=0){ // si ambos son impares
                    return a>b;
                }else{
                    return a<b; // si ambos pares
                }
            }
        });

        cout<<n<<" "<<m<<endl;
        for(int i=0; i<n; i++){
            cout<<M[i]<<endl;
        }
    }

    cout<<"0 0"<<endl;

}
// RUNTIME ERROR!!!

// int main(){
//     while(true){
//         int n, m;
//         cin>>n>>m;
//
//         if(n==0 || m==0){
//             break;
//         }
//
//         vector<vector<int>> M(m);
//         for(int i=0; i<n;i++){
//             int aux;
//             cin>>aux;
//             M[aux%m].push_back(aux);
//         }
//
//         for(int i=0; i<m;i++){
//             vector<int> pares, impares;
//
//             for(int j=0; j<M[i].size(); j++){
//                 if(M[i][j]%2==0){
//                     pares.push_back(M[i][j]);
//                 }else{
//                     impares.push_back(M[i][j]);
//                 }
//             }
//
//             sort(pares.begin(), pares.end());
//             sort(impares.begin(), impares.end(), greater<int>());
//             
//             M[i].clear();
//
//             M[i].insert(M[i].end(), impares.begin(), impares.end());
//             M[i].insert(M[i].end(), pares.begin(), pares.end());
//         }
//
//         cout<<n<<" "<<m<<endl;
//         for(int i=0; i<m; i++){
//             for(int j=0; j<M[i].size(); j++){
//                 cout<<M[i][j]<<endl;
//             }
//         }
//     }
// }
