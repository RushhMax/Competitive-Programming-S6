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


struct Punto {
    int u, v;
    double peso;
};

vector<int> padre, aux;

int find(int u) {
    if (padre[u] != u) {
        padre[u] = find(padre[u]);
    }
    return padre[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (aux[u] < aux[v]) {
            swap(u, v);
        }
        padre[v] = u;
        if (aux[u] == aux[v]) {
            aux[u]++;
        }
    }
}

double distancia(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int n, r;
        cin >> n >> r;

        vector<pair<int, int>> ciudades(n);
        f(i,n) {
            cin >> ciudades[i].ff >> ciudades[i].ss;
        }

        padre.resize(n);
        aux.resize(n, 0);
        f(i,n) {
            padre[i] = i;
        }

        vector<Punto> calles, railcalles;
        f(i,n) {
            for (int j = i + 1; j < n; ++j) {
                double dist = distancia(ciudades[i].ff, ciudades[i].ss, ciudades[j].ff, ciudades[j].ss);
                if (dist <= r) {
                    calles.pb({i, j, dist});
                } else {
                    railcalles.pb({i, j, dist});
                }
            }
        }

        sort(calles.begin(), calles.end(), [](Punto a, Punto b) {
            return a.peso < b.peso;
        });
        sort(railcalles.begin(), railcalles.end(), [](Punto a, Punto b) {
            return a.peso < b.peso;
        });

        double RL = 0, RRL = 0;

        for (const auto& Punto : calles) {
            if (find(Punto.u) != find(Punto.v)) {
                unionSets(Punto.u, Punto.v);
                RL += Punto.peso;
            }
        }

        for (const auto& Punto : railcalles) {
            if (find(Punto.u) != find(Punto.v)) {
                unionSets(Punto.u, Punto.v);
                RRL += Punto.peso;
            }
        }
        
        int cont;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                cont++;
            }
        }

        cout << "Case #" << tc << ": " << cont << " " << round(RL) << " " << round(RRL) << endl;
    }
}
