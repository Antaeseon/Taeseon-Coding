#include<cstdio>


int coin[10];

int main()
{
	int num=0;
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &coin[i]);
	}


	for (int i = 0; i < N; i++)
	{
		if (K / coin[N - 1 - i] != 0)
		{
			num += K / coin[N - 1 - i];
			K -= coin[N - 1 - i] *(K / coin[N - 1 - i]);
		}
		if (K == 0)
			break;
	}

	printf("%d\n", num);
}