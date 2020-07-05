#include<iostream>
#include<queue>

using namespace std;

struct node {
	int y;
	int x;
	int cnt;
};
int dy[8] = { -2,-2,-1,-1,1,1,2,2 };
int dx[8] = { -1,1,-2,2,-2,2,-1,1 };
int chess[301][301];
int visited[301][301];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	node e;
	queue<node>q;
	int testcase;
	int N;
	int startY, startX, desY, desX;
	
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		cin >> startY >> startX;
		chess[startX][startX] = 1;
		cin >> desY >> desX;
		chess[desY][desX] = 2;

		e.y = startY;
		e.x = startX;
		e.cnt = 0;
		q.push(e);
		visited[e.y][e.x] = 1;
		while (!q.empty()) {
			int tempY = q.front().y;
			int tempX = q.front().x;
			int tempCnt = q.front().cnt;
			q.pop();

			if (chess[tempY][tempX] == 2) {
				cout << tempCnt << "\n";
			}



			for (int i = 0; i < 8; i++) {
				e.y = tempY + dy[i];
				e.x = tempX + dx[i];

				if (e.y < 0 || e.y >= N || e.x < 0 || e.x >= N)
					continue;

				if (visited[e.y][e.x] == 0) {
					e.cnt = tempCnt + 1;
					visited[e.y][e.x] = 1;
					q.push(e);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				chess[i][j] = 0;
				visited[i][j] = 0;
			}
		}


	}

	

}

