#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
int map[21][21];
bool dessert[101];
int maximum = 0;
int dy[4]={ 1,1,-1,-1 };
int dx[4] = { 1,-1,-1,1 };

void dfs(int sy,int sx,int y, int x, int dir, int cnt) {
	dessert[map[y][x]] = true;
	if (sy+1 == y && sx-1 == x) {
		maximum = max(maximum, cnt);
		dessert[map[y][x]] = false;
		return;
	}
	for (int nn = dir; nn < dir + 2; nn++) {
		if (nn == 4)
			break;
		int nextY = y + dy[nn];
		int nextX = x + dx[nn];

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
			continue;
		if (!dessert[map[nextY][nextX]])
			dfs(sy, sx, nextY, nextX, nn, cnt + 1);

	}
	dessert[map[y][x]] = false;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> n;
		maximum = 0;
		memset(dessert, false, sizeof(dessert));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n - 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (map[i][j] != map[i + 1][j + 1]&&map[i][j]!=map[i+1][j-1]) {
					dessert[map[i][j]] = true;
					dfs(i , j ,i+1, j+1, 0, 2);
					dessert[map[i][j]] = false;
				}
			}
		}
		maximum != 0 ? cout << "#" << z << " " << maximum << "\n" : cout << "#" << z << " -1\n";

	}
}