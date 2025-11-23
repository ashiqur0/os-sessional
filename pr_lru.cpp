#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>  // For INT_MAX

using namespace std;

int main() {
    int totalPages, frameCount;

    // Input: number of pages
    cout << "Enter the number of pages: ";
    cin >> totalPages;

    vector<int> pages(totalPages);

    // Input: Page reference string
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < totalPages; i++) {
        cin >> pages[i];
    }

    // Input: number of frames
    cout << "Enter the number of frames: ";
    cin >> frameCount;

    vector<int> frames(frameCount, -1);  // initially empty
    vector<int> lastUsed(frameCount, 0); // tracks last used time

    int timeCounter = 0;  
    int pageFaults = 0, pageHits = 0;

    cout << "\nPage\tFrames\t\tStatus\n";

    // Process each page
    for (int i = 0; i < totalPages; i++) {
        int currentPage = pages[i];
        timeCounter++;

        bool hit = false;

        // Check for HIT
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                hit = true;
                pageHits++;
                lastUsed[j] = timeCounter; // update last used time
                break;
            }
        }

        // If MISS (Page Fault)
        if (!hit) {
            int lruIndex = -1;
            int minimumTime = INT_MAX;

            // Find empty frame OR least recently used frame
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {         // empty frame found
                    lruIndex = j;
                    break;
                }
                if (lastUsed[j] < minimumTime) {  // find LRU
                    minimumTime = lastUsed[j];
                    lruIndex = j;
                }
            }

            // Replace page
            frames[lruIndex] = currentPage;
            lastUsed[lruIndex] = timeCounter;
            pageFaults++;
        }

        // Print the current frame status
        cout << currentPage << "\t";
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == -1)
                cout << "_ ";
            else
                cout << frames[j] << " ";
        }

        cout << "\t" << (hit ? "(HIT)" : "(Fault)") << "\n";
    }

    // Final output
    cout << "\nTotal Page Faults = " << pageFaults << "\n";
    cout << "Total Page Hits   = " << pageHits << "\n";

    return 0;
}