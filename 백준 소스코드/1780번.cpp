#include<iostream>

using namespace std;



int map[2200][2200];
int cnt[3];

void paper(int h, int w,int size) {

	if (size == 1) {
		if (map[h][w] == -1)
			cnt[0]++;
		else if (map[h][w] == 0)
			cnt[1]++;
		else
			cnt[2]++;
		return;
	}

	for (int i = h; i < h + size; i++) {
		for (int j = w; j < w + size; j++) {
			if (map[h][w] != map[i][j]) {
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						paper(h + (size / 3)*a, w + (size / 3)*b, size / 3);
					}
				}
				return;
			}
		}
	}

	if (map[h][w] == -1)
		cnt[0]++;
	else if (map[h][w] == 0)
		cnt[1]++;
	else if (map[h][w] == 1)
		cnt[2]++;
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	paper(1, 1, n);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}
}