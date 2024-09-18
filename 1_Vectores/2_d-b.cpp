#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    while (cin >> n && n) {
        int pos = -1;
        vector<string> carts(n);
        string num, word;
        for (int i = 0; i < n; i++) {
            cin >> num >> word;
            int len = word.length();
            for (int j = 0; j < len; ++j) {
                pos = (pos + 1) % n;
                while (!carts[pos].empty()) {
                    pos = (pos + 1) % n;
                }
            }
            carts[pos] = num;
        }
        for (int k = 0; k < n; k++) {
            cout << carts[k] << (k + 1 < n ? " " : "\n");
        }
    }
    return 0;
}
