#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct node {
	int y;
	int x;
	int cnt = 1;
	int wall = 0;
};

char map[1001][1001];
bool visited[1001][1001][2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int y, x;
	bool beforeWall = false;
	node n;
	queue<node>q;
	cin >> y >> x;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> map[i][j];
		}
	}
	
	n.y = 0;
	n.x = 0;
	q.push(n);
	visited[0][0][0] = true;


	while (!q.empty()) {
		int tempY = q.front().y;
		int tempX = q.front().x;
		int tempCnt = q.front().cnt;
		int tempWall = q.front().wall;

		if (tempY == y - 1 && tempX == x - 1) {
			cout << tempCnt << "\n";
			return 0;
		}

		q.pop();
		for (int i = 0; i < 4; i++) {
			n.y = tempY + dy[i];
			n.x = tempX + dx[i];

			if (n.y < 0 || n.y >= y || n.x < 0 || n.x >= x)
				continue;
			if (map[n.y][n.x] == '0'&&!visited[n.y][n.x][0]&&tempWall==0) {
				n.cnt = tempCnt + 1;
				visited[n.y][n.x][0] = true;
				n.wall = 0;
				q.push(n);
			}
			if (map[n.y][n.x] == '1'&&!visited[n.y][n.x][1] && tempWall == 0) {
				n.cnt = tempCnt + 1;
				visited[n.y][n.x][1] = true;
				n.wall=1;
				q.push(n);
			}
			if (map[n.y][n.x] == '0' && !visited[n.y][n.x][1] && tempWall) {
				n.cnt = tempCnt + 1;
				visited[n.y][n.x][1] = true;
				n.wall = 1;
				q.push(n);
			}

		}
	}

	cout << "-1" << "\n";
}