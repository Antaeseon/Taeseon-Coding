#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int n, m;
int maximum = 0;
vector<vector<int>>tmap(1003, vector<int>(1003, 0));
vector<vector<int>>map(1003, vector<int>(1003, 0));
int dir[1003][2];

int main() {
	std::ios::sync_with_stdio(false), cin.tie();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (i == 1) {
				tmap[i][j] = tmap[i][j-1] + map[i][j];
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dir[j][0] = dir[j][1] = tmap[i - 1][j] + map[i][j];
		}

		for (int j = 2; j <= m; j++) {
			dir[j][0] = max(dir[j][0], dir[j - 1][0] + map[i][j]);
		}
		for (int j = m - 1; j >= 1; j--) {
			dir[j][1] = max(dir[j][1], dir[j + 1][1] + map[i][j]);
		}

		for (int j = 1; j <= m; j++) {
			tmap[i][j] = max(dir[j][0], dir[j][1]);
		}
	}
	cout << tmap[n][m] << "\n";
}