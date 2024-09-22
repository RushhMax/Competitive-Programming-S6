#include <iostream>
#include <sstream>
#include <vector>

#define vi vector<int>

using namespace std;

void bubbleSort(vi &v){
    for(int i=v.size()-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(v[j]>v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

void print(vi v){
    for(int i=0; i<v.size(); i++){
        if(i!=v.size()-1){
            cout<<v[i]<<"+";
        }else{
            cout<<v[i];
        }
    }

}

int main(){
	
	string s;
	getline(cin, s);
	stringstream nros(s);

	vector<int> nrosIngresados;
	while(getline(nros,s,'+')){
		nrosIngresados.push_back(stoi(s));
	}

    bubbleSort(nrosIngresados);
    print(nrosIngresados);

	return 0;
}



