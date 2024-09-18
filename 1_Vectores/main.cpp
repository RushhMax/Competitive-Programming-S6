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
#include <bitset>

using namespace std;

// int main(){
//     string input;
//     while (getline(cin, input)) {
//         if (input.empty()) {
//             break; // Termina cuando no se inserta ninguna línea
//         }
//         stringstream ss(input); // Convertir la línea a un stream
//         int v, t;
//         ss >> v >> t; // Leer los valores de la línea
//         cout << v * 2 * t << endl;
//     }

//     return 0;
// }

int main(){
    
    string first;
    while (getline(cin, first)) {
        if (first.empty()) {
            break; // Termina cuando no se inserta ninguna línea
        }

        string second;
        getline(cin, second);

        bool letter = false;

        for(int i=0; i<first.size(); i++){
            if(first[i] == ' ' || second[i] == ' ') continue;
            if(!(first[i]^second[i])) {
                cout<<"N"<<endl;
                letter = true;
                break;
            }else{

            }
        }
        if(!letter)cout<<"Y"<<endl;
    }
}