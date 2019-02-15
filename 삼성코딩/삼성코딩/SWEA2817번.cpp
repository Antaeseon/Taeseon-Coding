#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int v[103];

int main() {
	int testCase;
	int n, k;
	int inp;
	cin >> testCase;

	for (int z = 1; z <= testCase; z++) {
		int cnt = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		for (int i = 1; i < (1 << n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (i&(1 << j)) {
					sum += v[j];
				}
			}
			if (sum == k)
				cnt++;
		}

		cout << "#" << z << " " << cnt << "\n";

	}
}