#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REVERSE_FOR(i, start, end) for(int i = (end) - 1; i >= (start); --i)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

template <typename T>
void read_vector(vector<T>& v, int n) {
    FOR(i, 0, n) cin >> v[i];
}

// Solución al problema
void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n), arr2(n);
    read_vector(arr, n);
    read_vector(arr2, n);
    
}

int main() {
    FAST_IO;
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
