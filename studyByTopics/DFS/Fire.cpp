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


int dx[] = {-1,  0, 0, 1};
int dy[] = { 0, -1, 1, 0};

int main(){
	//__FasterIO__
	//__log__	
    //int tc;
    //cin>>tc;
    //while(tc--){
    int R,C; cin >> R >> C;
    vector<vector<char>> maze(R, vector<char>(C));
    
    int JX, JY;  
    vpii fire;
    f(i,R) f(j,C){
        cin >> maze[i][j];
        if(maze[i][j] == 'J') JX = i, JY = j;
        if(maze[i][j] == 'F') fire.push_back({i,j});
    }

    auto ok = [&](int x, int y){
        return x>=0 && x<R && y>=0 && y<C && maze[x][y] == '.';
    };

    auto print = [&](){
        cout<<"PRINT"<<endl;
        f(i,R){
            f(j,C){
                cout << maze[i][j];
            }
            cout << endl;
        }
    };

    auto safe = [&](int x, int y){
        return x==0 || x==R-1 || y==0 || y==C-1;
    };

    auto expandFire = [&](){
        vpii newFire;
        f(i,sz(fire)){
            auto [x,y] = fire[i];
            f(k,4){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(ok(nx,ny)){
                    maze[nx][ny] = 'F';
                    newFire.push({nx,ny});
                }
            }
        }
        fire = newFire;
    };

    int ans = -1;
    map<pii,int> vis;
    function<void(int, int, int)> dfs = [&](int x, int y, int deep){
        vis[{x,y}] = 1;
        //print();
        if(safe(x,y)){
            //cout << "SAFE" << x << " " << y << endl;
            //_(deep);
            //_(ans);
            ans = (ans == -1 ? deep : min(ans,deep));
            vis[{x,y}] = 0;
            return;
        }
        expandFire();
        f(k,4){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(ok(nx,ny) && !vis[{nx,ny}]){
                //cout << "DFS at (" << x << ", " << y << ") with depth " << deep << endl;
                dfs(nx,ny,deep+1);
            }
        }
        vis[{x,y}] = 0;
    };


    dfs(JX,JY,1);

    if(ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
	//__time__			//Uncomment for show runtime
    //}
}
