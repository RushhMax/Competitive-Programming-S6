#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;

        pair<int,int> par = {0,0};
        pair<int,int> impar = {0,0};

        if(a%2 == 0) {
            par.first = a;
            impar.first = a+1;
        }else{
            par.first = a+1;
            impar.first = a;
        }

        if(b%2==0){
            par.second = b;
            impar.second = b-1;
        }else{
            impar.second = b;
            par.second = b-1;
        }

        //cout<<"Par "<<par.first<<" "<<par.second<<endl;
        //cout<<"Impar "<<impar.first<<" "<<impar.second<<endl;

        int n = par.second/2;
        int n1 = (par.first-2)/2;
        //cout<<" n : "<<n<<" "<<n1<<endl;
        int sumPar = ((n)*(n+1)) - (n1*(n1+1));
        //cout<<sumPar<<endl;
        n =  (impar.second+1)/2;
        n1 = (impar.first-2+1)/2;
        //cout<<" m: "<<n<<" "<<n1<<endl;
        int sumImpar = (n*n) - (n1*n1);
        //cout<<sumImpar<<endl;

        cout<<sumPar-sumImpar<<endl;
    }

    // 2 + 4 + 6 + 2n = n*(n+1)
    // 1 + 3 + 5 + 7 + 9 + 2n-1 = n+n 
    // 2 4 6 8 = 20 // 4(5)
    // 1 3 5 7 9 11 // 11 = 2n-1 = 36 // 
    // 3 4 5 6
    // 8
    // 10
    //
    // 3 4 5 6 7 // 3 7 
    // 15
    // 10
    //alice par
}
