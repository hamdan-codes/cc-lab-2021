#include<stdio.h>
int main()
{

#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input", "r", stdin);
	freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif

	int  process[10], arrival[10], burst[10], ct[10], tat[10], wt[10], i, j, temp = 0, n;
	float awt = 0, atat = 0;
	// printf("enter no of proccess you want:");
	scanf("%d", &n);
	// printf("enter %d process:", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &process[i]);
	}
	// printf("enter %d arrival time:", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arrival[i]);
	}
	// printf("enter %d burst time:", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &burst[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < (n - i); j++)
		{
			if (arrival[j] > arrival[j + 1])
			{
				temp = process[j + 1];
				process[j + 1] = process[j];
				process[j] = temp;
				temp = arrival[j + 1];
				arrival[j + 1] = arrival[j];
				arrival[j] = temp;
				temp = burst[j + 1];
				burst[j + 1] = burst[j];
				burst[j] = temp;
			}
		}
	}
	ct[0] = arrival[0] + burst[0];
	for (i = 1; i < n; i++)
	{
		temp = 0;
		if (ct[i - 1] < arrival[i])
		{
			temp = arrival[i] - ct[i - 1];
		}
		ct[i] = ct[i - 1] + burst[i] + temp;
	}
	printf("\nP\t A.T\t B.T\t C.T\t TAT\t WT");
	for (i = 0; i < n; i++)
	{
		tat[i] = ct[i] - arrival[i];
		wt[i] = tat[i] - burst[i];
		atat += tat[i];
		awt += wt[i];
	}
	atat = atat / n;
	awt = awt / n;
	for (i = 0; i < n; i++)
	{
		printf("\nP%d\t %d\t\t %d\t\t %d\t\t %d\t\t %d",
		       process[i], arrival[i], burst[i], ct[i], tat[i], wt[i]);
	}
	printf("\naverage turnaround time is %.2f", atat);

	printf("\naverage wating timme is %.2f", awt);


	return 0;
}
