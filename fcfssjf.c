#include <stdio.h>

int fcfs(int n);
int sjf(int n);
int priority(int n);
void main(){
	int option, k = 1, n;
	while (k == 1){
		printf("CPU Scheduling Algorithms.\n1. FCFS\n2. SJF\nEnter an option: ");
		scanf("%d",&option);
		printf("Enter the number of processes: ");
		scanf("%d",&n);
		switch(option){
			case 1:
				fcfs(n);
				break;
			case 2:
				sjf(n);
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
}

int fcfs(int n){
	int process[n], bt[n], wt[n], tat[n], total_tat = 0, total_wt = 0;
	printf("Enter the process id and burst time: ");
	for (int i = 0; i < n; i++){
		scanf("%d%d",&process[i],&bt[i]);
	}
	wt[0] = 0;
	tat[0] = bt[0];
	total_tat = tat[0];
	printf("|Process\t|Burst time\t|Waiting time\t|Turn around time\n");
	for (int i = 1; i < n; i++){
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("|P%d\t\t|%d\t\t|%d\t\t|%d\n",process[i],bt[i],wt[i],tat[i]);
	}
	printf("|Gant Chart\n");
	for (int i = 0; i < n; i++){
		printf("|P%d\t",process[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++){
		if (i == n-1){
			printf("|%d-%d",wt[i],tat[n-1]);
		}
		else {
			printf("|%d-%d\t",wt[i],wt[i+1]);
		}
	}
	printf("\n");
	float avg_tat = (float)total_tat/n;
	float avg_wt = (float)total_wt/n;
	printf("Total Waiting time: %d\nTotal turnaround time: %d\nAverage Waiting time: %.2f\nAverage turnaround time: %.2f\n",total_wt,total_tat,avg_tat, avg_wt);
	return 0;
}

int sjf(int n){
	int process[n], bt[n], wt[n], tat[n], total_tat = 0, total_wt = 0;
	printf("Enter the process id and burst time: ");
	for (int i = 0; i < n; i++){
		scanf("%d%d",&process[i],&bt[i]);
	}
	wt[0] = 0;
	tat[0] = bt[0];
	total_tat = tat[0];
	
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if (bt[i] > bt[j]){
				int temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
				
				temp = process[i];
				process[i] = process[j];
				process[j] = temp;
			}
		}
	}
	printf("|Process\t|Burst time\t|Waiting time\t|Turn around time\n");
	for (int i = 1; i < n; i++){
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		total_tat = total_tat + tat[i];
		total_wt = total_wt + wt[i];
		printf("|P%d\t\t|%d\t\t|%d\t\t|%d\n",process[i],bt[i],wt[i],tat[i]);
	}
	printf("|Gant Chart\n");
	for (int i = 0; i < n; i++){
		printf("|P%d\t",process[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++){
		if (i == n-1){
			printf("|%d-%d",wt[i],tat[n-1]);
		}
		else {
			printf("|%d-%d\t",wt[i],wt[i+1]);
		}
	}
	printf("\n");
	float avg_tat = (float)total_tat/n;
	float avg_wt = (float)total_wt/n;
	printf("Total Waiting time: %d\nTotal turnaround time: %d\nAverage Waiting time: %.2f\nAverage turnaround time: %.2f\n",total_wt,total_tat,avg_tat, avg_wt);
	return 0;
}

