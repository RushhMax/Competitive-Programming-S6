#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Proceso {
    char id;
    int tiempoLlegada, TiempoServicio, remainingTime, completionTime, turnaroundTime, tiempoEspera;
};

void roundRobin(vector<Proceso> &procesos, int quantum) {
    int time = 0;
    queue<int> colalista;
    vector<bool> enCola(procesos.size(), false);

    int completed = 0;
    while (completed < procesos.size()) {
        for (size_t i = 0; i < procesos.size(); ++i) {
            if (procesos[i].tiempoLlegada <= time && procesos[i].remainingTime > 0 && !enCola[i]) {
                colalista.push(i);
                enCola[i] = true;
            }
        }

        if (!colalista.empty()) {
            int current = colalista.front();
            colalista.pop();
            enCola[current] = false;

            int executionTime = min(quantum, procesos[current].remainingTime);
            time += executionTime;
            procesos[current].remainingTime -= executionTime;

            if (procesos[current].remainingTime == 0) {
                procesos[current].completionTime = time;
                procesos[current].turnaroundTime = procesos[current].completionTime - procesos[current].tiempoLlegada;
                procesos[current].tiempoEspera = procesos[current].turnaroundTime - procesos[current].TiempoServicio;
                ++completed;
            }

            for (size_t i = 0; i < procesos.size(); ++i) {
                if (procesos[i].tiempoLlegada <= time && procesos[i].remainingTime > 0 && !enCola[i]) {
                    colalista.push(i);
                    enCola[i] = true;
                }
            }

            if (procesos[current].remainingTime > 0) {
                colalista.push(current);
                enCola[current] = true;
            }
        } else {
            ++time;
        }
    }

    cout << "\nRound Robin Scheduling (Quantum: " << quantum << ")\n";
    cout << "Proceso\tArrival\tService\tCompletion\tTurnaround\tWaiting\n";
    for (const auto &p : procesos) {
        cout << p.id << "\t" << p.tiempoLlegada << "\t" << p.TiempoServicio << "\t"
             << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t" << p.tiempoEspera << "\n";
    }
}

