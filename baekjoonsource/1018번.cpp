#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
char map[51][51];
bool visited[51][51];
int minimum = 1e9;
char color[2] = { 'B','W' };
int cnt = 0;
void dfs(int y, int x,int curY,int curX,int colorNum) { //0Àº B 1Àº W
	if (cnt > minimum)
		return;
	if (curY<y || curY>=y + 8 || curX < x || curX >= x + 8)
		return;
	if (visited[curY][curX])
		return;
	visited[curY][curX] = true;
	if (map[curY][curX] != color[colorNum])
		cnt++;
	if (colorNum == 0) {
		dfs(y, x, curY + 1, curX, 1);
		dfs(y, x, curY , curX+1, 1);
	}
	else {
		dfs(y, x, curY + 1, curX, 0);
		dfs(y, x, curY, curX + 1, 0);
	}
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int y, x;
	cin >> y >> x;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= y - 8; i++) {
		for (int j = 0; j <= x - 8; j++) {
			cnt = 0;
			memset(visited, false, sizeof(visited));
			dfs(i, j,i,j ,0);
			minimum = min(minimum, cnt);

			cnt = 0;
			memset(visited, false, sizeof(visited));
			dfs(i, j,i,j, 1);
			minimum = min(minimum, cnt);
		}
	}


	cout << minimum << "\n";
}