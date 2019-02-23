#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

char map[20][20];
bool visited[20][20];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;

	for (int z = 1; z <= 10; z++) {
		cin >> n;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				cin >> map[i][j];
			}
		}
		queue<pair<int, int>>q;
		q.push({ 1,1 });
		visited[1][1] = true;
		bool flag = false;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = y + dy[i];
				int nextX = x + dx[i];
				if (map[nextY][nextX] == '0'&&!visited[nextY][nextX]) {
					q.push({ nextY,nextX });
					visited[nextY][nextX] = true;
				}
				else if (map[nextY][nextX] == '3') {
					flag = true;
					break;
				}

			}
			if (flag)
				break;
		}

		flag ? cout << "#" << z << " 1\n" : cout << "#" << z << " 0\n";
		memset(visited, false, sizeof(visited));
	}
}