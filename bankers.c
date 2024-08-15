#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, r;
    int execution = 0, completion = 0, k = 0, flag = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    
    int visited[n], a[n];
    int allocation[n][r], maximum[n][r], need[n][r], available[r];
    
    printf("Enter the available resources: ");
    for (int i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }
    
    printf("Enter the maximum: ");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < r; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }
    
    printf("Enter the allocation: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    
    printf("\n|Allocation\t|Maximum\t|Need\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            printf("|%d ", allocation[i][j]);
        }
        printf("\t");
        for (int j = 0; j < r; j++) {
            printf("|%d ", maximum[i][j]);
        }
        printf("\t");
        for (int j = 0; j < r; j++) {
            printf("|%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    while (completion < n) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            execution = 0;
            if (visited[i] == 0) {
                for (int j = 0; j < r; j++) {
                    if (need[i][j] <= available[j]) {
                        execution++;
                    }
                }
                if (execution == r) {
                    for (int j = 0; j < r; j++) {
                        available[j] += allocation[i][j];
                    }
                    visited[i] = 1;
                    a[k++] = i;
                    completion++;
                    flag = 1;
                }
            }
        }
        if (flag == 0) {
            printf("No safe sequence.\n");
            exit(0);
        }
    }
    
    printf("The safe sequence is:\n< ");
    for (int i = 0; i < k; i++) {
        printf("P%d ", a[i]);
    }
    printf(">\n");
    
    return 0;
}
