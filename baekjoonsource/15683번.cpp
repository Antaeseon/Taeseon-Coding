#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int map[10][10];
int maximum = 0;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m;

struct node{
	int num;
	int y;
	int x;
};

vector<node>v;

void dfs(vector < vector <bool>>visited, int cnt, int dir,int cur) {
	if (cur == v.size()) {
		maximum = max(maximum, cnt);
		return;
	}
	int y = v[cur].y;
	int x = v[cur].x;
	int cam = v[cur].num;
	int nextY;
	int nextX;
	if (cam == 1) {
		nextY = y + dy[dir];
		nextX = x + dx[dir];
		while (nextY >= 0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] !=6 ) {
			if (map[nextY][nextX] == 0&&visited[nextY][nextX]==false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dir];
			nextX += dx[dir];
		}
		dfs(visited, cnt, 0, cur + 1);
		dfs(visited, cnt, 1, cur + 1);
		dfs(visited, cnt, 2, cur + 1);
		dfs(visited, cnt, 3, cur + 1);
	}
	else if (cam == 2) {
		int dirY = dir;
		int dirX = (dir + 2) % 4;
		nextY = y + dy[dirY];
		nextX = x + dx[dirY];
		while (nextY >= 0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dirY];
			nextX += dx[dirY];
		}
		nextY = y + dy[dirX];
		nextX = x + dx[dirX];
		while (nextY >= 0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dirX];
			nextX += dx[dirX];
		}
		dfs(visited, cnt, 0, cur + 1);
		dfs(visited, cnt, 1, cur + 1);
		dfs(visited, cnt, 2, cur + 1);
		dfs(visited, cnt, 3, cur + 1);
	}
	else if (cam == 3) {
		int dirY = dir;
		int dirX = (dir + 1) % 4;
		nextY = y + dy[dirY];
		nextX = x + dx[dirY];
		while (nextY >=0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dirY];
			nextX += dx[dirY];
		}
		nextY = y + dy[dirX];
		nextX = x + dx[dirX];
		while (nextY >= 0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dirX];
			nextX += dx[dirX];
		}
		dfs(visited, cnt, 0, cur + 1);
		dfs(visited, cnt, 1, cur + 1);
		dfs(visited, cnt, 2, cur + 1);
		dfs(visited, cnt, 3, cur + 1);
	}
	else if (cam == 4) {
		int dirY = dir;
		int dirX = (dir + 1) % 4;
		int dirY2 = (dir + 2) % 4;
		nextY = y + dy[dirY];
		nextX = x + dx[dirY];
		while (nextY >= 0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dirY];
			nextX += dx[dirY];
		}
		nextY = y + dy[dirX];
		nextX = x + dx[dirX];
		while (nextY >= 0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dirX];
			nextX += dx[dirX];
		}
		nextY = y + dy[dirY2];
		nextX = x + dx[dirY2];
		while (nextY >= 0 && nextY < n&&nextX>=0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[dirY2];
			nextX += dx[dirY2];
		}

		dfs(visited, cnt, 0, cur + 1);
		dfs(visited, cnt, 1, cur + 1);
		dfs(visited, cnt, 2, cur + 1);
		dfs(visited, cnt, 3, cur + 1);

	}
	else {
		nextY = y + dy[0];
		nextX = x + dx[0];
		while (nextY >= 0 && nextY < n&&nextX >= 0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[0];
			nextX += dx[0];
		}
		nextY = y + dy[1];
		nextX = x + dx[1];
		while (nextY >= 0 && nextY < n&&nextX >= 0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[1];
			nextX += dx[1];
		}
		nextY = y + dy[2];
		nextX = x + dx[2];
		while (nextY >= 0 && nextY < n&&nextX >= 0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[2];
			nextX += dx[2];
		}
		nextY = y + dy[3];
		nextX = x + dx[3];
		while (nextY >= 0 && nextY < n&&nextX >= 0 && nextX < m&&map[nextY][nextX] != 6) {
			if (map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				cnt++;
			}
			nextY += dy[3];
			nextX += dx[3];
		}
		dfs(visited, cnt, 0, cur + 1);
		dfs(visited, cnt, 1, cur + 1);
		dfs(visited, cnt, 2, cur + 1);
		dfs(visited, cnt, 3, cur + 1);
	}

}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	node camera;
	int mcount = 0;
	cin >> n >> m;
	vector<vector<bool> > visited(10, vector<bool>(10, false));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				camera.num = map[i][j];
				camera.y = i;
				camera.x = j;
				v.push_back(camera);
			}
			if (map[i][j] != 0)
				mcount++;
		}
	}

	dfs(visited, 0, 0, 0);
	dfs(visited, 0, 1, 0);
	dfs(visited, 0, 2, 0);
	dfs(visited, 0, 3, 0);

	cout << n*m-maximum-mcount << "\n";


}