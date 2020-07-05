#include<iostream>
#include<algorithm>

using namespace std;

int map[21][21];
int dx[5] = {0,0,0, -1,1 };
int dy[5] = {0, 1,-1 ,0,0,};
int dice[7] = { 0, };

int main() {
	int N, M, x, y, k;
	int dir;
	cin >> N >> M >> x >> y >> k;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}


	while (k--) {
		cin >> dir;
		int tempdice[7] = { 0, };
		
			int nextX = x + dx[dir];
			int nextY = y + dy[dir];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
				continue;
			
			if (dir == 1) {
				tempdice[3] = dice[1];
				tempdice[1] = dice[4];
				tempdice[2] = dice[2];
				tempdice[5] = dice[5];
				tempdice[6] = dice[3];
				tempdice[4] = dice[6];

			}
			else if (dir == 2) {
				tempdice[4] = dice[1];
				tempdice[1] = dice[3];
				tempdice[6] = dice[4];
				tempdice[5] = dice[5];
				tempdice[2] = dice[2];
				tempdice[3] = dice[6];
			}
			else if (dir == 3) {
				tempdice[6] = dice[2];
				tempdice[1] = dice[5];
				tempdice[5] = dice[6];
				tempdice[2] = dice[1];
				tempdice[4] = dice[4];
				tempdice[3] = dice[3];
			}
			else {
				tempdice[2] = dice[6];
				tempdice[1] = dice[2];
				tempdice[5] = dice[1];
				tempdice[3] = dice[3];
				tempdice[4] = dice[4];
				tempdice[6] = dice[5];

			}

			if (map[nextX][nextY] == 0) {
				map[nextX][nextY] = tempdice[6];
			}
			else {
				tempdice[6] = map[nextX][nextY];
				map[nextX][nextY] = 0;
			}
			cout << tempdice[1]<<"\n";

			for (int i = 0; i < 7; i++)
				dice[i] = tempdice[i];
			y = nextY;
			x = nextX;

		}


}