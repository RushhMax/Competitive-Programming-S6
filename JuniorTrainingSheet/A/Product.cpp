#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x,y;
    while(cin>>x>>y){
        vector<int> product(500,0);
        
        int aux = 0;
        for(int j= y.size()-1; j>=0; j--){
            aux = y.size()-1 - j;
            for(int i=x.size()-1; i>=0; i--){
                int a = x[i] - '0';
                int b = y[j] - '0';
                product[aux] += a*b;
                int k = aux;
                while(product[k] >= 10){
                    product[k+1] += product[k]/10;
                    product[k] = product[k]%10;
                    k++;
                }
                aux++;
            }
        }

        bool flag = false;
        for(int i = 500; i>=0; i--){
            if(product[i] != 0)flag = true;
            if(flag) cout<<product[i];
            if(i == 0 && !flag) cout<<0;
        }
        cout<<endl;
    }

    return 0;
}
