#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
char graph[55][55];
int a, b;

struct node {
	int x;
	int y;
	int depth = 0;
};


int bfs(int x,int y) {
	int num = 0;
	int c, d;
	node n;
	queue < node> q;
	int visited[55][55] = { 0 };
	
	n.x = x;
	n.y = y;

	q.push(n);
	while (!q.empty()) {
		c = q.front().x;
		d = q.front().y;
		
		for (int i = 0; i < 4; i++) {
			n.x = c+ dx[i];
			n.y = d + dy[i];

			if (n.x >= 0 && n.x < a && n.y >= 0 && n.y < b
				&&graph[n.x][n.y] == 'L'&&visited[n.x][n.y] == 0) {
				n.depth = q.front().depth + 1;
				q.push(n);
				visited[n.x][n.y] = 1;
			}
		}

		if (num < q.front().depth)
			num = q.front().depth;
		q.pop();

	}
	return num;
}



int main() {
	int temp;
	int max = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> graph[i][j];
		}
	}


	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (graph[i][j] == 'L') {
				temp=bfs(i, j);
				if (temp > max)
					max = temp;
			}
		}
	}

	cout << max << endl;
}