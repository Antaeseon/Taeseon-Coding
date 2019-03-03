#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
char map[302][302];
bool visited[302][302];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int n;
int tcnt = 0;

int checking(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (map[nextY][nextX] == '*') {
			cnt++;
		}
	}
	return cnt;
}

void bfs(int y, int x) {
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	tcnt++;
	while (!q.empty()) {
		int tY = q.front().first;
		int tX = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nextY = tY + dy[i];
			int nextX = tX + dx[i];

			if (nextY<1 || nextY>n || nextX<1 || nextY>n)
				continue;
			if (visited[nextY][nextX])
				continue;
			if (map[nextY][nextX] == '.') {
				int tchecking = checking(nextY, nextX);
				char a = tchecking;
				if (tchecking == 0) {
					q.push({ nextY,nextX });
					map[nextY][nextX] = '0';
				}
				else {
					map[nextY][nextX] =a;
				}
				visited[nextY][nextX] = true;
			}
		}
	}	
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> n;
		int nothing = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] != '.') {
					visited[i][j] = true;
					nothing++;
				}

			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == '.' && !visited[i][j] && checking(i, j) == 0) {
					bfs(i, j);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j])
					tcnt++;
			}
		}
		cout << "#" << z << " " << tcnt << "\n";
		memset(visited, false, sizeof(visited));
		memset(map, '$', sizeof(map));
		tcnt = 0;

	}
}