#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;
char map[11][11];
bool visited[11][11][11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct node {
	int ry;
	int rx;
	int by;
	int bx;
	int cnt = 0;
};

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int N, M;
	cin >> N >> M;
	node n;
	queue<node>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				n.ry = i;
				n.rx = j;
			}
			if (map[i][j] == 'B') {
				n.by = i;
				n.bx = j;
			}
		}
	}

	visited[n.ry][n.rx][n.by][n.bx] = true;
	q.push(n);

	while (!q.empty()) {
		int redX = q.front().rx;
		int redY = q.front().ry;
		int blueX = q.front().bx;
		int blueY = q.front().by;
		int tCnt = q.front().cnt;
		q.pop();

		if (tCnt > 10)
			break;






		if (map[redY][redX] == 'O'&&map[blueY][blueX] != 'O')
		{
			cout << tCnt << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nrx = redX, nry = redY, nbx = blueX, nby = blueY;
			while (map[nry + dy[i]][nrx + dx[i]] != '#'&&map[nry][nrx] != 'O') {
				nry += dy[i];
				nrx += dx[i];
			}
			while (map[nby + dy[i]][nbx + dx[i]] != '#'&&map[nby][nbx] != 'O') {
				nby += dy[i];
				nbx += dx[i];
			}

			if (nrx == nbx && nry == nby) {
				if (map[nry][nrx] == 'O')
					continue;
				if (abs(redX - nrx) + abs(redY - nry) < abs(blueX - nbx) + abs(blueY - nby)) {
					nbx -= dx[i];
					nby -= dy[i];
				}
				else {
					nrx -= dx[i];
					nry -= dy[i];
				}
			}

			if (visited[nry][nrx][nby][nbx])
				continue;
			visited[nry][nrx][nby][nbx] = true;
			node tp = { nry,nrx,nby,nbx,tCnt + 1 };
			q.push(tp);
		}
	}

	cout << "-1\n";


}
