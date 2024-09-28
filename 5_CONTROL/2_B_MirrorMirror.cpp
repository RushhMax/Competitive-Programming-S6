#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void rotateMatrix(vector<vector<char>> &M){
    int size = M.size();
    int begin = 0;
    int last = size - 1;
    while(begin < last){
        for(int i= begin; i < last; i++){
            char top = M[begin][i];
            // left
            M[begin][i] = M[(last-i)+begin][begin];
            // down
            M[(last-i)+begin][begin] = M[last][(last-i)+begin];
            // rigth
            M[last][last-i+begin] = M[i][last];

            M[i][last] = top;
        }
        last--;
        begin++;
    }
}

void verticalReflectionMatrix(vector<vector<char>> &M){
    int cont = 0;
    int final = M.size() -1;
    while(cont < final ){
        for(int i=0; i<M.size(); i++){
            int aux = M[cont][i];
            M[cont][i] = M[final][i];
            M[final][i] = aux;
        }
        cont++;
        final--;
    }
}

bool compare(vector<vector<char>> O, vector<vector<char>> N){
    for(int i=0; i<N.size();i++){
        for(int j=0; j<N.size();j++){
            if(O[i][j] != N[i][j]){
                return false;
            }
        }
    }
    return true;
}

void printMatrix(vector<vector<char>> &M){
    for(int i=0; i<M.size(); i++){
        for(int j=0; j<M[i].size(); j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    int cont = 1;
    while(cin>>n){
        cin.ignore();

        vector<vector<char>>Moriginal(n, vector<char>(n, '.' ));
        vector<vector<char>>Mnew(n, vector<char>(n, '.' ));
        
        for(int i=0; i<n; i++){
            string input;
            getline(cin,input);

            string original = input.substr(0, n); 
            string nueva = input.substr(n+1,n);

            for(int j=0; j<n; j++){
                Mnew[i][j] = original[j];
                Moriginal[i][j] = nueva[j];
            }
        }

        // PRESERVED
        if(compare(Moriginal, Mnew)){
            cout<<"Pattern "<<cont<<" was preserved."<<endl;
            cont++;
            continue;
        }

        vector<vector<char>> rotacion = Mnew;
        for(int i=0; i<3; i++){
            rotateMatrix(rotacion);
            //printMatrix(rotacion);
            if(compare(Moriginal, rotacion)){
                cout<<"Pattern "<<cont<<" was rotated "<<(i+1)*90<<" degrees."<<endl;
                goto nextPattern;
            }
        }
        
        // VERTICAL verticalReflectionMatrix
        rotateMatrix(rotacion);
        verticalReflectionMatrix(rotacion);
        //printMatrix(rotacion);
        if(compare(Moriginal, rotacion)){
            cout<<"Pattern "<<cont<<" was reflected vertically."<<endl;
            cont++;
            continue;
        }

        // REFLECTED + ROTATION
        for(int i=0; i<3; i++){
            rotateMatrix(rotacion);
            //printMatrix(rotacion);
            if(compare(Moriginal, rotacion)){
                cout<<"Pattern "<<cont<<" was reflected vertically and rotated "<<(i+1)*90<<" degrees."<<endl;
                goto nextPattern;
            }
        }


        cout << "Pattern " << cont << " was improperly transformed." << endl;
        //printMatrix(Moriginal);
        //printMatrix(Mnew);

        nextPattern:
        cont++;
    }

}
