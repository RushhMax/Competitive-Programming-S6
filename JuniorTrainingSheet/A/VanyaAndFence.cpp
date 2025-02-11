#include <iostream>

using namespace std;

int main(){
    int n,h;
    cin>>n>>h;

    int sum = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x > h)sum += 2;
        else sum++;
    }

    cout<<sum;

    return 0;
}
