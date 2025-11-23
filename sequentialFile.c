#include<stdio.h>

int main() {
    int f[50], i, j, st, len, c;

    for(i = 0; i < 50; i++)
        f[i] = 0;

    while(1) {

        printf("Enter the Starting Block: ");
        scanf("%d", &st);

        printf("Enter the Length of File: ");
        scanf("%d", &len);

        // Check free blocks
        c = 1;
        for(j = st; j < (st + len); j++) {
            if(f[j] == 1) {
                c = 0;
                break;
            }
        }

        if(c == 1) {
            for(j = st; j < (st + len); j++)
                f[j] = 1;

            printf("\nFile Allocated Successfully!");
            printf("\nBlocks Allocated: ");

            for(j = st; j < (st + len); j++)
                printf("%d ", j);
        }
        else {
            printf("\nFile NOT allocated. Some blocks already in use.\n");
        }

        printf("\n\nDo you want to enter another file? (1.Yes / 0.No): ");
        scanf("%d", &c);

        if(c == 0)
            break;
    }

    return 0;
}
