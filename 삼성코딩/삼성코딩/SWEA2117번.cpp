#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int price[55];
int maximum = 0;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	price[1] = 1;
	int temp = 1;
	for (int i = 2; i <= 50; i++) {
		price[i] = price[i - 1] + temp * 4;
		temp++;
	}
	int testCase;
	int n, m;
	int inp;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		vector<pair<int, int>>v;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> inp;
				if (inp == 1) {
					v.push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = 1; j <= 2 * n;j++) {
				int hNum = 0;
				for (int k = 0; k < v.size(); k++) {
					if (abs(v[i].first - v[k].first) + abs(v[i].second - v[k].second) < j)
						hNum++;
				}
				maximum = max(maximum, hNum * 3 - price[j]);
			}
		}

		cout << "#" << z << " " << maximum << "\n";
		maximum = 0;


	}
}