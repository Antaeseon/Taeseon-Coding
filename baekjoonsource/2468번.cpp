#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int map[101][101];
bool visited[101][101];
int N;
int minWall=1e9, maxWall=-1;



void dfs(int wall, int y, int x) {
	if (map[y][x] <= wall)
		return;
	if (y < 0 || y >= N || x < 0 || x >= N)
		return;
	if (visited[y][x])
		return;
	visited[y][x] = true;

	dfs(wall, y + 1, x);
	dfs(wall, y-1, x);
	dfs(wall, y, x + 1);
	dfs(wall, y, x - 1);
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> N;
	int result = 0;
	int maxResult = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxWall)
				maxWall = map[i][j];
			if (map[i][j] < minWall)
				minWall = map[i][j];
		}
	}
	for (int k = minWall-1; k < maxWall; k++) {
		result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
					if (!visited[i][j]&&map[i][j]>k) {
						dfs(k, i, j);
						result++;
					}
			}
		}
		maxResult = max(maxResult, result);
		memset(visited, false, sizeof(visited));
	}

	cout << maxResult << "\n";


}