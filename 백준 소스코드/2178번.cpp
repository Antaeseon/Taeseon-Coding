#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

char box[1003][1003];
int visited[1003][1003];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };



struct node {
	int x;
	int y;
	int depth;

};

int main() {
	queue <node> q;
	node n;
	int width, height;
	int a, b;
	cin >> height >> width;

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cin >> box[i][j];
		}
	}
	n.x = 1;
	n.y = 1;
	n.depth = 1;
	q.push(n);
	visited[1][1] = true;
		

	while (!q.empty()) {
		a = q.front().x;
		b = q.front().y;
		//q.pop();
		for (int i = 0; i < 4; i++) {
			n.x = a + dx[i];
			n.y = b + dy[i];

			if (n.x<1 || n.x>height || n.y<1 || n.y>width) {
				continue;
			}

			if (!visited[n.x][n.y] && box[n.x][n.y]=='1') {
				n.depth = q.front().depth + 1;
				q.push(n);
				visited[n.x][n.y] = 1;

				if (n.x == height && n.y == width) {
					cout << n.depth << endl;
					return 0;
				}
			}

		}
		q.pop();
	}

}