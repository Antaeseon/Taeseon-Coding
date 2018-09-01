#include<cstdio>


void hanoi(int k,int from,int by,int to) {
	if (k == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(k - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(k - 1, by, from, to);
	}
}





int main() {
	int k;
	scanf("%d", &k);
	printf("%d\n", (1 << k) - 1);
	hanoi(k, 1, 2, 3);
}