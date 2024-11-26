//#pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math") //Uncomment for a faster runtime
#include <bits/stdc++.h>
//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} //Print with endl
#define __(x) {cout << #x << " = " << x << " | ";} //Print without endl
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} //Print entire vector
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} //Print pair
#define _time_ { auto duration = chrono::duration<double>( /* Show runtime */ \
std::chrono::high_resolution_clock::now() - beg); cout<<"Time: "<<duration.count()<<endl;}
#define _log_ { std::FILE* file = std::freopen("LOG.txt", "w", stdout); }
//Constants
const auto beg = std::chrono::high_resolution_clock::now(); //Begining of the program
const double PI = acos(-1); //PI
const double E = 1e-8; //Small Number (10^-8)
const int INF = 0x3f3f3f3f; //Big integer that don't cause overflow when doubled
const int MOD = 1e9+7; //Mod operations (prime number)
//Shortened Methods
#define mp make_pair
#define ff first
#define ss second
//Shortened Types
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<std::string> vs;
typedef std::vector<std::pair<int, int>> vpii;
typedef std::map<int, int> mii;
typedef std::map<ll, ll> mll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::pair<std::string, int> psi;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>; //Min Heap
//loops
#define f(i,n) for(int i=0;i<n;i++) //From 0 to n-1
#define rf(i,n) for(int i=n-1;i>=0;i--) //From n-1 to 0
#define F(i,a,b) for(int i=a;i<b;i++) // From a to b-1
#define RF(i,a,b) for(int i=a;i>=b;i--) // From a to b-1
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define RFOR(it,c) for ( __typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); it++ )
#define REP(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end();)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(x) ((int)(x).size())
#define ms(arr,val) memset(arr,val,sizeof(arr))
//IO Optimization
#define _FasterIO_ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


/* ############################################################################################## */


void solve(){
    char N;
    cin>>N;
    cin.ignore();

    vector<set<char>> A; 
    string str;
    while(getline(cin,str) && !str.empty()){
        
        stringstream inp(str);
        char first, second;inp>>first>>second;
        //_(first);
        //_(second);

        vector<int> doit;
        bool doi = false;
        bool finaldoi = false;
        for(int i=0; i<A.size(); i++){ 
            if(A[i].find(first) != A[i].end()){ 
                //cout<<"se1 \n ";
                //_(first);
                A[i].insert(second);
                doi = true;
            }
            if(A[i].find(second) != A[i].end()) {
                //cout<<"se2\n";
                //_(second);
                A[i].insert(first);
                doi = true;
            }
            if(doi){
                doi = false;
                finaldoi = true;
                //cout<<"treu";
                doit.push_back(i);
            }
            if(doit.size() == 2){
                if(doit[0] != doit[1]){
                    //cout<<"join";
                    // unir i y j
                    A[doit[0]].insert(all(A[doit[1]]));
                    A.erase(A.begin() + doit[1]);
                    doit.clear();
                    break;      
                }
            }
        }
        if(!finaldoi){
            //cout<<"NEW "<<first<<" "<<second<<"\n";
            set<char> aux;
            aux.insert(first); aux.insert(second);
            A.push_back(aux);
        }
        //cout<<"PRINT\n";
        //f(i,A.size()){
        //    for(auto it = A[i].begin(); it!=A[i].end(); it++){
        //        cout<<*it<<" ";
        //    }
        //    cout<<endl;
        //}
        
    }

    // count from A to char N
    int noindent = 0;
    for(char f = 'A'; f <= N; f++){
        bool found = false;
        for(auto &a : A){
            if(a.find(f)!= a.end()){
                found = true;
                break;
            }
        }
        if(!found){
            noindent++;
        }
    }

    cout<<A.size()+noindent<<endl;

}

int main(){
	_FasterIO_		//Uncomment for improve runtime
	//_log_			//Uncomment for redirect output to LOG.txt

    int tc;cin >> tc;cin.ignore();
    f(i,tc){
        solve();
        if(i < tc-1){
            cout<<endl;
        }
        
    }
    
 //        string line;
	// while(getline(cin,line)){
	// 	cout << line << endl;
	// }

	//_time_			//Uncomment for show runtime
}
