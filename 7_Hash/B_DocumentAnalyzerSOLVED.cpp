#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <climits>
#include <set>

using namespace std;

void solve(int tc){
    string s;
    map<string,int> wordCounter;
    vector<string> words;
    
    while(getline(cin,s) && s != "END"){    
        for(char & c : s){
            if(c < 'a' || c > 'z'){
                c = ' ';
            }
        }

        stringstream ss(s);
        while(ss>>s){
            wordCounter[s]++;
            words.push_back(s);
        }

    }

    int size = wordCounter.size();
    map<string, int> actual;
    int p = -1, q = -1;
    int min = INT_MAX;
    int left = 0, right = 0;

    while(right < words.size()){
        string word = words[right];
        actual[word]++;
        right++;

        while(actual.size() == wordCounter.size()){
            if(right - left < min){
                min = right - left;
                p = left;
                q = right;
            }

            string word = words[left];
            actual[word]--;
            if(actual[word] == 0){
                actual.erase(word);
            }
            left++;
        }
    }

    cout<<"Document "<<tc<<": "<<p+1<<" "<<q<<"\n";
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=1; i<=n; i++){
        solve(i);
    }    
}
