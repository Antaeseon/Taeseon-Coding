#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
char map[15][15];
bool visited[15][15];
int cnt = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


struct node {
	int y;
	int x;
};


int bfs(int y, int x,char target) {
	node n;
	queue<node>q;
	vector<pair<int, int>>tVect;

	int cnt = 1;
	n.y = y;
	n.x = x;
	visited[y][x] = true;
	q.push(n);
	tVect.push_back({ y,x });
	while (!q.empty()) {
		int tempY = q.front().y;
		int tempX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			n.y = tempY + dy[i];
			n.x = tempX + dx[i];

			if (n.y < 0 || n.y >= 12 || n.x < 0 || n.x >= 6)
				continue;
			if (map[n.y][n.x] == target && !visited[n.y][n.x]) {
				cnt++;
				visited[n.y][n.x] = true;
				tVect.push_back({ n.y,n.x });
				q.push(n);
			}
		}
	}

	if (cnt >= 4) {
		for (int i = 0; i < tVect.size(); i++) {
			int cY = tVect[i].first;
			int cX = tVect[i].second;
			map[cY][cX] = '.';
		}
		return true;
	}
	else
	{
		return false;
	}
}

void resetMap() {
	for (int x = 0; x < 6; x++) {
		for (int y = 11; y > 0; y--) {
			if (map[y][x] == '.') {
				int temp = y - 1;
				while (temp >= 0 && map[temp][x] == '.')
					temp--;
				if (temp >= 0)
					swap(map[y][x], map[temp][x]);
			}
		}
	}
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		flag = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j])
					continue;
				if (map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B' || map[i][j] == 'P' || map[i][j] == 'Y')
					if (bfs(i, j, map[i][j]))
						flag = true;
			}
		}
		resetMap();
		if (flag)
			cnt++;
		else
			break;

	}

	cout << cnt << "\n";

}