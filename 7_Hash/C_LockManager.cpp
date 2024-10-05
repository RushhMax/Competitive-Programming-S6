#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

void solve(){
    map<int, vector<pair<char, int>>> process;
    map<int, int> denieds;

    char T;
    int NT,NDT;
    while (cin>>T && T != '#'){
        cin >> NT >> NDT;

        //cout<<T<<" "<<NT<<" "<<NDT<<endl;

        bool haveX = false;
        bool done = false;

        if (denieds.find(NT) == denieds.end()){
            for (auto &lock : process[NDT]){
                if (lock.first == 'X'){
                    haveX = true;
                }
                if (lock.second == NT){
                    process[NDT].push_back({T, NT});
                    cout << "GRANTED\n";
                    done = true;
                    break;
                }
            }

            if(!done){ 
                if (haveX || ( T == 'X' && !process[NDT].empty())){
                    cout << "DENIED\n";
                    denieds[NT] = 1;
                } else {
                    process[NDT].push_back({T, NT});
                    cout << "GRANTED\n";
                }
            }
        } else {
            cout << "IGNORED\n";
        }
    }
    cout<<endl;
}


int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }
}

// S 1 1           f
// S 2 2            g
// X 10 1         D
// S 6 123456789    G
// S 3 3              G
// X 2 2               G
// S 5 6                G
// S 3 1                G
// S 3 2                    D
// X 987654321 123456789    D
// X 1 4                    G
// S 6 6                    G
// S 3 5                    I
// S 2 4                    D
// X 4 5                    G
// S 2 51                   I
