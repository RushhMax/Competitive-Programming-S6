#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; 
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        int x; 
        cin >> x;

        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();

        if (pos == n) {
            cout << n << '\n';
        } else if (a[pos] == x) {
            cout << pos + 1 << '\n';
        } else {
            cout << pos << '\n';
        }
    }

    return 0;
}
