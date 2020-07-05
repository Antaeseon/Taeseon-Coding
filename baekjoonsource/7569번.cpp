#include<iostream>
#include<queue>

using namespace std;

int tomato[102][102][102];
int visited[102][102][102];
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
struct node {
	int x;
	int y;
	int z;
	int depth = 0;
};

int main() {
	int m, n, h;
	int a, b, c;
	int sum = 0;
	node to;
	queue<node>q;
	int ripe = 0;
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					to.x =k;
					to.y =j;
					to.z = i;
					to.depth = 0;
					visited[i][j][k] = 1;
					q.push(to);
				}
				if (tomato[i][j][k] != 0)
					ripe++;
			}
		}
	}
	if (ripe == m*n*h) {
		cout << "0" << endl;
		return 0;
	}

	while (!q.empty()) {
		a = (int)q.front().x;
		b = (int)q.front().y;
		c = (int)q.front().z;

		for (int i = 0; i < 6; i++) {
			to.x = a + dx[i];
			to.y = b + dy[i];
			to.z = c + dh[i];
			if (to.x<0 || to.x>m - 1 || to.y < 0 || to.y > n - 1 || to.z<0 || to.z>h - 1)
				continue;
			if (tomato[to.z][to.y][to.x] == 0) {
				to.depth = (int)q.front().depth + 1;
				q.push(to);
				visited[to.z][to.y][to.x] = 1;
				tomato[to.z][to.y][to.x] = 1;
			}
		}
		sum = q.front().depth;
		q.pop();
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0)
				{
					cout << "-1" << endl;
					return 0;
				}
			}
		}
	}
	cout << sum << endl;
}