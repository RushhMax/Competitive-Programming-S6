#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        int cont = 0;
        char actual = a[0];

        int i = 0;
        for(i = 0; i<a.size(); i++){
            if(!isalpha(a[i])){
                cout<<a[i];
                continue;
            }
            if(a[i] == actual){
                cont++;
                //if(i == a.size()-1){
                //    cout<<cont<<actual;
                //}
            }else{
                cout<<cont<<actual;
                actual = a[i];
                cont = 1;
            }

            if(i == a.size()-1){
                cout<<cont<<actual;
            }
        }

        cout<<endl;
        
        //cout<<actual<<endl;
        //cout<<cont<<actual<<endl;

    }

    return 0;
}
