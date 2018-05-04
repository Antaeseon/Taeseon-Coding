#include<cstdio>
#include<cmath>

int kong[1003][1003];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			kong[i][j] = 1;
		}
	}
}