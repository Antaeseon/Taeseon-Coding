#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
int d;
int minimum = 0;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return false;
}


void dfs(vector<vector<int>>tmap, vector<int>watcher) {
	int tcnt = 0;
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>>v1;
		vector<pair<int, int>>v2;
		vector<pair<int, int>>v3;
		
		for (int y = n - 1; y >= 0; y--) {
			for (int x = 0; x < m; x++) {
				if (tmap[y][x] == 1) {
					if (abs(n - y) + abs(x - watcher[0]) <= d) {
						v1.push_back({ abs(n - y) + abs(x - watcher[0]),x });
					}
					if (abs(n - y) + abs(x - watcher[1]) <= d) {
						v2.push_back({ abs(n - y) + abs(x - watcher[1]),x });
					}
					if (abs(n - y) + abs(x - watcher[2]) <= d) {
						v3.push_back({ abs(n - y) + abs(x - watcher[2]),x });
					}
				}
			}
		}
		sort(v1.begin(), v1.end(), cmp);
		sort(v2.begin(), v2.end(), cmp);
		sort(v3.begin(), v3.end(), cmp);
		if (!v1.empty()) {
			if (tmap[n - abs(v1[0].first - abs(watcher[0]-v1[0].second))][v1[0].second] == 1) {
				tmap[n - abs(v1[0].first - abs(watcher[0] - v1[0].second))][v1[0].second] = 0;
				tcnt++;
			}
		}
		if (!v2.empty()) {
			if (tmap[n - abs(v2[0].first - abs(watcher[1]-v2[0].second))][v2[0].second] == 1) {
				tmap[n - abs(v2[0].first - abs(watcher[1] - v2[0].second))][v2[0].second] = 0;
				tcnt++;
			}

		}
		if (!v3.empty()) {
			if (tmap[n - abs(v3[0].first - abs(watcher[2] - v3[0].second))][v3[0].second] == 1) {
				tmap[n - abs(v3[0].first - abs(watcher[2] - v3[0].second))][v3[0].second] = 0;
				tcnt++;
			}

		}
		for (int x = 0; x < m; x++) {
			for (int y = n; y > 0; y--) {
				if (y == n) {
					tmap[y-1][x] = 0;
				}
				else {
					swap(tmap[y][x], tmap[y - 1][x]);
				}
			}
		}



	}

	minimum = max(minimum, tcnt);
}





int main() {
	std::ios::sync_with_stdio(false), cin.tie();
	vector<vector<int>>map(20, vector<int>(20, 0));
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i < (1 << m); i++) {
		vector<int>watcher;
		for (int j = 0; j < m; j++) {
			if (i&(1 << j)) {
				watcher.push_back(j);
			}
			if (watcher.size() > 3)
				break;
		}
		if (watcher.size() == 3)
			dfs(map, watcher);
	}

	
	cout << minimum << "\n";
}