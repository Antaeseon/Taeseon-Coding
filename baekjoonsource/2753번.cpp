#include<iostream>
#include<queue>

using namespace std;

int map[301][301];
int visited[301][301];
int tempCalc[301][301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };



struct node {
	int y;
	int x;
};


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int y, x;
	cin >> y >> x;
	node N;
	int cnt = 0;
	queue<node>q;
	queue<node>tempQ;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> map[i][j];
			if (map[i][j])
			{
				N.y = i;
				N.x = j;
				q.push(N);
			}
		}
	}


	while (!q.empty()) {
		cnt++;


		while (!q.empty()) { 
			int tempY = q.front().y;
			int tempX = q.front().x;
			q.pop();
			for (int i = 0; i < 4; i++) {
				N.y = tempY + dy[i];
				N.x = tempX + dx[i];

				if (N.y < 0 || N.y >= y || N.x < 0 || N.x >= x)
					continue;

				if (map[N.y][N.x] == 0)
					tempCalc[tempY][tempX]++;

			}
		}

		for (int i = 0; i < y; i++) { 
			for (int j = 0; j < x; j++) {
				if (tempCalc[i][j] > 0) {
					map[i][j] = (map[i][j] - tempCalc[i][j]) > 0 ? (map[i][j] - tempCalc[i][j]) : 0;
				}
				if (map[i][j]) {
					N.y = i;
					N.x = j;
					q.push(N);
				}
			}
		}
		
		int glacier = 0;

		for (int i = 0; i < y; i++) { 
			for (int j = 0; j < x; j++) {
				if (map[i][j]&&!visited[i][j]) {
					glacier++;
					visited[i][j] = 1;
					N.y = i;
					N.x = j;
					tempQ.push(N);

					while (!tempQ.empty()) {
						int tempY = tempQ.front().y;
						int tempX = tempQ.front().x;
						tempQ.pop();

						for (int i = 0; i < 4; i++) {
							N.y = tempY +dy[i];
							N.x = tempX +dx[i];
							if (N.y < 0 || N.y >= y || N.x < 0 || N.x >= x)
								continue;
							if (map[N.y][N.x] && visited[N.y][N.x]==0) {
								visited[N.y][N.x] = 1;
								tempQ.push(N);
							}
						}
					}
				}
			}
		}
		if (glacier >= 2)
		{
			cout << cnt << "\n";
			return 0;
		}

		if (glacier == 0) {
			cout << "0" << "\n";
			return 0;
		}

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				visited[i][j] = 0;
				tempCalc[i][j] = 0;
			}
		}






	}

}