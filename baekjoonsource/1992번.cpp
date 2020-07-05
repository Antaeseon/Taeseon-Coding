#include<cstdio>
#include<vector>


using namespace std;

int n;
char map[100][100];


void qtree(int h, int w,int size) {
	


	for (int i = h; i < h+size; i++) {
		for (int j = w; j <w+ size; j++) {

			if (map[i][j] != map[h][w]) {
				printf("(");

				for (int a = 0; a < 2; a++) {
					for (int b = 0; b < 2; b++) {
						qtree(h + (size / 2)*a, w + (size / 2)*b, size / 2);
					}
				}
				printf(")");
				return;
			}
		}
	}

	if (map[h][w] == '1')
		printf("1");
	else
		printf("0");
	return;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	printf("(");
	qtree(0, 0,n);
	printf(")\n");
}