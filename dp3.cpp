#include <bits/stdc++.h>
using namespace std;

int main() {

    int totalPhilosopher, hungryCount;
    cout << "Enter Total Number of Philosopher: ";
    cin >> totalPhilosopher;

    vector<int> status(totalPhilosopher, 1); //1: Thinking, 2: Hungry, 3: Waiting

    cout << "How Many Philosopher are Hungry: ";
    cin >> hungryCount;

    if (totalPhilosopher == hungryCount) {
        cout << "Deadlock occurs" << endl;
        return 0;
    }

    for (int i = 0; i < hungryCount; i++) {
        int p;
        do {
            cout << "Enter hungry philosopher's position(1 to " << totalPhilosopher << "): ";
            cin >> p;
        } while (p < 1 || p > totalPhilosopher);
        status[p - 1] = 2;
    }

    for (int i = 0; i < totalPhilosopher; i++) {
        cout << "Philosopher " << i + 1;
        if (status[i] == 2) cout << " Hungry\n";
        else if (status[i] == 1) cout << " Thinking\n";
        else cout << " waiting\n";
    }

    int eating = 0;
    for (int i = 0; i < totalPhilosopher; i++) {
        if (status[i] == 2 && eating < 2) {
            cout << "philosopher " << i + 1 << " is eating\n";
            eating++;
        } else if (status[i] == 2) {
            cout << "philosopher " << i + 1 << " is waiting\n";
        }
    }

    return 0;
}