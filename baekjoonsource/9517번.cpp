#include<iostream>
#include<deque>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int k;
	int n;
	int total = 210;
	cin >> k >> n;
	int cur = k;
	for (int i = 0; i < n; i++) {
		int a;
		char t;
		cin >> a >> t;
		total -= a;
		if (total <= 0)
			break;
		if (t == 'T') {
			cur++;
			if (cur == 9)
				cur = 1;
		}
	}

	cout << cur << "\n";


}