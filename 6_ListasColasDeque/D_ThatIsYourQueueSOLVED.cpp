#include <bits/stdc++.h>

using namespace std;

void solve(int p, int c, int i){

    list<int> cola;
    for(int j=1; j<=min(p,c) ; j++){
        cola.push_back(j);
    }

    cout<<"Case "<<i<<":\n";
    
    char next;
    for(int j=0; j<c; j++){
        cin>>next;
        if(next == 'N'){
            cout<<cola.front()<<endl;
            cola.push_back(cola.front());
            cola.pop_front();
        }else if(next == 'E'){
            int x;
            cin>>x;
            cola.remove(x);
            cola.push_front(x);
        }
    }

}

int main(){
    int p,c;
    int tc = 1;
    while(cin>>p>>c && p != 0 && c != 0){
        solve(p,c,tc);
        tc++;
      
    }
}
