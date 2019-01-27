#include<iostream>
#include<vector>	
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int map[101][101];
bool visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int minimum = 1e9;

struct node {
	int y;
	int x;
	int cnt=0;
};

void bfs(int land) {
	node n;
	queue<node> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == land) {
				n.y = i;
				n.x = j;
				q.push(n);
				visited[i][j] = true;
			}
		}
	}


	while (!q.empty()) {
		int tempY = q.front().y;
		int tempX = q.front().x;
		int tempCnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			n.y = tempY + dy[i];
			n.x = tempX + dx[i];
			if (n.y < 0 || n.y >= N || n.x < 0 || n.x >= N)
				continue;
			if (map[n.y][n.x] == land && !visited[n.y][n.x]) {
				visited[n.y][n.x] = true;
				q.push(n);
			}
			else if (map[n.y][n.x] == 0 && !visited[n.y][n.x]) {
				visited[n.y][n.x] = true;
				n.cnt = tempCnt + 1;
				q.push(n);
			}
			else if (map[n.y][n.x] != 0 && map[n.y][n.x] != land) {
				minimum = min(minimum, tempCnt);
				return;
			}
		}
	}



}
void dfs(int y, int x,int land) {
	if (visited[y][x])
		return;

	map[y][x] = land;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			continue;
		
		if (!visited[nextY][nextX] && map[nextY][nextX] == 1)
			dfs(nextY, nextX, land);
	}
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> N;
	int land = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				dfs(i, j, land);
				land++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0&&!visited[i][j]) {
				bfs(map[i][j]);
			}
		}
	}

	cout << minimum << "\n";

}