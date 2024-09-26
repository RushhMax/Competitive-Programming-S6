#include <iostream>
#include <vector>
#include <stack>

using namespace std;


vector<int> multiplos(int n){
    vector<int> mult;
    int nro = 2;
    while(n!=1){
        if(n % nro == 0){
            mult.push_back(nro);
            n /= nro;
        }else{
            nro++;
        }
    }
    return mult;
}

vector<int> kMUltiplos(vector<int> multiplos, int k){
    
}

int main(){
    int n;
    cin >> n;
    
    while(n!=0){
        vector<int> mult = multiplos(n);
        for(int i=0; i<mult.size(); i++){
            cout<<mult[i]<<" ";
        }
        

    }

}
