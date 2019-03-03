#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;
int n, k;
int minimum = 1e9;
int house[100005];
int dis[100005];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int ans = 0;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> n >> k;

		for (int i = 1; i <= n; i++)
			cin >> house[i];
			
		for (int i = 1; i <= n - 1; i++)
			dis[i] = house[i + 1] - house[i];
		sort(dis + 1, dis + n);

		for (int i = 1; i <= n - k; i++) {
			ans += dis[i];
		}
		cout << "#" << z << " " << ans << "\n";
		ans = 0;
	}



}