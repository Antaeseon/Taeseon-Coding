#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int dragon[1024];
int map[102][102];
int x, y, d, g;
int main() {
	int n;
	cin >> n;
	dragon[0] = 0;
	dragon[1]=1;
	int temp1 = 2;
	int temp2 = 4;

	while (1) {
		int j = temp1 - 1;
		for (int i = temp1; i < temp2; i++,j--) {
			dragon[i] = (dragon[j]+1)%4;
		}
		temp1 *= 2;
		temp2 *= 2;

		if (temp2 == 2048)
			break;
	}



	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		map[x][y] = 1;
		for (int i = 0; i < (1 << g); i++) {
			x = x + dx[(dragon[i] + d) % 4];
			y = y + dy[(dragon[i] + d) % 4];
			map[x][y] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				cnt++;
		}
	}

	cout << cnt << "\n";


}