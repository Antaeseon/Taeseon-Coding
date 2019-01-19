#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int map[52][52];
bool visited[52][52];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int y, int x) {
	if (visited[y][x])
		return;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int tempY = y + dy[i];
		int tempX = x + dx[i];

		if (map[tempY][tempX] && !visited[tempY][tempX])
			dfs(tempY, tempX);
	}
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int m, n,k; //m은 가로 n은 세로
	int y, x;
	cin >> testCase;
	while (testCase--) {
		int cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && map[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}

		cout << cnt << "\n";
	}

}