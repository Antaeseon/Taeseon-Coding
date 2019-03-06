#include<iostream>
#include<string>

using namespace std;
long long n, k;
long long calc(long long y, long long x) {
	if (y == 0 && x == 0)
		return 1;
	long long tsum = n * n+1;
	if (x + y < n) {
		long long s = ((x + y)*(x + y + 1)) / 2;
		if ((x + y) % 2 == 0) {
			return s + 1 + x;
		}
		else {
			s = ((x + y+1)*(x + y + 2)) / 2;
			return s - x;
		}
	}
	else {
		long long tx = n - x - 1;
		long long ty = n - y - 1;
		long long s = ((tx + ty)*(tx + ty + 1)) / 2;
		if ((tx + ty) % 2 == 0) {
			return tsum-(s + 1 + tx);
		}
		else {
			s = ((tx + ty + 1)*(tx + ty + 2)) / 2;
			return tsum-(s - tx);
		}
	}
}

int main() {
	string inp;
	cin >> n >> k;
	cin >> inp;

	long long x = 0, y = 0;
	long long sum = 1;
	for (int i = 0; i < inp.size(); i++) {
		if (inp[i] == 'D') {
			y++;
			sum += calc(y, x);
		}
		else if (inp[i] == 'U') {
			y--;
			sum += calc(y, x);
		}
		else if (inp[i] == 'L') {
			x--;
			sum += calc(y, x);
		}
		else {
			x++;
			sum += calc(y, x);
		}
	}

	cout << sum << "\n";
}