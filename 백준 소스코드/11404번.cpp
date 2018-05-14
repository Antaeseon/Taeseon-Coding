#include<cstdio>
#include<stdio.h>
#include<algorithm>

using namespace std;

int m[105][105];
int main() {
	int i, j, k;
	int num, input;
	int inf = 1e8;
	scanf("%d", &num);
	scanf("%d", &input);

	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num; j++)
		{
				m[i][j] = inf;
		}
	}
	while (input--)
	{
		int a;
		scanf("%d %d %d", &i, &j, &a);
		m[i][j] = min(m[i][j],a);
	}

	for (k = 1; k <= num; k++)
	{
		for (i = 1; i <= num; i++)
		{
			for (j = 1; j <= num; j++)
			{
				if(m[i][j]>m[i][k] + m[k][j])
				m[i][j] = m[i][k] + m[k][j];
			}
		}
	}
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num; j++)
		{
			if (i == j||m[i][j]==inf)
				printf("0 ");
			else
				printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}