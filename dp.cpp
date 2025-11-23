#include <iostream>
using namespace std;

int main() {
    int totalPhilosopher, hungryCount;
    int status[20];
    // 1 = Thinking, 2 = Hungry, 3 = Waiting

    cout << "\n\n\t\tDINING PHILOSOPHER PROBLEM (Simple Simulation)\n";

    // Input total philosophers
    cout << "\nEnter total number of Philosophers: ";
    cin >> totalPhilosopher;

    // Initialize all as thinking
    for (int i = 0; i < totalPhilosopher; i++) {
        status[i] = 1; 
    }

    // Input hungry philosophers
    cout << "\nHow many Philosophers are Hungry: ";
    cin >> hungryCount;

    // Deadlock check
    if (hungryCount == totalPhilosopher) {
        cout << "\nAll philosophers are hungry -> DEADLOCK OCCURS!\n";
        return 0;
    }

    // Input hungry positions
    for (int i = 0; i < hungryCount; i++) {
        int pos;

        do {
            cout << "\nEnter Hungry Philosopher Number (1 to " << totalPhilosopher << "): ";
            cin >> pos;

            if (pos < 1 || pos > totalPhilosopher)
                cout << "Invalid! Please try again.\n";

        } while (pos < 1 || pos > totalPhilosopher);

        status[pos - 1] = 2; // mark as hungry
    }

    // Display philosopher statuses
    cout << "\n\nPhilosopher\tStatus\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < totalPhilosopher; i++) {
        cout << (i + 1) << "\t\t";

        if (status[i] == 1) cout << "Thinking\n";
        else if (status[i] == 2) cout << "Hungry\n";
        else cout << "Waiting\n";
    }

    // Safe sequence: allow max 2 to eat
    cout << "\n\nSafe Sequence (Max 2 Eating at a Time):\n";

    int eatingNow = 0;

    for (int i = 0; i < totalPhilosopher; i++) {
        if (status[i] == 2 && eatingNow < 2) {
            cout << "Philosopher " << (i + 1) << " is EATING\n";
            eatingNow++;
        } 
        else if (status[i] == 2) {
            status[i] = 3; // mark as waiting
            cout << "Philosopher " << (i + 1) << " is WAITING\n";
        }
    }

    cout << "\nExecution Completed.\n\n";

    return 0;
}