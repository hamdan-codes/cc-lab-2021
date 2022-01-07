// Author: Chaudhary Hamdan, 1905387

#include<stdio.h>


void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
	wt[0] = 0;

	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i - 1] + wt[i - 1] - processes[i];
}

void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt);

	findTurnAroundTime(processes, n, bt, wt, tat);


	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
	}
	int s = total_wt * 1.0 / n;
	int t = total_tat * 1.0 / n;
	printf("Average waiting time: %d", s);
	printf("\nAverage turn around time: %d ", t);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input", "r", stdin);
	freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif


	int n;
	scanf("%d", &n);

	int processes[n], burst_time[n];

	for (int i = 0; i < n ; i++) {
		scanf("%d", &processes[i]);
		scanf("%d", &burst_time[i]);
	}

	findavgTime(processes, n, burst_time);
	return 0;
}
