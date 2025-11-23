#include <iostream>
#include <vector>
#include <cmath>   // for abs()

using namespace std;

int main() {
    int totalRequests;
    int headPosition;

    // Input: Number of requests
    cout << "Enter total number of disk requests: ";
    cin >> totalRequests;

    vector<int> requestQueue(totalRequests);

    // Input: Request sequence
    cout << "Enter the disk request sequence:\n";
    for (int i = 0; i < totalRequests; i++) {
        cin >> requestQueue[i];
    }

    // Input: Current head position
    cout << "Enter the current head position: ";
    cin >> headPosition;

    cout << "\nHead Movement Order:\n";
    cout << headPosition;

    int totalMovement = 0;
    int currentPosition = headPosition;

    // FCFS servicing
    for (int req : requestQueue) {
        cout << " ---> " << req;

        totalMovement += abs(req - currentPosition);  // distance moved
        currentPosition = req;                        // update head
    }

    cout << "\n\nTotal Head Movement = " << totalMovement << " cylinders\n";
    cout << "FCFS Scheduling Completed.\n";

    return 0;
}