#include<iostream>
using namespace std;

int map[51][51];
int dy[4] = { -1,0,1,0 }; //ºÏ,µ¿,³²,¼­
int dx[4] = { 0,1,0,-1 };
int res = 0;

void dfs(int y, int x, int dir) {
	if (map[y][x] == 1)
		return;
	if (map[y][x] == 0) {
		map[y][x] = 2;
		res++;
	}
	for (int i = 0; i < 4; i++) {
		int tempDir =( dir + 3) % 4;
		int nextY = y + dy[tempDir];
		int nextX = x + dx[tempDir];

		if (map[nextY][nextX] == 0) {
			dfs(nextY, nextX, tempDir);
			return;
		}
		else {
			dir = tempDir;
		}
	}
	int nextY = y - dy[dir];
	int nextX = x - dx[dir];
	dfs(nextY, nextX, dir);

}


int main() {
	int n, m;
	int ry, rx, rd;
	cin >> n >> m;
	cin >> ry >> rx >> rd;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	dfs(ry, rx, rd);
	cout << res << "\n";

}