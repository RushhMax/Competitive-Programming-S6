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

int main(){
    string input;
    while (getline(cin, input)) {
        if (input.empty()) {
            break; // Termina cuando no se inserta ninguna línea
        }

        bool first_last = true; 
        int max;
        int antX = 0;
        for(int i=1; i<=input.size(); i++){
            if(input[i-1] == 'X'){
                if(first_last) {
                    if(i < 2) max = 0;
                    else max = i - 2;
                    first_last = false;
                }
                else{
                    int dist = i - antX - 1;
                    dist = (dist % 2 == 0 ? (dist/2)-1 : (dist/2));
                    if(dist > max){
                        max = dist;
                    }
                }
                antX = i;
            }
        }
        if (antX < input.length() && (input.length() - antX - 1) > max) {
            max = input.size() - antX - 1;
        }
        cout<<max<<endl;
    }
}


