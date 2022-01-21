// Author: Chaudhary Hamdan, 1905387
// Generated at: Fri Jan 21 12:47:25 2022

#include<stdio.h>
#include <limits.h>

int main() {

#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\KIIT\\input", "r", stdin);
	freopen("C:\\Users\\KIIT\\output", "w", stdout);
#endif


	int tasks, machines;
	scanf("%d%d", &machines, &tasks);

	int maxMin[machines][tasks];
	int table[machines][tasks];
	int makespan = 0;

	for (int i = 0; i < machines; i++)
		for (int j = 0; j < tasks; j++) {
			scanf("%d", &maxMin[i][j]);
			table[i][j] = maxMin[i][j];
		}

	printf("Original Data\n");
	for (int i = 0; i < machines; i++) {
		for (int j = 0; j < tasks; j++)
			printf("%d ", maxMin[i][j]);
		printf("\n");
	}

	int resultTask[tasks];
	int resultMachine[tasks];
	int resultTime[tasks];

	int ptr = -1;
	while (ptr < tasks - 1) {
		int time[tasks], machine[tasks];
		for (int j = 0; j < tasks; j++) {
			int minimum = INT_MAX;
			int pos = -1;
			for (int i = 0; i < machines; i++) {
				if (maxMin[i][j] < minimum) {
					minimum = maxMin[i][j];
					pos = i;
				}
			}
			time[j] = minimum;
			machine[j] = pos;
		}
		int maximum = INT_MIN;
		int pos = -1;
		for (int j = 0; j < tasks; j++) {
			if (time[j] > maximum && time[j] != INT_MAX) {
				maximum = time[j];
				pos = j;
			}
		}
		resultTask[++ptr] = pos;
		resultMachine[ptr] = machine[pos];
		resultTime[ptr] = table[machine[pos]][pos];
		if (maximum > makespan)
			makespan = maximum;
		for (int i = 0; i < machines; i++) {
			for (int j = 0; j < tasks; j++) {
				if (j == resultTask[ptr])
					maxMin[i][j] = INT_MAX;
				else if (i == resultMachine[ptr] && maxMin[i][j] != INT_MAX)
					maxMin[i][j] += maximum;
				else
					continue;
			}
		}
	}
	printf("\nScheduled Task are :\n");
	for (int i = 0; i < tasks; i++) {
		printf("Task %d Runs on Machine %d with Time %d units\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
	}
	printf("\nMakespan : %d units\n", makespan);


	return 0;
}
