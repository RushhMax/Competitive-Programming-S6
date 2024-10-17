//#pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math") //Uncomment for a faster runtime
#include <bits/stdc++.h>

//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} 
#define __(x) {cout << #x << " = " << x << " | ";}
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} 
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} 
#define _time_ { auto duration = chrono::duration<double>( /* Show runtime */ \
std::chrono::high_resolution_clock::now() - beg); cout<<"Time: "<<duration.count()<<endl;}
#define _log_ { std::FILE* file = std::freopen("LOG.txt", "w", stdout); }

//Constants
const auto beg = std::chrono::high_resolution_clock::now();
const double PI = acos(-1); 
const double E = 1e-8; 
const int INF = 0x3f3f3f3f; //Big integer that don't cause overflow when doubled
const int MOD = 1e9+7; //Mod operations (prime number)

//Shortened Methods
#define pb push_back
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
                                                                         //
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
    int p; cin>>p; cin.ignore();
    int ind = 1;
    map<int,set<int>> places;
    while(p--){
        string input; getline(cin,input);
        stringstream s(input);
        
        int x;
        int cant = 0;
        while(s>>x){
            cant++;
        }
        places[cant].insert(ind);
        ind++;
    }

    set<int> YES = (places.begin()->second);
    for(auto it= YES.begin() ; it!= YES.end() ; it++){
        cout<<*it;
        if(next(it) != YES.end()){
            cout<<" ";
        }
    }
}

int main(){
	_FasterIO_		//Uncomment for improve runtime
	//_log_			//Uncomment for redirect output to LOG.txt

	int tc; cin>>tc;cin.ignore();
    for(int i=1; i<=tc; i++){
        solve();
        cout<<endl;
    }
    
	//_time_			//Uncomment for show runtime
}
