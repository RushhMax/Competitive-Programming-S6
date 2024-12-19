#include <bits/stdc++.h>

using namespace std;

char nots[7] = {'4','7','A','b','C','d','F'};

bool isNO(char a){
    for(int i=0; i<7; i++){
        if(a == nots[i]) return true;
    }
    return false;
}

bool compare (char a, char b){
        if(a == '0' && b == '0') return true;
        if(a == '1' && b == '1') return true;
        if(a == '2' && b == '2') return true;
        if(a == '3' && b == 'E') return true;
        if(a == '5' && b == '5') return true;
        if(a == '6' && b == '9') return true;
        if(a == '8' && b == '8') return true;
        if(a == '9' && b == '6') return true;
        if(a == 'E' && b == '3') return true;
        return false;
}

int main(){
    string input;
    cin>>input;

    int cont = 0;
    int mid = (input.size()%2==0? input.size()/2 : (input.size()/2)+1);
    for(int i=0; i<mid;i++){
        char f = input[i];
        char s =input[input.size()-1-i];
        
        bool No1 = isNO(f);
        bool No2 = isNO(s);
        if(No1 || No2){
            if(No1 && No2){
                cont+=2;
            }else{
                cont++;
            }
            continue;
        }
    
        if(!compare(f, s)){
            cont++;
        }else if(!compare(s,f)){
            cont++;
        }
    }   

    cout << cont << endl;

    return 0;
}
