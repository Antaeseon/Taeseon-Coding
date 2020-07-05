#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

char map[12][12];
bool visited[12][12][12][12];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct node {
	int by;
	int bx;
	int ry;
	int rx;
	int cnt = 0;
};


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int by, bx, ry, rx;
	queue<node>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'B') {
				by = i;
				bx = j;
			}
			else if (map[i][j] == 'R') {
				ry = i;
				rx = j;
			}
		}
	}
	q.push({ by,bx,ry,rx,0 });
	visited[by][bx][ry][rx] = true;

	while (!q.empty()) {
		int tempBy = q.front().by;
		int tempBx = q.front().bx;
		int tempRy = q.front().ry;
		int tempRx = q.front().rx;
		int tempCnt = q.front().cnt;
		q.pop();

		if (tempCnt > 10)
			break;

		if (map[tempRy][tempRx] == 'O') {
			cout <<"1\n";
			return 0;
		}



		for (int i = 0; i < 4; i++) {
			int bcnt = 0;
			int rcnt = 0;
			int nby = tempBy, nbx = tempBx, nry = tempRy, nrx = tempRx;
			while (map[nby + dy[i]][nbx + dx[i]] != '#'&&map[nby][nbx] != 'O') {
				nby += dy[i];
				nbx += dx[i];
				bcnt++;
			}
			while (map[nry + dy[i]][nrx + dx[i]] != '#'&&map[nry][nrx] != 'O') {
				nry += dy[i];
				nrx += dx[i];
				rcnt++;
			}

			if (nbx == nrx && nby == nry) {
				if (map[nby][nbx] == 'O')
					continue;
				if (bcnt > rcnt) {
					nby -= dy[i];
					nbx -= dx[i];
				}
				else {
					nry -= dy[i];
					nrx -= dx[i];
				}
			}
			
			if (visited[nby][nbx][nry][nrx])
				continue;
			visited[nby][nbx][nry][nrx] = true;
			if (map[nby][nbx] == 'O')
				continue;
			q.push({ nby,nbx,nry,nrx,tempCnt + 1 });



		}
	}

	cout << "0\n";
}