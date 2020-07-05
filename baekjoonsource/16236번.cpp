#include<iostream>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;

int map[22][22];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
struct shark {
	int y;
	int x;
	int cnt = 0;
	int size = 2;
	int move = 0;
};

bool cmp(shark a, shark b) {
	if (a.move < b.move)
		return true;
	else if(a.move>b.move)
		return false;
	if (a.y < b.y)
		return true;
	else if(a.y>b.y)
		return false;
	if (a.x < b.x)
		return true;
	else
		return false;
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int res = 0;
	int n;
	shark s;
	queue<shark>q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s.y = i;
				s.x = j;
				map[i][j] = 0;
			}
		}
	}

	while (1) {
		int maxMove = 1e9;
		bool visited[21][21] = { false, };
		visited[s.y][s.x] = true;
		vector<shark>v;
		q.push(s);

		while (!q.empty()) {
			int tempY = q.front().y;
			int tempX = q.front().x;
			int tempCnt = q.front().cnt;
			int tempShark = q.front().size;
			int tempMove = q.front().move;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextY = tempY + dy[i];
				int nextX = tempX + dx[i];
				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
					continue;
				if (visited[nextY][nextX])
					continue;
				if (map[nextY][nextX] == 0||map[nextY][nextX]==tempShark) {
					visited[nextY][nextX] = true;
					s.y = nextY;
					s.x = nextX;
					s.cnt = tempCnt;
					s.move = tempMove + 1;
					s.size = tempShark;
					q.push(s);
				}
				else if (map[nextY][nextX]<tempShark) {
					visited[nextY][nextX] = true;
					s.y = nextY;
					s.x = nextX;
					s.cnt = tempCnt+1;
					s.move = tempMove + 1;
					s.size = tempShark;
					v.push_back(s);
				}
				
			}
		}
		sort(v.begin(), v.end(),cmp);
		if (v.size() == 0)
			break;
		res += v[0].move;
		if (v[0].size == v[0].cnt) {
			s.size = v[0].size + 1;
			s.cnt = 0;
		}
		else {
			s.size = v[0].size;
			s.cnt = v[0].cnt;
		}
		s.y = v[0].y;
		s.x = v[0].x;
		s.move = 0;
		map[s.y][s.x] = 0;
	}
	cout << res << "\n";
}