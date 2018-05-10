#include<cstdio>
#include<algorithm>


using namespace std;

int tri[1000][1000];
int dp[1000][1000];

int main()
{
	int n;
	int inp;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			scanf("%d", &inp);
			tri[i][j] = inp;
			if (i == 0) {
				dp[i][j] = tri[0][0];
				continue;
			}
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			}
			else
				dp[i][j] = max(dp[i - 1][j] + tri[i][j], dp[i - 1][j - 1] + tri[i][j]);
		}
	}




	int max = 0;

	for (int i = 0; i < n; i++)
	{
		if (dp[n - 1][i] > max)
			max = dp[n - 1][i];
	}
	printf("%d\n", max);
}