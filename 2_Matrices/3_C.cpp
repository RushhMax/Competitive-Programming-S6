#include <iostream>
#include <vector>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower
#include <list>
#include <map>  // arbol binario equilibrado, clave valor
#include <unordered_map> // hash table
#include <set>  // arbol binario equilibrado, valor
#include <unordered_set> // tabla hash
#include <cmath>
#include <sstream> // Necesario para ostringstream

using namespace std;

int main(){
    string input;
    // bool empty = false;
    int k = 0;
    // for(int k= 0; k<100; k++){

    while(getline(cin, input)) {
        int matriz[3][3] = { 0 };
        if(!input.empty()) {

            
            for(int i=0; i<input.size(); i++) {
                if(input[i] == 'a'){
                    matriz[0][0]++;
                    matriz[0][1]++;
                    matriz[1][0]++;
                }
                if(input[i] == 'b'){
                    matriz[0][0]++;
                    matriz[0][1]++;
                    matriz[0][2]++;
                    matriz[1][1]++;
                }
                if(input[i] == 'c'){
                    matriz[0][2]++;
                    matriz[0][1]++;
                    matriz[1][2]++;
                }
                if(input[i] == 'd'){
                    matriz[1][0]++;
                    matriz[1][1]++;
                    matriz[0][0]++;
                    matriz[2][0]++;
                }
                if(input[i] == 'e'){
                    matriz[1][1]++;
                    matriz[1][2]++;
                    matriz[1][0]++;
                    matriz[0][1]++;
                    matriz[2][1]++;
                    
                }
                if(input[i] == 'f'){
                    matriz[1][2]++;
                    matriz[0][2]++;
                    matriz[2][2]++;
                    matriz[1][1]++;
                }
                if(input[i] == 'g'){
                    matriz[2][0]++;
                    matriz[2][1]++;
                    matriz[1][0]++;
                }
                if(input[i] == 'h'){
                    matriz[2][1]++;
                    matriz[2][2]++;
                    matriz[2][0]++;
                    matriz[1][1]++;
                }
                if(input[i] == 'i'){
                    matriz[2][2]++;
                    matriz[2][1]++;
                    matriz[1][2]++;
                }        
            }
        

        cout<<"Case #"<<k+1<<": \n";
        for(int i=0; i<3; i++){
            for(int j=0; j<2; j++){
                cout << matriz[i][j]%10 << " ";
            }
            
            cout<<matriz[i][2]%10 <<endl;
        }
        k++;
    }
    
}
