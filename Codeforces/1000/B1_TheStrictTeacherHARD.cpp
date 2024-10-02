//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
    
    vll teacher;
    for(int i=0; i<m;i++){
        int x;
        cin>>x;
        teacher.push_back(x);
    }

    //sort(teacher.begin(), teacher.end());
    
    for(int i=0; i<q;i++){
        ll int query;
        cin>>query;
        ll int a = 0, b = n, min = MAX_N;
        
        int start = 0, end = m;
        int mid;
        bool dir = false;
        while(start < end){
            mid = (start+end)/2;
            if(query < teacher[mid]){
                b = teacher[mid];
                if(!dir){
                    break;
                }
                end = mid;
            }else if(teacher[mid] < query){
                a = teacher[mid];
                if(dir){
                    break;
                }
                start = mid+1;
            }
        }
        
        if(mid > 0 && a == 0) a = teacher[mid-1]; 
        if(mid > m && b == n) b = teacher[mid-1];
        if(mid )
        //cout<<"a: "<<a<<", b: "<<b<<endl;

        if(a == 0){ a = b; }
        if(b == n){ b = a; }

        if(a == b){ 
            if(query<a){
                cout<<a-1<<endl;
            }else{
                cout<<n-a<<endl;
            }
        }else if(query<a && query<b){
            if(a<b){
                cout<<a-1<<endl;
            }else{
                cout<<b-1<<endl;
            }
        }else if(query>a && query>b){
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
