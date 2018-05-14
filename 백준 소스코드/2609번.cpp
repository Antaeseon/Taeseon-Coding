#include<cstdio>
#include<algorithm>


using namespace std;

int gcd(int a, int b)
{
	long long n;
	if (a < b)
		swap(a, b);
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}


int main()
{
	int a, b;
	int g1, g2;
	scanf("%d %d", &a, &b);
	g1 = gcd(a, b);
	g2 = a * b / g1;

	printf("%d %d\n", g1, g2);
}