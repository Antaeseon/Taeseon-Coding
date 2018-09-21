#include<cstdio>
#include<algorithm>

using namespace std;

int wine[10005];
int dp[10005];


int main() {

	int n;
	int temp;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &wine[i]);
	}

	if (n == 1)
	{
		printf("%d\n", wine[1]);
	}
	else if (n == 2)
	{
		printf("%d\n", wine[1] + wine[2]);
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];


	for (int i = 3; i <= n; i++)
	{
		temp = 0;
		temp = max(dp[i-2]+wine[i],dp[i-1]);
		temp = max(temp,wine[i]+ wine[i - 1] + dp[i - 3]);
		dp[i] = temp;
	}
	
	printf("%d\n", dp[n]);
}