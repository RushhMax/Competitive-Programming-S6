#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;cin>>tc;
	while(tc--){
	    int k; cin>>k;
	    bool repetido = false; int num;
	    map<int,int> mapa;
	    for(int i=0;i<k; i++){
	       int x;cin>>x;
	       mapa[x]++;
	       if(mapa[x]>2){
	           repetido = true;
	           num = x;
	       }
	    }
	    
	    if(repetido) cout<<"1\n"<<num<<endl;
	    else cout<<-1<<endl;
	}
}
