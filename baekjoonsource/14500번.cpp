#include<iostream>
#include<algorithm>

using namespace std;
int n, m;
int map[502][502];
bool visited[502][502];
int maximum = 0;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x, int cur, int sum) {
	if (cur == 4) {
		maximum = max(maximum, sum);
		return;
	}
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
			continue;
		if (!visited[nextY][nextX]) {
			dfs(nextY, nextX, cur + 1, sum + map[nextY][nextX]);
		}
	}
	visited[y][x] = false;
}

void countF() {
	int sum = 0;
	for (int i = 0; i < m - 2; i++) {  //ぬ
		sum = 0;
		for (int j = 0; j < n - 1; j++) {
			sum += map[j][i];
			sum += map[j][i+1];
			sum += map[j + 1][i + 1];
			sum += map[j][i+2];
			maximum = max(maximum, sum);
			sum = 0;
		}
	}		

	for (int i = 0; i < m - 2; i++) { // で
		sum = 0;
		for (int j = 1; j < n; j++) {
			sum += map[j][i];
			sum += map[j][i + 1];
			sum += map[j - 1][i + 1];
			sum += map[j][i + 2];
			maximum = max(maximum, sum);
			sum = 0;
		}
	}

	for (int i = 0; i < m - 1; i++) { // っ
		sum = 0;
		for (int j = 1; j < n-1; j++) {
			sum += map[j][i];
			sum += map[j][i + 1];
			sum += map[j - 1][i + 1];
			sum += map[j+1][i + 1];
			maximum = max(maximum, sum);
			sum = 0;
		}
	}

	for (int i = 0; i < m - 1; i++) { // た
		sum = 0;
		for (int j = 1; j < n - 1; j++) {
			sum += map[j][i];
			sum += map[j-1][i];
			sum += map[j+1][i];
			sum += map[j][i + 1];
			maximum = max(maximum, sum);
			sum = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 0, 0);
		}
	}
	countF();
	cout << maximum << "\n";

}