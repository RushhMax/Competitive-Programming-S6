#include <iostream>
#include <stack>

using namespace std;

void solve(){
    int n;
    cin>>n;
    stack<int> pila;
    for(int i=0; i<n; i++){
        char f,s,t,fo;
        cin>>f>>s>>t>>fo;
        if(f=='#') pila.push(1);
        else if(s=='#') pila.push(2);
        else if(t=='#') pila.push(3);
        else if(fo=='#') pila.push(4);
    }
    
    while(!pila.empty()){
        cout<<pila.top()<<" ";
        pila.pop();
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin>>t;

    for(int i=1; i<=t; i++){
        solve();
    }

}


