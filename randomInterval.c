#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define TOTAL_NODE 80
#define TOTAL_TIME 1000000

void* sim(int TOTAL_NODE)
{
	srand((unsigned)time(NULL));
	int i, t, last[TOTAL_NODE], totWakeup = 0, totValidWakeup = 0;
	double totInterval = 0;
	int *wake = (int*)malloc(TOTAL_TIME * sizeof(int));
	memset(wake, 0xff, TOTAL_TIME * sizeof(int));
	memset(last, 0, TOTAL_NODE * sizeof(int));
	for (i = 0; i < TOTAL_NODE; i++)
	{
		t = rand() % TOTAL_NODE + 1;
		while (t <= TOTAL_TIME)
		{
			wake[t] = (wake[t] < 0)? i : TOTAL_NODE;
			t += rand() % TOTAL_NODE + 1;
		}
	}
	for (t = 0; t <= TOTAL_TIME; t++)
	{
		if (wake[t] < 0)
			continue;
		totWakeup++;
		if (wake[t] < TOTAL_NODE)
		{
			totValidWakeup++;
			totInterval += t - last[wake[t]];
			last[wake[t]] = t;
		}
	}
	free(wake);
	struct resultStruct
	{
		int v1, v2;
		double v3, v4;
	}*result = (struct resultStruct*)malloc(sizeof(struct resultStruct));
	result->v1 = totWakeup;
	result->v2 = totValidWakeup;
	result->v3 = (double)totValidWakeup/totWakeup;
	result->v4 = (double)totInterval/totValidWakeup;
	return result;
}
