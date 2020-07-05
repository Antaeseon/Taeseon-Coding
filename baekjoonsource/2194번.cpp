#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map[602][602];
bool visited[602][602];
int dy[4] = { -1,1,0,0 }; //ºÏ,³²,¼­,µ¿
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
};



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n, m, a, b, k;
	int y, x;
	int fy, fx;
	queue<node>q;
	cin >> n >> m >> a >> b >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> y >> x;
	q.push({ y,x,0 });
	visited[y][x] = true;
	cin >> fy >> fx;

	while (!q.empty()) {
		int ty = q.front().y;
		int tx = q.front().x;
		int tcnt = q.front().cnt;
		q.pop();
	
		if (ty == fy && tx == fx) {
			cout << tcnt << "\n";
			return 0;
		}


		for (int i = 0; i < 4; i++) {
			int ny = ty + dy[i];
			int nx = tx + dx[i];
			bool flag = true;
			if (visited[ny][nx])
				continue;

			if (i == 0) {  //ºÏ
				if (ny < 1)
					continue;
				
				for (int j = 0; j < b; j++) {
					if (map[ny][nx + j] == 1)
					{
						flag = false;
						break;
					}
				}
				if (flag) {
					visited[ny][nx] = true;
					q.push({ ny,nx,tcnt + 1 });
				}
			}
			else if (i == 1) { //³²
				if (ty + a > n)
					continue;
				for (int j = 0; j < b; j++) {
					if (map[ty+a][tx + j] == 1)
					{
						flag = false;
						break;
					}
				}
				if (flag) {
					visited[ny][nx] = true;
					q.push({ ny,nx,tcnt + 1 });
				}

			}
			else if (i == 2) { //¼­
				if (nx <1)
					continue;
				for (int j = 0; j < a; j++) {
					if (map[ny+j][nx] == 1)
					{
						flag = false;
						break;
					}
				}
				if (flag) {
					visited[ny][nx] = true;
					q.push({ ny,nx,tcnt + 1 });
				}
			}
			else if (i == 3) { //µ¿
				if (tx+b > m)
					continue;
				for (int j = 0; j < a; j++) {
					if (map[ny + j][tx+b] == 1)
					{
						flag = false;
						break;
					}
				}
				if (flag) {
					visited[ny][nx] = true;
					q.push({ ny,nx,tcnt + 1 });
				}

			}
		}

	}

	cout << "-1\n";


}
