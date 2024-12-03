
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Proceso {
    char id;
    int tiempoLlegada, TiempoServicio, completionTime, turnaroundTime, waitingTime;
};

bool compareArrival(const Proceso &a, const Proceso &b) {
    return a.tiempoLlegada < b.tiempoLlegada;
}

void sjf(vector<Proceso> &procesos) {
    sort(procesos.begin(), procesos.end(), compareArrival);

    int time = 0, completed = 0;
    while (completed < procesos.size()) {
        int shortest = -1;
        for (size_t i = 0; i < procesos.size(); ++i) {
            if (procesos[i].tiempoLlegada <= time && procesos[i].completionTime == 0) {
                if (shortest == -1 || procesos[i].TiempoServicio < procesos[shortest].TiempoServicio) {
                    shortest = i;
                }
            }
        }

        if (shortest != -1) {
            time += procesos[shortest].TiempoServicio;
            procesos[shortest].completionTime = time;
            procesos[shortest].turnaroundTime = procesos[shortest].completionTime - procesos[shortest].tiempoLlegada;
            procesos[shortest].waitingTime = procesos[shortest].turnaroundTime - procesos[shortest].TiempoServicio;
            ++completed;
        } else {
            ++time; 
        }
    }

    cout << "\nShortest Job First Scheduling\n";
    cout << "Proceso\tArrival\tService\tCompletion\tTurnaround\tWaiting\n";
    for (const auto &p : procesos) {
        cout << p.id << "\t" << p.tiempoLlegada << "\t" << p.TiempoServicio << "\t"
             << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t" << p.waitingTime << "\n";
    }
}
