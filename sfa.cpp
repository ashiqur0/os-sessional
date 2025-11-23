#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int TOTAL_BLOCKS = 50;

    // 0 = free, 1 = allocated
    vector<int> diskBlocks(TOTAL_BLOCKS, 0);

    cout << "\n=== Contiguous File Allocation Simulation ===\n";

    while (true) {

        int startBlock, fileLength;

        // Get starting block and length
        cout << "\nEnter Starting Block (0 - 49): ";
        cin >> startBlock;

        cout << "Enter File Length (number of blocks): ";
        cin >> fileLength;

        // Check boundary condition
        if (startBlock < 0 || startBlock + fileLength > TOTAL_BLOCKS) {
            cout << "\nError: File exceeds disk block range!\n";
            continue;
        }

        // Check if all required blocks are free
        bool allFree = true;
        for (int i = startBlock; i < startBlock + fileLength; i++) {
            if (diskBlocks[i] == 1) {
                allFree = false;
                break;
            }
        }

        // If free -> allocate
        if (allFree) {
            for (int i = startBlock; i < startBlock + fileLength; i++) {
                diskBlocks[i] = 1;
            }

            cout << "\nFile Allocated Successfully!";
            cout << "\nBlocks Allocated: ";

            for (int i = startBlock; i < startBlock + fileLength; i++) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            cout << "\nFile NOT allocated. Some blocks are already in use.\n";
        }

        // Ask user if they want to continue
        int choice;
        cout << "\nDo you want to allocate another file? (1 = Yes, 0 = No): ";
        cin >> choice;

        if (choice == 0) break;
    }

    cout << "\nProgram Ended.\n";
    return 0;
}