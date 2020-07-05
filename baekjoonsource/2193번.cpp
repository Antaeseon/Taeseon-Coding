#include<iostream>
#include<algorithm>

using namespace std;

long long dp[100][2];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int N;
	cin >> N;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][2] = 0;
	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[N][0] + dp[N][1] << "\n";

}