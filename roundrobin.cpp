#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, quantum;
    cout << "Enter number of processes and time quantum: ";
    cin >> n >> quantum;

    vector<int> burst(n), remBurst(n), wait(n), tat(n);
    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) cin >> burst[i], remBurst[i] = burst[i];

    int t = 0;
    bool done;
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remBurst[i] > 0) {
                done = false;
                if (remBurst[i] > quantum) {
                    t += quantum;
                    remBurst[i] -= quantum;
                } else {
                    t += remBurst[i];
                    wait[i] = t - burst[i];
                    remBurst[i] = 0;
                }
            }
        }
    } while (!done);

    cout << "Process\tBurst\tWait\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        tat[i] = burst[i] + wait[i];
        cout << i + 1 << "\t" << burst[i] << "\t" << wait[i] << "\t" << tat[i] << endl;
    }
    return 0;
}
