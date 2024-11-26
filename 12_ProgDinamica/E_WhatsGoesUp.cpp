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

map<pair<int,int>, vector<int>> memo;

vector<int> longestSub(vector<int> v, int ind, int ant){
    if(ind == v.size()){
        return {};
    }

    if(memo.find(mp(ind,ant)) != memo.end()){
        return memo[mp(ind,ant)];
    }

    vector<int> uno = longestSub(v,ind+1,ant);
    vector<int> dos = {};
    if(v[ind] > ant){
        dos = longestSub(v,ind+1,v[ind]);
        dos.insert(dos.begin(),v[ind]);
    }

    vector<int> result = uno.size() >= dos.size() ? uno : dos;
    memo[mp(ind,ant)] = result;
    return result;
}

void solve(){
    vector<vector<int>> posibles;
    vector<int> numbers;

    int x;
    while(cin>>x){
        numbers.pb(x);
    }

    _vec(numbers);

    f(i,numbers.size()){
        vector<int> sequence;
        sequence.push_back(numbers[i]);
        for(int j = i; j < numbers.size(); j++){
            if(numbers[j] > sequence.back()){
                sequence.push_back(numbers[j]);
            }
        }
        _vec(sequence);
        posibles.push_back(sequence);
    }

    int max = INT_MIN;
    int ind = -1;
    f(i,posibles.size()){
        if(posibles[i].size() > max){
            max = posibles[i].size();
            ind = i;
        }
    }

    cout<<max<<"\n-\n";
    f(i,posibles[ind].size()){
        cout<<posibles[ind][i]<<"\n";
    }

    
}

int main(){
	//__FasterIO__		//Uncomment for improve runtime
	//__log__			//Uncomment for redirect output to LOG.txt
	
    solve();
	//__time__			//Uncomment for show runtime
}
