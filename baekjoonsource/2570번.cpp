#include<cstdio>
#include<algorithm>

int stair[302];
int dp[302];

using namespace std;

int main() {
	int n;
	scanf("%d", &n);


	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &stair[i]);
	}
	dp[1] = stair[1];
	dp[2] = stair[1]+stair[2];
	dp[3] = max(stair[3] + dp[1], stair[3] + stair[2]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
	}

	printf("%d\n", dp[n]);
}