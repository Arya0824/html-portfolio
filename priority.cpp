#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id, burst, priority, wait = 0, tat = 0;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    cout << "Enter burst time and priority for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cin >> processes[i].burst >> processes[i].priority;
    }

    // Sort processes by priority (higher priority executes first)
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.priority > b.priority;
    });

    // Calculate waiting and turnaround times
    for (int i = 1; i < n; i++) 
        processes[i].wait = processes[i - 1].wait + processes[i - 1].burst;
    
    for (int i = 0; i < n; i++) 
        processes[i].tat = processes[i].wait + processes[i].burst;

    // Output results
    cout << "Process\tBurst\tPriority\tWait\tTurnaround\n";
    for (auto &p : processes)
        cout << p.id << "\t" << p.burst << "\t" << p.priority << "\t\t" 
             << p.wait << "\t" << p.tat << endl;

    return 0;
}
