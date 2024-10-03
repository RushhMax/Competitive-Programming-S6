#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

void solve()
{
    string line;

    map<int, vector<pair<char, int>>> process;
    map<int, int> denieds;

    while (getline(cin, line) && line != "#")
    {
        stringstream datos(line);
        char T;
        getline(datos, line, ' ');
        T = line[0];
        getline(datos, line, ' ');
        int NT = stoi(line);
        getline(datos, line, ' ');
        int NDT = stoi(line);

        bool haveX = false;
        if (denieds.find(NT) == denieds.end())
        {
            for (int i = 0; i < process[NDT].size(); i++)
            {
                if (process[NDT][i].first == 'X')
                {
                    haveX = true;
                }
                if (process[NDT][i].second == NT)
                {
                    process[NDT].push_back({T, NT});
                    cout << "GRANTED\n";
                    break;
                }
            }
            if (haveX || T == 'X')
            {
                cout << "DENIED\n";
            }
        }
        else
        {
            cout << "IGNORED\n";
        }

    }
}


int main()
{
    int tc;
    cin >> tc;
    cin.ignore(); // Para ignorar el salto de linea al leer tc

    while (tc--)
    {
        solve();
    }

    // std::unordered_map<std::string, int> hashTable;

    // // Insertar elementos
    // hashTable["apple"] = 1;
    // hashTable["banana"] = 2;
    // hashTable["orange"] = 3;

    // // Buscar elementos
    // std::string key = "banana";
    // if (hashTable.find(key) != hashTable.end()) {
    //     std::cout << key << " encontrado: " << hashTable[key] << std::endl;
    // } else {
    //     std::cout << key << " no encontrado" << std::endl;
    // }

    // // Eliminar un elemento
    // hashTable.erase("banana");

    // // Mostrar el contenido de la tabla hash
    // for (const auto &pair : hashTable) {
    //     std::cout << pair.first << ": " << pair.second << std::endl;
    // }

    // return 0;
}

// S 1 1           f
// S 2 2            g
// X 10 1         D
// S 6 123456789    G
// S 3 3              G
// X 2 2               G
// S 5 6                G
// S 3 1                G
// S 3 2                    D
// X 987654321 123456789    D
// X 1 4                    G
// S 6 6                    G
// S 3 5                    I
// S 2 4                    D
// X 4 5                    G
// S 2 51                   I
