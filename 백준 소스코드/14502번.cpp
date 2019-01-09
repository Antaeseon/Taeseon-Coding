#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int y, x;
int map[9][9];
int tempmap[9][9];
int result = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int totalcount = 0;
struct node {
	int y;
	int x;

};

void copyMap() {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			tempmap[i][j] = map[i][j];
		}
	}
}

int bfs() {
	node n;
	queue<node>q;
	int cnt = 0;
	copyMap();
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (tempmap[i][j] == 2) {
				n.y = i;
				n.x = j;
				q.push(n);
			}
		}
	}

	while (!q.empty()) {
		int tempY = q.front().y;
		int tempX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			n.y = tempY + dy[i];
			n.x = tempX + dx[i];

			if (n.x < 0 || n.x >= x || n.y<0 || n.y>y)
				continue;
			if (tempmap[n.y][n.x] == 0) {
				tempmap[n.y][n.x] = 2;
				q.push(n);
			}
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (tempmap[i][j] == 0)
				cnt++;
		}
	}
	return cnt;


}

void makeWall(int tempY,int cnt) {

	if (cnt > 3)
		return;
	if (cnt == 3) {
		int temp = bfs();
		if (result < temp)
			result = temp;
		return;
	}
	for (int i = tempY; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				if (j + 1 == x) {
					makeWall(i+1,cnt + 1);
				}
				makeWall(i, cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> y >> x;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> map[i][j];
		}
	}

	makeWall(0,0);

	cout<<result << "\n";

}