//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <cmath>

//B1. The Strict Teacher (Easy Version)
//https://codeforces.com/problemset/problem/1436/B1

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VAi_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define pii pair<int, int>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vvi vector<vector<int>>
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve(){
    ll int n, m, q;
    cin>>n>>m>>q;
    ll int a,b;
    cin>>a>>b;
    cin>>q;

    if(q<a && q<b){
        if(a<b){
            cout<<a-1<<endl;
        }else{
            cout<<b-1<<endl;
        }
    }else if(q>a && q>b){
        if(a>b){
            cout<<n-a<<endl;
        }else{
            cout<<n-b<<endl;
        }
    }else{
        if(a>b){
            cout<<(a-b)/2<<endl;
        }else{
            cout<<(b-a)/2<<endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
