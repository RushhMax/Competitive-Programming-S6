#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


int main(){
    string input;
    int cont = 1;
    while(cin>>input && input != "end"){
        vector<char> stacks;
        for(int k=0; k<input.size(); k++){
            bool added = false;
            for(int i=0; i < stacks.size(); i++){
                if(input[k] <= stacks[i]){
                    stacks[i] = input[k];
                    added = true;
                    break;
                }
            }
            if(!added){
                stacks.push_back(input[k]);
            }
        }
        cout<<"Case "<<cont<<": "<<stacks.size()<<endl;
        cont++;
    }
}

// WRONG ANSWER

// int main(){
//     string input;
//     int cont = 1;
//     while(cin>>input && input != "end"){
//         unordered_set<char> letras;
//         letras.insert(input[0]);
//         char letra = input[0];
//         int contStacks = 1;
//         for(int i=1; i<input.size(); i++){
//             if(input[i] != letra){
//                 if(letras.find(input[i]) == letras.end()){
//                     letras.insert(input[i]);
//                 }
//                 if(letra < input[i]){
//                     contStacks++;
//                 }
//                 letra = input[i];
//             }
//         }
//
//         cout<<"Case "<<cont<<": ";
//         contStacks <= letras.size() ? cout<<contStacks<<endl : cout<<letras.size()<<endl;
//         cont++;
//     }
// }
