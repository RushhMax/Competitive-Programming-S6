#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve(){
    int l;
    cin>>l;
    stack<ll> fors;
    fors.push(1);
    ll n = 0;
    
    ll limit = (1ULL << 32) - 1;

    cin.ignore();

    bool over = false;
    for(int i=0; i<l; i++){
        string s;
        getline(cin,s);

        if(s == "add"){
            if(fors.top() == limit+1) over = true;
            else n += fors.top();
        }else if(s.find("for") != string::npos){
            ll f = stoi(s.substr(4));
            ll push_ = fors.top() * f;
            if(push_ > limit) fors.push(limit+1);
            else fors.push(push_);
        }else if(s == "end"){
            fors.pop();
        }
    }

    if(n > limit || over)
        cout<<"OVERFLOW!!!\n";
    else 
        cout<<n<<endl;

}

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
