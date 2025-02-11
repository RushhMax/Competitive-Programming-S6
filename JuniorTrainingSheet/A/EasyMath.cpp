#include <bits/stdc++.h>

#define ll long long

using namespace std;
ll mcd(ll a, ll b){
    return b == 0 ? a : mcd(b, a%b);
}
ll mcm(ll a, ll b){
    return (a/mcd(a,b))*b;
}
ll nrosDivisibles(ll x,ll y, ll a){ // 3 10 3 //  6 9  //         
    return (y/a) - ((x-1)/a);
}
int main(){
    int tc;cin>>tc;
    while(tc--){

        ll n,m,a,d; cin>>n>>m>>a>>d;
        vector<ll> nrosDiv = {a, a+d, a+(2*d), a+(3*d), a+(4*d)};

        ll cont = 0;
        for(int i=0; i<nrosDiv.size(); i++){
            cont += nrosDivisibles(n,m, nrosDiv[i]); // 2   3    5
            for(int j=i+1; j<nrosDiv.size(); j++){ // MCM(2 3) mcm(2,5)
                cont -= nrosDivisibles(n,m, mcm(nrosDiv[i], nrosDiv[j]));
                for(int k=j+1; k<nrosDiv.size(); k++){ // MCM(2 3 5) 
                    cont += nrosDivisibles(n,m, mcm(mcm(nrosDiv[i], nrosDiv[j]), nrosDiv[k]));
                    for(int l=k+1; l<nrosDiv.size(); l++){
                        cont -=  nrosDivisibles(n,m,mcm(mcm(mcm(nrosDiv[i],nrosDiv[j]), nrosDiv[k]), nrosDiv[l]));
                        for(int e=l+1; e<nrosDiv.size(); e++){
                            cont += nrosDivisibles(n,m,mcm(mcm(mcm(mcm(nrosDiv[i], nrosDiv[j]), nrosDiv[k]), nrosDiv[l]), nrosDiv[e]));   
                        }
                    }
                }
            }
        }
        //cout<<cont<<endl;
        cout<<m-n+1-cont<<endl;
    }
}
