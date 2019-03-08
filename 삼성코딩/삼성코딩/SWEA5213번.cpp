#include<iostream>
#include<algorithm>

using namespace std;

long long arr[1000005];
long long dp[1000005];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	cin >> testCase;

	for (int i = 1; i <= 1000000; i++) {
		if (i % 2 == 1) {
			for (int j = 1; i*j <= 1000000; j++) {
				arr[i*j]+=i;
			}
		}
		dp[i] = dp[i - 1] + arr[i];
	}


	for (int z = 1; z <= testCase; z++) {
		int l, r;
		cin >> l >> r;
		long long sum = 0;
		cout << "#" << z << " " << dp[r]-dp[l-1] << "\n";
	}
}