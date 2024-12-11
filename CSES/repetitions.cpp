#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;

    int letter = s[0];
    int count = 0;
    int best = 1;
    for(int i = 0; i < s.size();i++){
        if(s[i] == letter){
            count++;
        }else{
            best = max(best, count); 
            letter = s[i];
            count = 1;
        }
    }

    best = max(best, count);

    cout<<best<<endl;


    return 0;
}
