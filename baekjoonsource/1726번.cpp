#include<iostream>
#include<queue>


using namespace std;

struct node {
	int height;
	int width;
	int d;
	int cnt=0;
};

int map[103][103];
int visited[5][103][103];
int dw[5] = {0,1,-1,0,0}; //동서남북
int dh[5] = {0,0,0,1,-1};
queue<node>q;

int counter(int n) { //동일경우 서 남일경우 북을 반환
	if (n == 1) return 2;
	else if (n == 2) return 1;
	else if (n == 3) return 4;
	else return 3;
}


int main() {
	int m, n;
	int tempH, tempW, tempD;
	cin >> m >> n;
	node in, out;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> in.height >> in.width >> in.d;
	cin >> out.height >> out.width >> out.d;

	visited[in.d][in.height][in.width] = 1;
	q.push(in);

	while (!q.empty()) {
		tempH = q.front().height;
		tempW = q.front().width;
		tempD = q.front().d;

		if (tempH == out.height&&tempW == out.width&&tempD == out.d)
			cout << q.front().cnt << endl;


		for (int i = 1; i <= 3; i++) {  //앞으로 1씩 진행한다.
			in.height = tempH + dh[tempD] * i;
			in.width = tempW + dw[tempD] * i;
			in.d = tempD;
			if (in.height<1 || in.height>m || in.width<1 || in.width>n)
				break;
			if (map[in.height][in.width])
				break;
			if (visited[tempD][in.height][in.width])
				continue;
			visited[tempD][in.height][in.width] = 1;
			in.cnt = q.front().cnt + 1;
			q.push(in);
		}

		for (int i = 1; i <= 4; i++) { //90도 또는 -90도 방향으로 방향 전환
			in.height = tempH;
			in.width = tempW;
			in.d = tempD;
			if (i == in.d||i==counter(in.d))
				continue;
			if (visited[i][in.height][in.width])
				continue;
			visited[i][in.height][in.width] = 1;
			in.d = i;
			in.cnt = q.front().cnt + 1;
			q.push(in);
		}
		q.pop();
	}
}