#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;


    while(tc--){
        string s;
        cin>>s;

        string aux;
        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i])){
                aux = s.substr(0,i);
                int num = stoi(aux);
                char c = s[i];

                int cajasG = num / 50;
                num = num % 50;
                int cajasM = num / 10;
                num = num % 10;
                for(int j = 0; j<cajasG; j++){
                    cout<<"["<<c<<"]";
                }
                for(int j=0; j<cajasM; j++){
                    cout<<"{"<<c<<"}";
                }
                if(num>0){
                    cout<<"(";
                    for(int j=0; j<num; j++){
                        cout<<c;
                    }
                    cout<<")";
                }
                

                //cout<<aux<<endl;



                s = s.substr(i+1, s.size() - aux.size());
                i = 0;
            }
        }
        cout<<endl;

    }
}
