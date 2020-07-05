#include<cstdio>


int main()
{
	long long num;
	scanf("%lld", &num);

	long long a = 0;
	long long b = 1;
	long long total=0;
	if (num == 0)
	{
		printf("0\n");
		return 0;
	}
	else if (num == 1)
	{
		printf("1\n");
		return 0;
	}
	while(--num)
	{
		total = a + b;
		total %= 1000000;
		a = b;
		a %= 1000000;
		b = total;
		b %= 1000000;
	}

	printf("%lld\n", total);
}