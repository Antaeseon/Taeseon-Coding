#include<cstdio>
#include<algorithm>


using namespace std;

int gcd(int a, int b)
{
	int n;
	if (a < b)
		swap(a, b);
	while (b != 0)
	{
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}



int main() {
	int n,a, b;
	int result;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &a, &b);
		result = gcd(a, b);
		result = a * b / result;
		printf("%d\n", result);
	}
}