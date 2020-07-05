#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long test[1000006];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	long long n;
	long long a, b;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> test[i];
	}
	
	cin >> a >> b;
	sum += n;


	for (int i = 0; i < n; i++) {
		test[i] -= a;
		if (test[i] < 0) {
			test[i] = 0;
			continue;
		}
		sum+= (ceil(double(test[i]) / double(b)));
	}

	cout << sum << "\n";
}