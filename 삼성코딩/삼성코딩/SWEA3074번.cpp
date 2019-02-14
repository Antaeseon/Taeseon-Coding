#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m; //n 심사대 m 사람수
int total[100006];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int through;
	int testCase;
	cin >> testCase;

	for (int z = 1; z <= testCase; z++) {
		cin >> n >> m;
		int maximum = 0;
		for (int i = 0; i < n; i++) {
			cin >> total[i];
			maximum = max(maximum, total[i]);
		}
		long long time1 = 0;
		long long time2 = m * maximum;
		long long minimum = m*maximum;
		while (time1 <= time2) {
			long long mid = (time1 + time2) / 2;
			long long ans = 0;
			for (int i = 0; i < n; i++) {
				ans += (mid / total[i]);
			}

			if (ans < m) {
				time1 = mid + 1;
			}
			else {
				if (minimum > mid)
					minimum = mid;
				time2 = mid - 1;
			}
		}
		cout << "#" << z << " " << minimum << "\n";

	}
}