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
//IO Optimization
#define __FasterIO__ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/* ############################################################################################## */

vi getPrimos(int limit){
    vector<bool> esPrimo(limit+1, true);
    //esPrimo[0] = esPrimo[1] = false;

    for(int i = 2; i*i <= limit; i++){
        if(esPrimo[i]){
            for(int j = i*i; j <= limit; j+=i){
                esPrimo[j] = false;
            }
        }
    }

    vi primos;
    F(i,2,limit+1){
        if(esPrimo[i]){
            primos.pb(i);
        }
    }

    return primos;
}

void getFactors(vi &primos, int n){
    if(n==0) {
        cout<<"0\n";
        return;
    }

    cout<<n<<" =";
    bool aux = true;

    if(n<0){
        cout<<" -1";
        n = -n;
        aux = false;
    }

    for(int pri:primos){
        if(pri*pri > n) break;
        while(n%pri == 0){
            if(!aux) cout<<" x";
            cout<<" "<<pri;
            n /= pri;
            aux = false;
        }
    }

    if(n>1){
        if(!aux) cout<<" x";
        cout<<" "<<n;
    }
    cout<<endl;
}

int main(){
	//__FasterIO__		//Uncomment for improve runtime
	//__log__			//Uncomment for redirect output to LOG.txt
	
    const int LIMIT = 46340;
    vi primos = getPrimos(LIMIT);

    int n;
    while(cin>>n && n){
        getFactors(primos, n);
    }

    //__time__			//Uncomment for show runtime
}
