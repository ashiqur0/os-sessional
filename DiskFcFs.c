#include<stdio.h>
int main(){
 
    int n,i,head;
    int request[100];
    printf("Enter the total Number of Disk: ");
    scanf("%d",&n);
    printf("Enter the disk Request sequence: ");
    for(i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    printf("Enter thr Curent Head Position.\n");
    scanf("%d",&head);
    printf("\n Head Movement in Order:\n");
    printf("%d",head);
    for(i=0;i<n;i++){
        printf("-------->%d",request[i]);
    }
 return 0;
}