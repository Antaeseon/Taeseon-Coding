#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int map[10][10];
int sak[6];


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int tcnt = 0;
	int tempcnt = 0;
	int rcnt = 0;
	for (int i = 0; i < 6; i++)
		sak[i] = 5;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				tempcnt++;
		}
	}

		for (int i = 5; i >= 1; i--) {
			for (int y = 0; y < 10; y++) {
				if (y + i >10)
					break;
				for (int x = 0; x < 10; x++) {
					if (x + i >10)
						break;
					bool flag = false;
					for (int sy = y; sy < y + i; sy++) {
						for (int sx = x; sx < x + i; sx++) {
							if (map[sy][sx] == 0) {
								flag = true;
								break;
							}
						}
						if (flag)
							break;
					}
					if (flag == false) {
						sak[i]--;
						if (sak[i] < 0) {
							cout << "-1\n";
							return 0;
						}

						for (int sy = y; sy < y + i; sy++) {
							for (int sx = x; sx < x + i; sx++) {
								map[sy][sx] = 0;
							}
						}
						tcnt++;
					}



				}
			}
		}


	cout << tcnt << "\n";
}