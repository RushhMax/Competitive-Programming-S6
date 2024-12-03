#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    char id;                // Identificador del proceso
    int arrivalTime;        // Tiempo de llegada
    int serviceTime;        // Tiempo de servicio
    int remainingTime;      // Tiempo restante (para Round Robin)
    int completionTime;     // Tiempo de finalización
    int turnaroundTime;     // Tiempo de retorno (turnaround)
    int waitingTime;        // Tiempo de espera
};

// Comparador para ordenar por tiempo de llegada (para SJF)
bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

// Algoritmo Round Robin
void roundRobin(vector<Process> &processes, int quantum) {
    int time = 0;
    queue<int> readyQueue;
    vector<bool> inQueue(processes.size(), false);

    int completed = 0;
    while (completed < processes.size()) {
        // Añadir procesos listos a la cola
        for (size_t i = 0; i < processes.size(); ++i) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0 && !inQueue[i]) {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }

        if (!readyQueue.empty()) {
            int current = readyQueue.front();
            readyQueue.pop();
            inQueue[current] = false;

            int executionTime = min(quantum, processes[current].remainingTime);
            time += executionTime;
            processes[current].remainingTime -= executionTime;

            if (processes[current].remainingTime == 0) {
                processes[current].completionTime = time;
                processes[current].turnaroundTime = processes[current].completionTime - processes[current].arrivalTime;
                processes[current].waitingTime = processes[current].turnaroundTime - processes[current].serviceTime;
                ++completed;
            }

            // Reagregar procesos listos
            for (size_t i = 0; i < processes.size(); ++i) {
                if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0 && !inQueue[i]) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                }
            }

            // Reagregar el proceso actual si no está terminado
            if (processes[current].remainingTime > 0) {
                readyQueue.push(current);
                inQueue[current] = true;
            }
        } else {
            ++time; // Incrementar el tiempo si no hay procesos listos
        }
    }

    cout << "\nRound Robin Scheduling (Quantum: " << quantum << ")\n";
    cout << "Process\tArrival\tService\tCompletion\tTurnaround\tWaiting\n";
    for (const auto &p : processes) {
        cout << p.id << "\t" << p.arrivalTime << "\t" << p.serviceTime << "\t"
             << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t" << p.waitingTime << "\n";
    }
}

// Algoritmo Shortest Job First (SJF)
void sjf(vector<Process> &processes) {
    sort(processes.begin(), processes.end(), compareArrival);

    int time = 0, completed = 0;
    while (completed < processes.size()) {
        int shortest = -1;
        for (size_t i = 0; i < processes.size(); ++i) {
            if (processes[i].arrivalTime <= time && processes[i].completionTime == 0) {
                if (shortest == -1 || processes[i].serviceTime < processes[shortest].serviceTime) {
                    shortest = i;
                }
            }
        }

        if (shortest != -1) {
            time += processes[shortest].serviceTime;
            processes[shortest].completionTime = time;
            processes[shortest].turnaroundTime = processes[shortest].completionTime - processes[shortest].arrivalTime;
            processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].serviceTime;
            ++completed;
        } else {
            ++time; // Incrementar tiempo si no hay procesos listos
        }
    }

    cout << "\nShortest Job First Scheduling\n";
    cout << "Process\tArrival\tService\tCompletion\tTurnaround\tWaiting\n";
    for (const auto &p : processes) {
        cout << p.id << "\t" << p.arrivalTime << "\t" << p.serviceTime << "\t"
             << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t" << p.waitingTime << "\n";
    }
}

int main() {
    // Datos para Round Robin
    vector<Process> rrProcesses1 = {
        {'A', 0, 8, 8}, {'B', 1, 4, 4}, {'C', 2, 9, 9}, {'D', 3, 5, 5}
    };
    vector<Process> rrProcesses2 = {
        {'A', 0, 5, 5}, {'B', 1, 3, 3}, {'C', 2, 1, 1}, {'D', 3, 2, 2}, {'E', 4, 3, 3}
    };

    // Datos para SJF
    vector<Process> sjfProcesses = {
        {'A', 0, 5}, {'B', 1, 3}, {'C', 2, 1}, {'D', 3, 2}, {'E', 4, 3}
    };

    // Ejecución de algoritmos
    cout << "Round Robin (Primer Conjunto):";
    roundRobin(rrProcesses1, 3);

    cout << "\nRound Robin (Segundo Conjunto):";
    roundRobin(rrProcesses2, 2);

    cout << "\nShortest Job First:";
    sjf(sjfProcesses);

    return 0;
}
