#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;
char map[52][52];
bool visited[52][52][65];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;
int fy, fx;

struct node {
	int y;
	int x;
	int cnt;
	int key;
};

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	queue<node>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				q.push({ i,j,0 ,0});
				map[i][j] = '.';
			}
		}
	}

	while (!q.empty()) {
		int tempY = q.front().y;
		int tempX = q.front().x;
		int tempCnt = q.front().cnt;
		int tempKey = q.front().key;
		q.pop();



		for (int i = 0; i < 4; i++) {
			int nextY = tempY + dy[i];
			int nextX = tempX + dx[i];
			if (map[nextY][nextX]=='1') {
				cout << tempCnt+1 << "\n";
				return 0;
			}
			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
				continue;
			if (visited[nextY][nextX][tempKey])
				continue;
			if (map[nextY][nextX] == '.') {
				visited[nextY][nextX][tempKey] = true;
				q.push({ nextY,nextX,tempCnt + 1,tempKey });
			}
			else if (map[nextY][nextX] >= 'a'&&map[nextY][nextX] <= 'f'){
				int nextKey =(map[nextY][nextX] - 'a');
				nextKey = 1 << nextKey;
				nextKey = tempKey | nextKey;
				visited[nextY][nextX][nextKey] = true;
				q.push({ nextY,nextX,tempCnt + 1,nextKey });
			}
			else if(map[nextY][nextX] >= 'A'&&map[nextY][nextX] <= 'F'){
				if (tempKey&1<<(map[nextY][nextX] - 'A')) {
					visited[nextY][nextX][tempKey] = true;
					q.push({ nextY,nextX,tempCnt + 1,tempKey });
				}
			}


		}

	}

	cout << "-1\n";

}