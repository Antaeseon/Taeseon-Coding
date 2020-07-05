#include<iostream>

using namespace std;

long long map[101][101];
long long dp[101][101] = { 0, };

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	long long N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (dp[y][x] == 0)
				continue;
			if (y == N - 1 && x == N - 1) {
				continue;
			}
			long long Right = x + map[y][x];
			long long Down = y + map[y][x];

			if(Right<N)
				dp[y][Right] += dp[y][x];
			if(Down<N)
				dp[Down][x] += dp[y][x];
		}
	}
	cout << dp[N - 1][N - 1] << "\n";

}