#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    set<int> snacks;
    int top = n;
    for(int i=0; i < n;i++){
        int snack;cin>>snack;
        if(snack == top){
            cout<<snack<<" ";
            top--;
            while(top != 0 && snacks.find(top) != snacks.end()){
                cout<<top<<" ";
                top--;
            }
            cout<<endl;
            //imprime recurisva 
        }else{
            snacks.insert(snack);
            cout<<endl;
        }
    }

        
    return 0;
}
