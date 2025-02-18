

using namespace std;
using i64 = long long;
const int N = 1'000'000;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), mp(N + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  vector<int> ans(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = i; j <= N; j += i) {
      cnt += mp[j];
    }
    if (cnt >= k) {
      for (int j = i; j <= N; j += i) {
        ans[j] = i;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[a[i]] << "\n";
  }

  return 0;
}
