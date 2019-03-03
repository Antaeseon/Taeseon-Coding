#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int rem(int n) {
	int m = 0;
	while (n) {
		if (n % 2)
			m++;
		n /= 2;

	}
	return m;
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n, k;
	int res = 0;
	cin >> n >> k;

	while (1) {
		if (rem(n) <= k)
			break;

		n++;
		res++;
	}

	cout << res << "\n";


}