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

void deletenumber(vector<int> &v, int n){
    for(int i=0; i<v.size(); i++){
        if(v[i]==n){
            v.erase(v.begin()+i);
            return;
        }
    }
}

int findNumber(vector<vector<int>> &v, int n, int number){
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j]==number){
                return i;
            }
        }
    }
    return -1;
}

int findNumberIndex(vector<vector<int>> &v, int n, int number){
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j]==number){
                return j;
            }
        }
    }
    return -1;
}

void returnInitialPositions(vector<vector<int>> &v, int n, int index){
    vector<int> temp;
    for (int j = 0; j < v[index].size(); j++) {
        int numero = v[index][j];
        temp.push_back(numero); // Almacena el número para moverlo
    }
    v[index].clear();
    for (int num : temp) {
        v[num].push_back(num); 
    }
}


int main(){
    int n;
    cin>>n;

    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        v[i].push_back(i);
    }

    string commands;
    while(getline(cin, commands)){
        if(commands == "quit") break;

        istringstream iss(commands);
        string aux;
        getline(iss, aux, ' ');
        if(aux == "move"){
            getline(iss, aux, ' ');
            int from = stoi(aux);
            getline(iss, aux, ' ');
            int to;
            if(aux == "onto"){
                getline(iss, aux, ' ');
                to = stoi(aux);
                returnInitialPositions(v,n,to);
                v[findNumber(v, n, to)].push_back(from);
                deletenumber(v[from], from);
            }
            if(aux == "over"){
                getline(iss, aux, ' ');
                to = stoi(aux);
                v[findNumber(v, n, to)].push_back(from);
                deletenumber(v[from], from);
            }
        }
        if(aux == "pile"){
            getline(iss, aux, ' ');
            int from = stoi(aux);
            getline(iss, aux, ' ');
            int to;
            if(aux == "onto"){
                getline(iss, aux, ' ');
                to = stoi(aux);
                returnInitialPositions(v,n,to);
                vector<int> & destino = v[findNumber(v, n, to)]; // destino;
                vector<int> & inicio = v[findNumber(v, n, from)];
                std::copy(inicio.begin() + findNumberIndex(v,n,from), inicio.end(), std::back_inserter(destino));
                inicio.erase(inicio.begin() + findNumberIndex(v,n,from), inicio.end());
            }
            if(aux == "over"){
                getline(iss, aux, ' ');
                to = stoi(aux);
                vector<int> & destino = v[findNumber(v, n, to)]; // destino;
                vector<int> & inicio = v[findNumber(v, n, from)];
                std::copy(inicio.begin() + findNumberIndex(v,n,from), inicio.end(), std::back_inserter(destino));
                inicio.erase(inicio.begin() + findNumberIndex(v,n,from), inicio.end());
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<i<<": ";
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}