#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int map[1001][1001];
bool visited[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int status;
	int time;
};

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	node l;
	int testCase;

	cin >> testCase;
	for (int z = 1; z <= testCase; z++) { 
		queue<node>q[11];
		int n, m, k;
		cin >> n >> m >> k;

		for (int i = 500; i < 500 + n; i++) {
			for (int j = 500; j < 500 + m; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0) {
					l.y = i;
					l.x = j;
					l.status = 1; //0 죽음 1 비활성 2 활성
					l.time = 0;
					visited[i][j] = true;
					q[map[i][j]].push(l);
				}
			}
		}

		for (int i = 1; i <= k; i++) {
			for (int j = 10; j >= 1; j--) {
				if (q[j].size() == 0)
					continue;
				int sz = q[j].size();
				for (int k = 0; k < sz; k++) {
					int ty = q[j].front().y;
					int tx = q[j].front().x;
					int ts = q[j].front().status;
					int tt = q[j].front().time;
					q[j].pop();
					tt++;
					if (ts==1) {
						if (tt == map[ty][tx]) {
							ts = 2;
							tt = 0;
						}
							q[j].push({ ty,tx,ts,tt });
					}
					else if (ts == 2) {
						if (tt < map[ty][tx]) {
							q[j].push({ ty,tx,ts,tt });
						}

						if (tt == 1) {
							for (int v = 0; v < 4; v++) {
								int ny = ty + dy[v];
								int nx = tx + dx[v];

								if (visited[ny][nx])
									continue;
								if (map[ny][nx] == 0) {
									map[ny][nx] = map[ty][tx];
									visited[ny][nx] = true;
									q[j].push({ ny,nx,1,0 });
								}

							}
						}


					}

				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= 10; i++) {
			sum += q[i].size();
		}
		cout << "#" << z << " " << sum << "\n";
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
	}
}