#include<cstdio>

long long tile[1003];

int main()
{
	int num;
	scanf("%d", &num);
	tile[1] = 1;
	tile[2] = 2;

	for (int i = 3; i <= num; i++)
	{
		tile[i] = tile[i - 1] + tile[i - 2];
		tile[i] %= 10007;
	}

	printf("%lld", tile[num]);
	

}