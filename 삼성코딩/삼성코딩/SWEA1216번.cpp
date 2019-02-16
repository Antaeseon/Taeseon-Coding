#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
char map[101][101];
char rmap[101][101];

int main() {
	int n;
	for (int z = 1; z <= 10; z++) {
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				rmap[j][i] = map[i][j];
			}
		}
		int maximum = 1;
		for (int i = 0; i < 100; i++) {
			for (int upper = 100; upper >= maximum; upper--) {
				if (maximum >= upper)
					break;
				for (int j = 0; j <= 100-upper; j++) {
					if (j + upper - 1 >= 100)
						break;
					bool flag = true;
					for (int x = j, rx = j + upper - 1; j < upper / 2; x++, rx--) {
						if (map[i][x] != map[i][rx]) {
							flag = false;
							break;
						}
					}
					if (flag) {
						maximum = max(maximum, upper);
					}
					flag = true;
					for (int x = j, rx = j + upper - 1; j < upper / 2; x++, rx--) {
						if (rmap[i][x] != rmap[i][rx]) {
							flag = false;
							break;
						}
					}
					if (flag) {
						maximum = max(maximum, upper);
					}
				}

			}
		}

		cout << "#" << z << " " << maximum << "\n";
	}
}