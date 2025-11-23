#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int totalPhilosopher, hungryCount;

    // Input total philosophers
    cout << "\nEnter total number of Philosophers: ";
    cin >> totalPhilosopher;

    // status: 1 = Thinking, 2 = Hungry, 3 = Waiting
    vector<int> status(totalPhilosopher, 1);  // all start Thinking

    // Input hungry count
    cout << "\nHow many Philosophers are Hungry: ";
    cin >> hungryCount;

    // Deadlock check
    if (hungryCount == totalPhilosopher) {
        cout << "\nAll philosophers are hungry -> DEADLOCK OCCURS!\n";
        return 0;
    }

    // Mark hungry philosophers
    for (int i = 0; i < hungryCount; i++) {
        int p;
        do {
            cout << "Enter Hungry Philosopher (1 to " << totalPhilosopher << "): ";
            cin >> p;
        } while (p < 1 || p > totalPhilosopher);

        status[p - 1] = 2;
    }

    // Show statuses
    cout << "\n\nPhilosopher\tStatus\n";
    cout << "-----------------------\n";

    for (int i = 0; i < totalPhilosopher; i++) {
        cout << i + 1 << "\t\t";

        if (status[i] == 1) cout << "Thinking\n";
        else if (status[i] == 2) cout << "Hungry\n";
        else cout << "Waiting\n";
    }

    // Safe sequence (only 2 can eat)
    cout << "\nSafe Sequence:\n";
    int eating = 0;
    for (int i = 0; i < totalPhilosopher; i++) {
        if (status[i] == 2 && eating < 2) {
            cout << "Philosopher " << i + 1 << " is EATING\n";
            eating++;
        } else if (status[i] == 2) {
            status[i] = 3;
            cout << "Philosopher " << i + 1 << " is WAITING\n";
        }
    }

    cout << "\nExecution Completed.\n\n";
}