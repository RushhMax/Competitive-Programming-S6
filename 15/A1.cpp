
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Edge {
    int u, v;
    double weight;
};

// Union-Find con compresión de ruta y unión por rango
vector<int> parent, rankArray;

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rankArray[u] < rankArray[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (rankArray[u] == rankArray[v]) {
            rankArray[u]++;
        }
    }
}

// Función para calcular la distancia euclidiana
double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int n, r;
        cin >> n >> r;

        vector<pair<int, int>> cities(n);
        for (int i = 0; i < n; ++i) {
            cin >> cities[i].first >> cities[i].second;
        }

        parent.resize(n);
        rankArray.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        vector<Edge> roads, railroads;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = euclideanDistance(cities[i].first, cities[i].second,
                                                cities[j].first, cities[j].second);
                if (dist <= r) {
                    roads.push_back({i, j, dist});
                } else {
                    railroads.push_back({i, j, dist});
                }
            }
        }

        // Ordenar aristas por peso
        sort(roads.begin(), roads.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });
        sort(railroads.begin(), railroads.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        int numStates = n;
        double roadLength = 0, railroadLength = 0;

        // Calcular MST para caminos
        for (const auto& edge : roads) {
            if (find(edge.u) != find(edge.v)) {
                unionSets(edge.u, edge.v);
                roadLength += edge.weight;
                numStates--;
            }
        }

        // Calcular MST para ferrocarriles
        for (const auto& edge : railroads) {
            if (find(edge.u) != find(edge.v)) {
                unionSets(edge.u, edge.v);
                railroadLength += edge.weight;
                numStates--;
            }
        }

        cout << "Case #" << caseNum << ": " << numStates << " "
             << round(roadLength) << " " << round(railroadLength) << endl;
    }

    return 0;
}
