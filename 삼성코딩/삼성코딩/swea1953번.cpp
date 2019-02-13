#include<iostream>
#include<queue>
#include<algorithm>


using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int st1[4][8] = {
	{0,1,1,0,0,1,1,0},
	{0,1,0,1,0,0,1,1},
	{0,1,1,0,1,0,0,1},
	{0,1,0,1,1,1,0,0}
};
int st2[4][8] = {
	{0,1,1,0,0,1,1,0},
	{0,0,0,0,0,0,0,0},
	{0,1,1,0,1,0,0,1},
	{0,0,0,0,0,0,0,0}
};
int st3[4][8] = {
	{0,0,0,0,0,0,0,0},
	{0,1,0,1,0,0,1,1},
	{0,0,0,0,0,0,0,0},
	{0,1,0,1,1,1,0,0}
};
int st4[4][8] = {
	{0,1,1,0,0,1,1,0},
	{0,1,0,1,0,0,1,1},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};
int st5[4][8] = {
	{0,0,0,0,0,0,0,0},
	{0,1,0,1,0,0,1,1},
	{0,1,1,0,1,0,0,1},
	{0,0,0,0,0,0,0,0}
};
int st6[4][8] = {
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,1,1,0,1,0,0,1},
	{0,1,0,1,1,1,0,0}
};
int st7[4][8] = {
	{0,1,1,0,0,1,1,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,1,0,1,1,1,0,0}
};




int main() {
	int testCase;
	int n, m, r, c, l;

	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		queue<pair<int, int>>q;
		int map[52][52] = { 0, };
		bool visited[52][52] = { false, };
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		q.push({ r,c });
		visited[r][c] = true;
		int cnt = 1;


		while (!q.empty()) {
			int my = q.front().first;
			int mx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextY = my + dy[i];
				int nextX = mx + dx[i];
				
				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
					continue;

				if (visited[nextY][nextX])
					continue;

				if (map[my][mx] == 1) {
					if (st1[i][map[nextY][nextX]]) {
						cnt++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}
				}
				else if (map[my][mx] == 2) {
					if (st2[i][map[nextY][nextX]]) {
						cnt++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}

				}
				else if (map[my][mx] == 3) {
					if (st3[i][map[nextY][nextX]]) {
						cnt++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}

				}
				else if (map[my][mx] == 4) {
					if (st4[i][map[nextY][nextX]]) {
						cnt++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}

				}
				else if (map[my][mx] == 5) {
					if (st5[i][map[nextY][nextX]]) {
						cnt++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}

				}
				else if (map[my][mx] == 6) {
					if (st6[i][map[nextY][nextX]]) {
						cnt++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}

				}
				else {
					if (st7[i][map[nextY][nextX]]) {
						cnt++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}

				}



			}

			cout << "#" << z << " " << cnt << "\n";

		}


	}





}