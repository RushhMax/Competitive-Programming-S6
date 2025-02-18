
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned int i, j, n, k;
    cin >> n >> k;
    
    unordered_map<unsigned int, unsigned int> divs;
    vector<vector<unsigned int>> nums(n);

    // Leer valores y calcular divisores
    for (i = 0; i < n; i++) {
        unsigned int a;
        cin >> a;
        
        vector<unsigned int> divisores;
        for (j = 1; j * j <= a; j++) {
            if (a % j == 0) {
                divs[j]++;
                divisores.push_back(j);
                if (j != a / j) {
                    divs[a / j]++;
                    divisores.push_back(a / j);
                }
            }
        }
        
        // Ordenar divisores de mayor a menor para búsqueda eficiente
        sort(divisores.rbegin(), divisores.rend());
        nums[i] = move(divisores);
    }

    // Para cada número, obtener el mayor divisor válido
    for (const auto& divisores : nums) {
        for (unsigned int d : divisores) {
            if (divs[d] >= k) {
                cout << d << "\n";
                break;
            }
        }
    }

    return 0;
}
