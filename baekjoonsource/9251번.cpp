#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

int dp[1003][1003];

int main() {
	std::ios::sync_with_stdio(false);
	string a, b;
	int maxi;
	int temp = 0;
	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			temp = 0;
			if (a[i - 1] == b[j - 1])
				temp = 1;
			dp[i][j] = max(dp[i - 1][j - 1] + temp, dp[i][j - 1]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}


	cout << dp[a.size()-1][b.size()-1];
}