#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

//#define TOTAL_NODE 80
#define TOTAL_TIME 1000000
#define THRESHOLD (INT_MAX/10)

void* sim(int TOTAL_NODE)
{
	srand((unsigned)time(NULL));
	int i, t, round, last[TOTAL_NODE], totWakeup = 0, totValidWakeup = 0;
	double totInterval = 0;
	unsigned long sx, x, sy, y;
	int *wake = (int*)malloc(TOTAL_TIME * sizeof(int));
	memset(wake, 0xff, TOTAL_TIME * sizeof(int));
	memset(last, 0, TOTAL_NODE * sizeof(int));
	for (i = 0; i < TOTAL_NODE; i++)
	{
		/*sx = */x = rand() % TOTAL_NODE + 1;
		/*sy = */y = rand() % TOTAL_NODE + 1;
		t = x;
		//round = 0;
		while (t <= TOTAL_TIME)
		{
			wake[t] = (wake[t] < 0)? i : TOTAL_NODE;
			y += x;
			x = y - x;
			if ((x > THRESHOLD) || (y > THRESHOLD))
			{
				x = rand() % TOTAL_NODE + 1;
				y = rand() % TOTAL_NODE + 1;
			}
			/*
			round++;
			if (round == 60)
			{
				x = sx;
				y = sy;
				round = 0;
			}
			*/
			t += x % TOTAL_NODE + 1;
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
