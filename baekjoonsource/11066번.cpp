#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<cstring>
using namespace std;

int dp[502][502];
int num[503];

int dynamic(int s, int d) {
	if (s == d)
		return 0;

	if (dp[s][d] != -1)
		return dp[s][d];

	int tmp = num[d] - num[s - 1];
	dp[s][d] = 1e9;
	for (int i = s; i < d; i++) {
		dp[s][d] = min(dp[s][d],
			dynamic(s, i) + dynamic(i + 1, d) + tmp);
	}
	return dp[s][d];
}


int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	int temp;

	cin >> n;

	while (n--) {
		priority_queue<int, vector<int>, greater<int>>q;
		cin >> k;
		memset(dp, -1, sizeof(dp));

		for (int i = 1; i <= k; i++) {
			cin >> temp;
			num[i] = num[i - 1] + temp;
		}

		int res = dynamic(1, k);
		cout << res << "\n";
	}


}