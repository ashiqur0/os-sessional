#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, i, j;
    int pageFaults = 0, pageHits = 0;
    int frameSize;
    int time[10]; // প্রতিটি ফ্রেমের শেষ ব্যবহারের সময় রাখে
    int recent = 0; // সময় গণনা করে
    int found, lruIndex;

    // মোট পেজ সংখ্যা ইনপুট
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // পেজ রেফারেন্স স্ট্রিং ইনপুট (যেমন 1 2 3 2 4 1)
    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // মোট ফ্রেম সংখ্যা ইনপুট
    printf("Enter the number of frames: ");
    scanf("%d", &frameSize);

    // শুরুতে সব ফ্রেম খালি
    for (i = 0; i < frameSize; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    // আউটপুট হেডার
    printf("\nPage\tFrames\t\tStatus\n");

    // প্রতিটি পেজ রিকোয়েস্ট প্রক্রিয়া করা
    for (i = 0; i < n; i++) {
        found = 0;
        recent++; // সময় আপডেট

        // চেক করা পেজটি আগে থেকেই আছে কিনা
        for (j = 0; j < frameSize; j++) {
            if (frames[j] == pages[i]) {
                found = 1;       // পেজ পাওয়া গেছে → HIT
                pageHits++;
                time[j] = recent; // শেষ ব্যবহারের সময় আপডেট
                break;
            }
        }

        // যদি পেজ না পাওয়া যায় → Fault
        if (found == 0) {
            int minTime = 1e9; // অনেক বড় মান ধরা হলো

            // কোন ফ্রেমে বসানো হবে তা নির্ধারণ
            for (j = 0; j < frameSize; j++) {
                if (frames[j] == -1) { // খালি ফ্রেম পাওয়া গেলে
                    lruIndex = j;
                    break;
                }
                if (time[j] < minTime) { // সবচেয়ে পুরনো ব্যবহৃত পেজ খোঁজা
                    minTime = time[j];
                    lruIndex = j;
                }
            }

            // নতুন পেজ বসানো হলো
            frames[lruIndex] = pages[i];
            time[lruIndex] = recent;
            pageFaults++;
        }

        // বর্তমান অবস্থা প্রিন্ট
        printf("%d\t", pages[i]);
        for (j = 0; j < frameSize; j++) {
            if (frames[j] == -1)
                printf("_ ");
            else
                printf("%d ", frames[j]);
        }

        // ফলাফল HIT না FAULT
        if (found == 1)
            printf("\t(HIT)\n");
        else
            printf("\t(Fault)\n");
    }

    // চূড়ান্ত ফলাফল
    printf("\nTotal Page Faults = %d\n", pageFaults);
    printf("Total Page Hits   = %d\n", pageHits);

    return 0;
}
