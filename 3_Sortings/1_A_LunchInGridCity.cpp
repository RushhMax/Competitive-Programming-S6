#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int street, avenue, friends;
        cin>>street>>avenue>>friends;

        vector<int> streets;
        vector<int> avenues;
        for(int i=0; i<friends; i++){
            int x,y;
            cin>>x>>y;
            streets.push_back(x);
            avenues.push_back(y);
        }

        sort(streets.begin(), streets.end());
        sort(avenues.begin(), avenues.end());

        int resultStreet = streets[(friends - 1) / 2];
        int resultAvenue = avenues[(friends - 1) / 2];

        cout<<"(Street: "<<resultStreet<<", Avenue: "<<resultAvenue<<")\n";
    }
}
