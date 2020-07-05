#include<cstdio>
#include<algorithm>

int dp[102][102];
int num;



int main() {
	scanf("%d", &num);
	int sum = 0;

	if (num == 1)
	{
		printf("9\n");
		return 0;
	}

	for (int i = 1; i <= 9; i++) {
		dp[0][i] = 1;
	}
	
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[num - 1][i];
		sum %= 1000000000;
	}

	printf("%d\n", sum);
}