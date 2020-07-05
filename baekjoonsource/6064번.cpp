#include<iostream>

using namespace std;

long long gcd(long long  a, long long  b)
{

	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	long long x, y, Tx, Ty;
	long long a, b;
	long long cnt = 0;
	cin >> n;




	while (n--) {
		cin >> x >> y >> Tx >> Ty;
		if (x > y) {
			swap(x, y);
			swap(Tx, Ty);
		}


		int gc = gcd(x, y);
		int lcm = x * y / gc;
		if (Tx ==x&& Ty==y) {
			cout << lcm << "\n";
		}
		else {
			if (Tx%gc != Ty % gc) {
				cout << "-1" << "\n";
				continue;
			}

			long long cnt = Tx;
			int tempY = Tx % y;
			for (int i = 0; i < y; i++) {
				if (Ty == tempY)
				{
					cout << cnt << "\n";
					break;
				}

				cnt += x;
				tempY += x;
				tempY %=y;
				if (tempY == 0)
					tempY = y;
			}

		}


	}

}