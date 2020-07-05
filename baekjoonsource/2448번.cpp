#include<iostream>


using namespace std;

char map[10000][10000];



void star(int h, int w,int size) {
	if (size == 3) {
		map[h][w] = '*';
		map[h + 1][w - 1] = '*';
		map[h + 1][w + 1] = '*';
		map[h + 2][w - 2] = '*';
		map[h + 2][w - 1] = '*';
		map[h + 2][w] = '*';
		map[h + 2][w +1] = '*';
		map[h + 2][w + 2] = '*';
		return;
	}

	star(h, w, size / 2);
	star(h +size/2, w - size / 2, size / 2);
	star(h+size/ 2, w + size / 2, size / 2);
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n+1; j++) {
			map[i][j] = ' ';
		}
	}


	star(0, n, n);

	for (int i = 0; i < n; i++) {
		for (int j = 1;j< 2 * n-1; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}