#include <stdio.h>
#include <stdlib.h>

int fcfs(int n);
int scan(int n);
int cscan(int n);
void main(){
	int k = 1, choice, n;
	while (k == 1){
		printf("Disk Scheduling Algorithms\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.Exit\nEnter an option: ");
		scanf("%d",&choice);
		if (choice == 1 || choice == 2 || choice == 3){
			printf("Enter the number of requests: ");
			scanf("%d",&n);
		}
		switch(choice){
			case 1:
				fcfs(n);
				break;
			case 2:
				scan(n);
				break;
			case 3:
				cscan(n);
				break;
			case 4:
				printf("Exiting.");
				exit(0);
				break;
			default:
				printf("Enter a valid option.\n");
		}
	}
}

int fcfs(int n){
	int head, queue[n], total = 0;
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the requests: ");
	for (int i = 1; i < n+1; i++){
		scanf("%d",&queue[i]);
	}
	queue[0] = head;
	printf("The head movement from %d to %d is: %d.\n",queue[0],queue[1],abs(queue[0] - queue[1]));
	total = total + abs(queue[0] - queue[1]);
	for (int i = 1; i < n; i++){
		printf("The head movement from %d to %d is: %d.\n",queue[i],queue[i+1],abs(queue[i]-queue[i+1]));
		total = total + abs(queue[i]-queue[i+1]);
	}
	printf("The total seek time is: %d.\n",total);
}

int scan(int n){
	int queue[n], head, maxrange;
	int queue1[n], queue2[n], queue3[n], x = 0, y = 0, temp;
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the maximum range: ");
	scanf("%d",&maxrange);
	printf("Enter the requests: ");
	for (int i = 0; i < n; i++){
		scanf("%d",&queue[i]);
	}
	for (int i = 0; i < n; i++){
		if (queue[i] > head){
			queue1[x] = queue[i];
			x++;
		}
		else {
			queue2[y] = queue[i];
			y++;
		}
	}
	
	for (int i = 0; i < x - 1; i++){
		for (int j = i+1; j < x; j++){
			if (queue1[i] > queue1[j]){
				temp = queue1[i];
				queue1[i] = queue1[j];
				queue1[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < y - 1; i++){
		for (int j = i+1; j < y; j++){
			if (queue2[i] < queue2[j]){
				temp = queue2[i];
				queue2[i] = queue2[j];
				queue2[j] = temp;
			}
		}
	}
	//printf("X: %d, Y: %d\n",x,y);
	int index = 0, index2 = 0, total = 0, total2 = 0;
	for (int i = 0; i < x; i++){
				queue3[index] = queue1[i];
				index++;
			}
			queue3[index] = maxrange;
			index++;
			for (int i = 0; i < y; i++){
				queue3[index] = queue2[i];
				index++;
			}
			printf("The head movement from %d to %d is: %d.\n", head, queue3[0], abs(head-queue3[0]));
			total = total + abs(head-queue3[0]);
			for (int i = 0; i < index-1; i++){
				printf("The head movement from %d to %d is: %d.\n", queue3[i], queue3[i+1], abs(queue3[i]-queue3[i+1]));
				total = total + abs(queue3[i]-queue3[i+1]);
			}
			printf("The total seek time: %d.\n",total);
	return 0;
}

int cscan(int n){
	int queue[n], head, maxrange;
	int queue1[n], queue2[n], queue3[n], x = 0, y = 0, temp;
	printf("Enter the head position: ");
	scanf("%d",&head);
	printf("Enter the maximum range: ");
	scanf("%d",&maxrange);
	printf("Enter the requests: ");
	for (int i = 0; i < n; i++){
		scanf("%d",&queue[i]);
	}
	for (int i = 0; i < n; i++){
		if (queue[i] > head){
			queue1[x] = queue[i];
			x++;
		}
		else {
			queue2[y] = queue[i];
			y++;
		}
	}
	
	for (int i = 0; i < x - 1; i++){
		for (int j = i+1; j < x; j++){
			if (queue1[i] > queue1[j]){
				temp = queue1[i];
				queue1[i] = queue1[j];
				queue1[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < y - 1; i++){
		for (int j = i+1; j < y; j++){
			if (queue2[i] > queue2[j]){
				temp = queue2[i];
				queue2[i] = queue2[j];
				queue2[j] = temp;
			}
		}
	}
	//printf("X: %d, Y: %d\n",x,y);
	int direction, index = 0, index2 = 0, total = 0, total2 = 0;
	printf("1.Right\n2.Left\nChoose a direction: ");
	scanf("%d",&direction);
	switch(direction){
		case 1:
			for (int i = 0; i < y; i++){
				queue3[index] = queue2[i];
				index++;
			}
			queue3[index] = maxrange;
			index++;
			for (int i = 0; i < x; i++){
				queue3[index] = queue1[i];
				index++;
			}
			printf("The head movement from %d to %d is: %d.\n", head, queue3[0], abs(head-queue3[0]));
			total = total + abs(head-queue3[0]);
			for (int i = 0; i < index-1; i++){
				printf("The head movement from %d to %d is: %d.\n", queue3[i], queue3[i+1], abs(queue3[i]-queue3[i+1]));
				total = total + abs(queue3[i]-queue3[i+1]);
			}
			printf("The total seek time: %d.\n",total);
			break;
		case 2:
			for (int i = 0; i < x; i++){
				queue3[index2] = queue1[i];
				index2++;
			}
			queue3[index2] = maxrange;
			index2++;
			for (int i = 0; i < y; i++){
				queue3[index2] = queue2[i];
				index2++;
			}
			printf("The head movement from %d to %d is: %d.\n", head, queue3[0], abs(head-queue3[0]));
			total2 = total2 + abs(head-queue3[0]);
			for (int i = 0; i < index2-1; i++){
				printf("The head movement from %d to %d is: %d.\n", queue3[i], queue3[i+1], abs(queue3[i]-queue3[i+1]));
				total2 = total2 + abs(queue3[i]-queue3[i+1]);
			}
			printf("The total seek time: %d.\n",total2);
			break;
		default:
			printf("Enter either 1 or 2.\n");
			break;
	}
	/*printf("Queue - 3\n");
	for (int i = 0; i < index2; i++){
		printf("%d ",queue3[i]);
	}
	printf("Queue greater than head.\n");
	for (int i = 0; i < x; i++){
		printf("%d ",queue1[i]);
	}
	printf("Queue lesser than head.\n");
	for (int i = 0; i < y; i++){
		printf("%d ",queue2[i]);
	}*/
	return 0;
}
