#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char map[51][51];
int n, m;
int maximum = 0;

void sq(int y, int x) {
	int num = map[y][x];
	int msqare = min(n - y-1, m - x-1);
	
	if (msqare <= maximum)
		return;

	for (int i = maximum; i <= msqare; i++) {
		if (map[y][x] == map[y + i][x] && map[y][x] == map[y][x+i]&&map[y][x]==map[y+i][x+i]) {
			maximum = i;
		}
	}



}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			sq(i, j);
		}
	}
	maximum++;
	cout << maximum*maximum << "\n";


}