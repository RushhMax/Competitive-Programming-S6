int main() {
    vector<Proceso> Procesos1 = {
        {'A', 0, 8, 8}, {'B', 1, 4, 4}, {'C', 2, 9, 9}, {'D', 3, 5, 5}
    };
    vector<Proceso> Procesos2 = {
        {'A', 0, 5, 5}, {'B', 1, 3, 3}, {'C', 2, 1, 1}, {'D', 3, 2, 2}, {'E', 4, 3, 3}
    };
    vector<Proceso> ProcesosS = {
        {'A', 0, 5}, {'B', 1, 3}, {'C', 2, 1}, {'D', 3, 2}, {'E', 4, 3}
    };

    cout << "Round Robin (1st Set):";
    roundRobin(Procesos1, 3);

    cout << "\nRound Robin (2nd Set):";
    roundRobin(Procesos2, 2);

    cout << "\nShortest Job First:";
    sjf(ProcesosS);

    return 0;
}
