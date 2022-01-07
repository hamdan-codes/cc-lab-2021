// Author: Chaudhary Hamdan, 1905387

#include<stdio.h>

int main()
{

#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input", "r", stdin);
	freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif



	int i, limit, total = 0, x, counter = 0, time_quantum;
	int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time
	                                     [10], temp[10];
	float average_wait_time, average_turnaround_time;
	scanf("%d", &limit);
	x = limit;
	for (i = 0; i < limit; i++)
	{
		scanf("%d", &arrival_time[i]);
		scanf("%d", &burst_time[i]);
		temp[i] = burst_time[i];
	}
	scanf("%d", &time_quantum);
	for (total = 0, i = 0; x != 0;)
	{
		if (temp[i] <= time_quantum && temp[i] > 0)
		{
			total = total + temp[i];
			temp[i] = 0;
			counter = 1;
		}
		else if (temp[i] > 0)
		{
			temp[i] = temp[i] - time_quantum;
			total = total + time_quantum;
		}
		if (temp[i] == 0 && counter == 1)
		{
			x--;
			wait_time = wait_time + total - arrival_time[i] -
			            burst_time[i];
			turnaround_time = turnaround_time + total -
			                  arrival_time[i];
			counter = 0;
		}
		if (i == limit - 1)
		{
			i = 0;
		}
		else if (arrival_time[i + 1] <= total)
		{
			i++;
		}
		else
		{
			i = 0;
		}
	}
	average_wait_time = wait_time * 1.0 / limit;
	average_turnaround_time = turnaround_time * 1.0 / limit;
	printf("Average Waiting Time:%f", average_wait_time);
	printf("\nAvg Turnaround Time:%f\n", average_turnaround_time);
	return 0;
}
