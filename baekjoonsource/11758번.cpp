#include<cstdio>
#include<algorithm>


int main()
{
	int x[3], y[3];
	int s;
	int turn; //반시계 1, 시계 -1 일직선 0
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	s = x[0] * y[1] + x[1] * y[2] + x[2] * y[0]
		- (x[1] * y[0] + x[2] * y[1] + x[0] * y[2]);

	if (s > 0)
		turn = -1;
	else if (s == 0)
		turn = 0;
	else
		turn = 1;

	printf("%d\n", turn);
	
}