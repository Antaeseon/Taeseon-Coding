#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
char map[9][9];
char rmap[9][9];

int main() {
	int n;
	for (int z = 1; z <= 10; z++) {
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> map[i][j];
				rmap[j][i] = map[i][j];
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int k = 0; k <= 8 - n; k++) {
				bool flag1 = true;
				bool flag2 = true;
				for (int j = k,m=j+n-1; j < 8/n+k; j++,m--) {
					if (map[i][j] != map[i][m])
						flag1 = false;
					if (rmap[i][j] != rmap[i][m])
						flag2 = false;
				}
				if (flag1)
					cnt++;
				if (flag2)
					cnt++;
			}
		}

		cout << "#" << z << " " << cnt << "\n";
	}
}