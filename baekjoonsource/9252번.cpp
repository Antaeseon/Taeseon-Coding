#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int dp[1003][1003];
int res[1003];
int main() {
	std::ios::sync_with_stdio(false);
	string a, b;
	bool checking = false;
	vector<char>v;
	int maxi;
	int fa=-1, fb=-1;
	int temp;

	int cnt = 0;
	int tdp = 1;
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

	int h = a.size();
	int w = b.size();
	while (dp[h][w]!=0) {
		if (dp[h][w] == dp[h - 1][w])
			h--;
		else if (dp[h][w] == dp[h][w - 1])
			w--;
		else {
			v.push_back(a[h - 1]);
			h--;
			w--;
		}
	}

	reverse(v.begin(), v.end());


	cout << dp[a.size()][b.size()]<<"\n";
	for (auto ch : v)
		cout<<ch;

}