#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int step, mod;
    while(cin>>step>>mod){
        //int actual = 0;
        //set<int> numbers;
        //do{
        //for(int i=0; i < mod; i++){
        //    numbers.insert(actual%mod);
        //    //if(numbers[0] > 1) break;
        //    actual += step;
        //}
        //}while(numbers.size() < mod);
        

        int a = (mod > step) ? mod : step;
        int b = (mod < step) ? mod : step;
        int r;
        do{
            r = a%b;
            a = b;
            b = r;
        }while(r);


        string stepstr = to_string(step);
        string modstr = to_string(mod);
        cout<<string(10-stepstr.size(), ' ')<<stepstr<<string(10-modstr.size(), ' ')<<modstr<<string(4,' ');
       
        if(a == 1)cout<<"Good Choice\n";
        else cout<<"Bad Choice\n";

        cout<<endl;

    }
    return 0;
}
