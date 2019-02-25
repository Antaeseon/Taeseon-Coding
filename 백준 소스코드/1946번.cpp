#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int a, b;
	int n;
	cin >> testCase;
	while (testCase--) {
		vector<pair<int, int>>v;
		int res = 1;
		int minimum;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		minimum = v[0].second;
		for (int i = 1; i < v.size(); i++) {
			if (v[i].second < minimum) {
				minimum = v[i].second;
				res++;
			}
		}
		cout << res << "\n";

	}
}