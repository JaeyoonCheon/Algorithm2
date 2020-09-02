#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CASE 100
#define MAX_NUMBER 1000
#define MAX_COST 100

double avgCost(int cost[MAX_NUMBER], int first, int last);

int main(void)
{
	int i, j, c;
	int C, N, L;
	int cost[MAX_NUMBER] = { 0 };
	double Avg = 0, MinAvg = 101;
	double ans[MAX_CASE] = { 0 };

	scanf("%d", &C);

	for (c = 0; c < C; c++)
	{
		scanf("%d %d", &N, &L);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &cost[i]);
		}

		for (i = 0; i < N; i++)//시작점
		{
			for (j = i + L - 1; j < N; j++)//탐색 범위. 최소~최대 범위의 평균값 계산
			{
				Avg = avgCost(cost, i, j);
				if (Avg < MinAvg)
				{
					MinAvg = Avg;
				}
			}
		}
		ans[c] = MinAvg;
	}

	for (i = 0; i < C; i++)
	{
		printf("%lf\n", ans[i]);
	}

	return 0;
}

double avgCost(int cost[MAX_NUMBER], int first, int last)//case마다의 평균값 계산
{
	int i;
	double avg = 0, count = (double)last - (double)first +1;

	for (i = first; i <= last; i++)
	{
		avg += cost[i];
	}
	
	return (avg / count);
}