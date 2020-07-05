#include<iostream>
#include<algorithm>

using namespace std;
int R, C;
char map[21][21];
int alpha[30];
int visited[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int maximum = 0;

void dfs(int y, int x, int cnt) {
	if (y == 0 && x == 0)
	{
		visited[0][0] = 1;
		alpha[map[0][0] - 'A'] = 1;
	}

	maximum = max(maximum, cnt);
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
			continue;
		if (!visited[nextY][nextX] && !alpha[map[nextY][nextX]-'A']) {
			visited[nextY][nextX] = 1;
			alpha[map[nextY][nextX]-'A'] = 1;
			dfs(nextY, nextX, cnt + 1);
			visited[nextY][nextX] = 0;
			alpha[map[nextY][nextX]-'A'] = 0;
		}
		
	}
}

int main() {
	cin >> R >> C;
	int visited[21][21] = { 0, };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0, 1);
	cout << maximum << "\n";
}