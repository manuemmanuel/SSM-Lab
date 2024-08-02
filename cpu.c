#include <stdio.h>

int fcfs(int n);
int sjf(int n);
int priority(int n);
int roundrobin(int n);
void main(){
	int option, k = 1, n;
	while (k == 1){
		printf("CPU Scheduling Algorithms.\n1. FCFS\n2. SJF\n3. Priority\n4. Roundrobin\nEnter an option: ");
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
			case 3:
				priority(n);
				break;
			case 4:
				roundrobin(n);
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
	printf("|P%d\t\t|%d\t\t|%d\t\t|%d\n",process[0],bt[0],wt[0],tat[0]);
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
	printf("Total Waiting time: %d\nTotal turnaround time: %d\nAverage Waiting time: %.2f\nAverage turnaround time: %.2f\n",total_wt,total_tat,avg_wt, avg_tat);
	return 0;
}

int sjf(int n){
	int process[n], bt[n], wt[n], tat[n], total_tat = 0, total_wt = 0;
	printf("Enter the process id and burst time: ");
	for (int i = 0; i < n; i++){
		scanf("%d%d",&process[i],&bt[i]);
	}
	
	for (int i = 0; i < n -1 ; i++){
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
	
	wt[0] = 0;
	tat[0] = bt[0];
	total_tat = tat[0];
	
	printf("|Process\t|Burst time\t|Waiting time\t|Turn around time\n");
	printf("|P%d\t\t|%d\t\t|%d\t\t|%d\n",process[0],bt[0],wt[0],tat[0]);
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

int priority(int n){
	int process[n],bt[n],tat[n],total_tat = 0,total_wt = 0,wt[n],priority[n];
	printf("Enter the process id, burst time and priority: ");
	for(int i = 0; i < n;i++){
		scanf("%d%d%d",&process[i],&bt[i],&priority[i]);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n -1; j++){
			if (priority[j] > priority[j+1]){
				int temp = priority[j];
				priority[j] = priority[j+1];
				priority[j+1] = temp;
				
				temp = process[j];
				process[j] = process[j+1];
				process[j+1] = temp;
				
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
			}
		}
	}
	wt[0] = 0;
	tat[0] = bt[0];
	total_wt = wt[0];
	total_tat = tat[0];
	printf("|Process\t|Burst time\tPriority\t|Waiting time\t|Turn around time\n");
	printf("|P%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n",process[0],bt[0],priority[0],wt[0],tat[0]);
	for (int i = 1; i < n; i++){
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		total_tat = total_tat + tat[i];
		total_wt = total_wt + wt[i];
		printf("|P%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n",process[i],bt[i],priority[i],wt[i],tat[i]);
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
	float avg_wait = (float)total_wt/n;
	float avg_tat = (float)total_tat/n;
	printf("Total Waiting time: %d\n",total_wt);
	printf("Total turn around time: %d\n",total_tat);
	printf("Average waiting time: %.2f\n",avg_wait);
	printf("Average turn around time: %.2f\n",avg_tat);
	return 0;
}

int roundrobin(int n){
	int quantum,time[20];
	int x = 1;
	time[0] = 0;
	printf("Enter the time quantum: ");
	scanf("%d",&quantum);
	int process[n], burst[n], tat[n], wt[n], rburst[n];
	int total_tat = 0, total_wt = 0, total = 0, flag = 0;
	printf("Enter the process id and burst time: ");
	for (int i = 0; i < n; i++){
		scanf("%d%d",&process[i],&burst[i]);
		rburst[i] = burst[i];
	}
	printf("|Gant Chart\n");
	while (flag != n){
		for (int i = 0; i < n; i++){
			if (rburst[i] > quantum){
				total = total + quantum;
				rburst[i] = rburst[i] - quantum;
				printf("|P%d\t",process[i]);
				time[x] = total;
				x++;
			}
			else if (rburst[i] > 0){
				total = total + rburst[i];
				rburst[i] = 0;
				flag++;
				tat[i] = total;
				wt[i] = total - burst[i];
				printf("|P%d\t",process[i]);
				time[x] = total;
				x++;
			}
		}
	}
	printf("\n");
	
	for (int i = 0; i < x-1; i++){
		printf("|%d-%d\t",time[i],time[i+1]);
	}
	printf("\n");
	printf("|Process\t|Burst time\tRemaining time\t|Waiting time\t|Turn around time\n");
	for (int i = 0; i < n; i++){
		printf("|P%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n",process[i],burst[i],rburst[i],wt[i],tat[i]);
		total_tat = total_tat + tat[i];
		total_wt = total_wt + wt[i];
	}
	float avg_wait = (float)total_wt/n;
	float avg_tat = (float)total_tat/n;
	printf("Total Waiting time: %d\n",total_wt);
	printf("Total turn around time: %d\n",total_tat);
	printf("Average waiting time: %.2f\n",avg_wait);
	printf("Average turn around time: %.2f\n",avg_tat);
	return 0;
	
}

