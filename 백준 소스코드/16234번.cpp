#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;
int n, l, r;
int map[52][52];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool visited[51][51] = { false ,  };
int result = 0;

bool bfs(int y, int x) {
	queue<pair<int, int>>q;
	vector<pair<int, int>>v;
	bool flag = false;
	int sum = 0;
	visited[y][x] = true;
	q.push({ y,x });
	v.push_back({ y,x });
	sum += map[y][x];
	while (!q.empty()) {
		int tempY = q.front().first;
		int tempX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = tempY + dy[i];
			int nextX = tempX + dx[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
				continue;
			if (!visited[nextY][nextX] && (abs(map[nextY][nextX] - map[tempY][tempX]) >= l && abs(map[nextY][nextX] - map[tempY][tempX]) <= r)) {
				flag = true;
				visited[nextY][nextX] = true;
				q.push({ nextY,nextX });
				v.push_back({ nextY,nextX });
				sum += map[nextY][nextX];
			}
		}
	}
	if (flag) {
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = (sum / v.size());
		}
	}



	return flag;
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> l >> r;
	bool chk;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j])
					chk = bfs(i, j);
				if (chk == true)
					cnt++;

			}
		}
		if (cnt>0)
			result++;
		else
			break;
	}


	cout << result << "\n";
}