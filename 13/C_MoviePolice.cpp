/* ######################## Template available in: https://propi.dev/cp  ######################## */
//#pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math") //Uncomment for a faster runtime
#include <bits/stdc++.h>
//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} //Print with endl
#define __(x) {cout << #x << " = " << x << " | ";} //Print without endl
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} //Print entire vector
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} //Print pair
#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
std::chrono::high_resolution_clock::now() - beg); cout<<"Time: "<<duration.count()<<endl;}
#define __log__ { std::FILE* file = std::freopen("LOG.txt", "w", stdout); }
//Constants
const auto beg = std::chrono::high_resolution_clock::now(); //Begining of the program
const double PI = acos(-1); //PI
const double E = 1e-8; //Small Number (10^-8)
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

/* ############################################################################################## */


int main(){
	//__log__			//Uncomment for redirect output to LOG.txt

    int m,q; cin>>m>>q;
    vector<string> movies;
    f(i,m){
        string s; cin>>s;
        movies.pb(s);
    }

    f(i,q){
        string s; cin>>s;
        int min = INF, index = -1;
    
        f(j, m){
            string mov = movies[j];
            if(mov.size() < sz(s)) continue;

            for(int ini = 0; ini <= mov.size() - sz(s); ini++){
                int dif = 0;
                f(j,sz(s)){
                    dif += (mov[ini+j]!=s[j]);
                }
                if(dif < min) { 
                    min = dif;
                    index = j+1;
                }
            }
        }

        cout<<index<<endl;
    }
	//__time__			//Uncomment for show runtime
}
