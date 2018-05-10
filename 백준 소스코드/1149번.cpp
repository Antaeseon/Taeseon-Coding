#include<cstdio>
#include<algorithm>
using namespace std;

int color[1004][3];


int main()
{


	int num;
	int r, g, b;
	scanf("%d", &num);

	scanf("%d %d %d", &color[0][0], &color[0][1], &color[0][2]);

	for (int i = 1; i < num; i++) {
		scanf("%d", &r);
		scanf("%d", &g);
		scanf("%d", &b);
		color[i][0] = r + min(color[i - 1][1], color[i - 1][2]);
		color[i][1] = g + min(color[i - 1][0], color[i - 1][2]);
		color[i][2] = b + min(color[i - 1][0], color[i - 1][1]);

	}
	int output = min(color[num - 1][0], color[num - 1][1]);
	output = min(output, color[num - 1][2]);

	printf("%d", output);
}