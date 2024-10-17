
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
//Templates
struct Graph { // Call like: Graph G(n); G.addEdge(u,v);
    int n; vector<unordered_set<int>> adj;
	Graph(int size) : n(size) { adj.resize(size); }
    void addEdge(int u, int v) { adj[u].insert(v); /* adj[v].insert(u); */ }
	void removeEdge(int u, int v) { adj[u].erase(v); /* adj[v].erase(u); */ }
};
template <template<typename...> class Container, typename T> // DFS: dbfs<stack,int>(G,v);
vector<int> dbfs(Graph& G, int v) {							 // BFS: dbfs<queue,int>(G,v);
	vector<int> visited_order; //Order of graph traversal
	vector<int> visited(G.n,INF); // Keep track of visited nodes
    Container<T> arr; arr.push(v); visited[v] = v; // Starts at v

    while (!arr.empty()) {
		if constexpr(is_same<Container<T>, stack<typename Container<T>::value_type>>::value) {
			v = arr.top();					   //	top if std::stack
		} else { v = arr.front(); } arr.pop(); // front if std::queue
		
		visited_order.pb(v); // DO SOMETHING WITH VISITED NODE

        for (int w : G.adj[v]) { // For each unvisited neighbor of v
            if (visited[w] == INF) {
                arr.push(w);
				visited[w] = v;					//Keep track of PARENT
				// visited[w] = visited[v] + 1; //Keep track of DISTANCE
            }
        }
    }

	// _vec(visited_order)	 // Uncomment to print visited order
	return visited;
}
vi backtrack(vi parent, int start, int end) { //Backtrack visited nodes to reconstruct a path
	vi path; path.pb(end);
	while (path.back() != start) { path.pb(parent[path.back()]); }
	reverse(all(path)); return path;
}

/* ############################################################################################## */


void parser(string &dic, map<string, string> &dict){
    dic = dic.substr(1, dic.size()-2);
    stringstream st(dic);
    string aux;
    while(getline(st, aux, ',')){
        size_t pos = aux.find(':');
        string key = aux.substr(0, pos);
        string value = aux.substr(pos+1);
        dict[key] = value;
    }
}

void solve(){
    string old, new_;
    getline(cin, old);
    getline(cin, new_);

    map<string, string> dictOLD;
    map<string, string> dictNEW;

    parser(old, dictOLD);


    set<string> mas, menos, cambio;

    new_ = new_.substr(1, new_.size()-2);
    stringstream st2(new_);
    while(getline(st2, new_, ',')){
        size_t pos = new_.find(':');
        string key = new_.substr(0, pos);
        string value = new_.substr(pos+1);
        dictNEW[key] = value;

        if(dictOLD.find(key) == dictOLD.end()){
            mas.insert(key);
        }else{
            if( dictOLD[key] != value){
                cambio.insert(key);
            }
        }
    }

    // for(const auto & [key, value] : dictNEW){
    //     if(dictOLD.find(key) == dictOLD.end()){
    //         mas.insert(key);
    //     }else if( dictOLD[key] != value){
    //         cambio.insert(key);
    //     }
    // }

    for(const auto & [key, value] : dictOLD){
        if(dictNEW.find(key) == dictNEW.end()){
            menos.insert(key);
        }
    }

    if(mas.size() == 0 && 
            menos.size() == 0 && 
            cambio.size() == 0 ){
        cout << "No changes\n";
    }else{

        if(!mas.empty()){
            cout<<"+";
            for(auto it = mas.begin() ; it!=mas.end(); it++){
                cout<<*it;
                if(next(it) != mas.end()){
                    cout<<",";
                }
            }
            cout<<endl;
        }
        if(!menos.empty()){
            
            cout<<"-";
            for(auto it = menos.begin(); it!=menos.end(); it++){
                cout<<*it;
                if(next(it) != menos.end()){
                    cout<<",";
                }
            }
            cout<<endl;
        }
        if(!cambio.empty()){
            cout<<"*"; 
            for(auto it = cambio.begin(); it!=cambio.end(); it++){
                cout<<*it;
                if(next(it) != cambio.end()){
                    cout<<",";
                }
            }
            cout<<endl;
        }    
    }
}

int main(){
	__FasterIO__		//Uncomment for improve runtime
	//__log__			//Uncomment for redirect output to LOG.txt

	int tc; cin>>tc;
    cin.ignore();
    for(int i=1; i<=tc; i++){
        solve();
        cout<<endl;
    }
    
 //        string line;
	// while(getline(cin,line)){
	// 	cout << line << endl;
	// }

	//__time__			//Uncomment for show runtime
}
