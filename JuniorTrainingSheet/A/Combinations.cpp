#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        long double ans=1;

        int nm = n-m;
        int auxM = m;
        for(int i=n; i>0; i--){
            ans *= i;
            if(auxM > 0) {
                ans /= auxM;
                auxM--;
            }else if(nm > 0){
                ans /= nm;
                nm--;
            }
        }

        cout<<fixed<<setprecision(0);
        cout<<n<<" things taken "<<m<<" at a time is "<<ans<< " exactly."<<endl;
    }
}
