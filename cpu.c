#include <stdio.h>

void fcfs(int n);
void sjf(int n);
void priority(int n);
void roundRobin(int n);

int main() {
    int choice, n,k = 1;

    while (k == 1) {
        printf("CPU Scheduling Algorithms\n");
        printf("1. First Come First Served (FCFS)\n");
        printf("2. Shortest Job First (SJF)\n");
        printf("3. Priority Scheduling\n");
        printf("4. Round Robin\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program.\n");
            break;
        }

        printf("Enter the number of processes: ");
        scanf("%d", &n);

        switch (choice) {
            case 1:
                fcfs(n);
                break;
            case 2:
                sjf(n);
                break;
            case 3:
                priority(n);
                break;
            case 4:
                roundRobin(n);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void fcfs(int n) {
    int process[n], burst[n], wt[n], tat[n], total_tat = 0, total_wt = 0;
    printf("Enter the burst time and process id:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &process[i], &burst[i]);
    }
    wt[0] = 0;
    tat[0] = burst[0];
    total_tat = tat[0];
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + burst[i-1];
        total_wt += wt[i];
        tat[i] = tat[i-1] + burst[i];
        total_tat += tat[i];
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average Waiting time: %.2f\nTotal Waiting time: %d\nAverage Turnaround time: %.2f\nTotal Turnaround time: %d\n",
           avg_wt, total_wt, avg_tat, total_tat);
}

void sjf(int n) {
    int process[n], burst[n], wt[n], tat[n], total_tat = 0, total_wt = 0;
    printf("Enter the burst time and process id:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &process[i], &burst[i]);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (burst[i] > burst[j]) {
                int temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = burst[0];
    total_tat = tat[0];
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + burst[i-1];
        total_wt += wt[i];
        tat[i] = tat[i-1] + burst[i];
        total_tat += tat[i];
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average Waiting time: %.2f\nTotal Waiting time: %d\nAverage Turnaround time: %.2f\nTotal Turnaround time: %d\n",
           avg_wt, total_wt, avg_tat, total_tat);
}

void priority(int n) {
    int process[n], bt[n], wt[n], tat[n], priority[n], i, j, temp;
    int total_wt = 0, total_tat = 0;
    printf("Enter processes, burst time, and priority:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &process[i], &bt[i], &priority[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
                
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];
    total_wt = wt[0];
    total_tat = tat[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    
    printf("\nProcess\t|Burst time\t|Priority\t|Waiting time\t|Turn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t|%d\t\t|%d\t\t|%d\t\t|%d\n", process[i], bt[i], priority[i], wt[i], tat[i]);
    }
    printf("\nTotal Waiting time: %d\n", total_wt);
    printf("Total Turn around time: %d\n", total_tat);
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average Waiting time: %.2f\n", avg_wt);
    printf("Average turn around time: %.2f\n", avg_tat);
}

void roundRobin(int n) {
    int quantum = 5;
    int process[n], burst[n], rburst[n], wt[n], tat[n];
    int flag = 0, total = 0, total_wt = 0, total_tat = 0;

    printf("Enter processes and burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &process[i], &burst[i]);
        rburst[i] = burst[i];
    }

    while (flag != n) {
        for (int i = 0; i < n; i++) {
            if (rburst[i] > quantum) {
                total += quantum;
                rburst[i] -= quantum;
            } else if (rburst[i] > 0) {
                total += rburst[i];
                rburst[i] = 0;
                flag++;
                tat[i] = total;
                wt[i] = total - burst[i];
            }
        }
    }

    printf("\nProcess\t|Burst time\t|Waiting time\t|Turn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t|%d\t\t|%d\t\t|%d\n", process[i], burst[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nTotal Waiting time: %d\n", total_wt);
    printf("Total Turn around time: %d\n", total_tat);
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average Waiting time: %.2f\n", avg_wt);
    printf("Average turn around time: %.2f\n", avg_tat);
}
