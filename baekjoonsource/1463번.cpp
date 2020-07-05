#include<cstdio>
#include<algorithm>



using namespace std;

int dp[10000007];


int main() {
	int num;
	int cnt = 0;
	scanf("%d",&num);
	dp[cnt] = num;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= num; i++)
	{
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		else
			dp[i] = dp[i - 1] + 1;
	}

	printf("%d\n", dp[num]);
	
}