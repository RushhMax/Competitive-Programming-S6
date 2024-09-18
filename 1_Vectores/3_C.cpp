#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<string> number;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        int counter = 0;
        for (int j = 0; j < d; j++) {
            string user;
            cin >> user;
            number.push_back(user);
            counter++;
        }
        
        string remember;
        cin >> remember;
        cout << "Case " << i + 1 << ":" << endl;
        for (int j = 0; j < counter; j++) {
            int diff = 0;
            for (int k = 0; k < number[j].length(); k++) {
                if (number[j][k] != remember[k])
                    diff++;
            }
            if (diff > 1) continue;
            cout << number[j] << endl;
        }
        number.clear();
    }
    return 0;
}
