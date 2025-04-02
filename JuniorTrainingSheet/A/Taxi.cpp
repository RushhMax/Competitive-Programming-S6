#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>=c){ cout<<a<<endl;return 0;}
    int r = (c-a)/(b+d);
    cout<<min((c-(r*d)),a+((r+1)*b))<<endl;
}
