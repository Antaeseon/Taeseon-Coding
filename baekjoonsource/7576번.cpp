#include<iostream>
#include<queue>

using namespace std;

int box[1002][1002];
int visited[1002][1002];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };


struct node {
	int x;
	int y;
	int depth;
};



int main() {
	queue <node> q;
	int x, y;
	int depth = 0;
	int a, b;
	int tempa, tempb;
	int level = 0;
	int sum = 0;
	int ripe = 0;
	node n;

	cin >> y>> x;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				n.x = i;
				n.y = j;
				n.depth = 0;
				visited[n.x][n.y] = true;
				q.push(n);
			}
			if (box[i][j] != 0)
				ripe++;
		}
	}

	if (ripe == x * y) {
		cout << "0" << endl;
		return 0;
	}


	while (!q.empty()) {
		a = q.front().x;
		b = q.front().y;
		for (int i = 0; i < 4; i++) {
			n.x = a + dx[i];
			n.y = b + dy[i];
			if (n.x<0 || n.x>x-1 || n.y<0 || n.y>y-1) {
				continue;
			}
			if (box[n.x][n.y] == 0 && visited[n.x][n.y] == 0
				&&box[n.x][n.y]==0) {
				n.depth = q.front().depth + 1;
				q.push(n);
				box[n.x][n.y] = 1;
				visited[n.x][n.y] = 1;
			}
		}
		sum = q.front().depth;
		q.pop();
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if(box[i][j]==0){
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	cout << sum << endl;
}