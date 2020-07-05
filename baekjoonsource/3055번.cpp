#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

char map[52][52];
bool visited[52][52];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt = 0;
};

int main() {
	int n, m;
	cin >> n >> m;
	int desY, desX;
	node water;
	node go;
	queue<node>waterQ;
	queue<node>goQ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
				visited[i][j] = true;
			if (map[i][j] == '*') {
				water.y = i;
				water.x = j;
				waterQ.push(water);
			}
			else if (map[i][j] == 'S') {
				visited[i][j] = true;
				go.y = i;
				go.x = j;
				goQ.push(go);
			}
			else if (map[i][j] == 'D') {
				desY = i;
				desX = j;
			}
		}
	}


	while (!goQ.empty()) {

		int tempWaterSize = waterQ.size();
		for(int k=0;k< tempWaterSize;k++){
			int waterY = waterQ.front().y;
			int waterX = waterQ.front().x;
			waterQ.pop();
			for (int i = 0; i < 4; i++) {
				int nextWaterY = waterY + dy[i];
				int nextWaterX = waterX + dx[i];

				if (nextWaterY < 0 || nextWaterY >= n || nextWaterX < 0 || nextWaterY >= m)
					continue;

				if (map[nextWaterY][nextWaterX] == '.' || map[nextWaterY][nextWaterX] == 'S') {
					map[nextWaterY][nextWaterX] = '*';
					water.y = nextWaterY;
					water.x = nextWaterX;
					waterQ.push(water);
				}
			}
		}

		int tempGoSize = goQ.size();
		int tempCnt = goQ.front().cnt;
		for (int k = 0; k < tempGoSize; k++) {
			int goY = goQ.front().y;
			int goX = goQ.front().x;
			goQ.pop();
			for (int i = 0; i < 4; i++) {
				int nextGoY = goY + dy[i];
				int nextGoX = goX + dx[i];

				if (nextGoY < 0 || nextGoY >= n || nextGoX < 0 || nextGoX >= m)
					continue;

				if (map[nextGoY][nextGoX] == '.') {
					map[nextGoY][nextGoX] = 'S';
					go.y = nextGoY;
					go.x = nextGoX;
					go.cnt = tempCnt + 1;
					goQ.push(go);
				}

				if (map[nextGoY][nextGoX] == 'D') {
					cout << tempCnt+1 << "\n";
					return 0;
				}



			}
		}


	}

	cout << "KAKTUS" << "\n";


}


