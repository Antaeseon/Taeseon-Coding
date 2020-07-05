#include<cstdio>

int main()
{
	long long num;
	scanf("%lld", &num);

	while (num)
	{
		if (num % 2 != 0 && num != 1)
		{
			printf("0\n");
			return 0;
		}
		num=num >> 1;
	}
	printf("1\n");
}