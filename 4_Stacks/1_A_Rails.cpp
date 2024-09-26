#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;

    while(cin>>n && n!=0){     
        while(true){
            int cont = 1;   
            stack<int> station;        
            bool valid = true;
            
            int vagon;
            cin>>vagon;
            if (vagon == 0) {
                cout << endl;
                break;
            }

            for(int i=0; i<n; i++){
                if(i>0){
                    cin>>vagon;
                }
                while(cont<=vagon){
                    station.push(cont++);
                }
                if(!station.empty() && vagon == station.top()){
                    station.pop();
                }else {
                    valid = false;
                }   
            }
            if(valid)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}