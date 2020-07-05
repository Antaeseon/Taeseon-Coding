#include<iostream>


using namespace std;

long long dp[105];

int main() {
	std::ios::sync_with_stdio(false);
	int num;
	int k;
	cin >> num;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	while (num--) {
		cin >> k;
		if (k <= 3)
		{
			cout << dp[k]<<"\n";
			continue;
		}

		for (int i = 4; i <= k; i++) {
			dp[i] = dp[i - 3] + dp[i - 2];
		}
		cout << dp[k] << "\n";
	}

}