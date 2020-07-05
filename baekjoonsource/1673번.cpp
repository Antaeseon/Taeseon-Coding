#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	long long n, k;

	while(cin >> n >> k) {

		long long sum = 0;
		

		while (1) {
			sum += (n - n % k);
			long long temp = n - n % k;
			n = n % k;
			n = n + temp / k;

			if (k > n)
				break;

		}

		cout << sum +n << "\n";
	}
}