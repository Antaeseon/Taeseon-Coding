#include<iostream>
#include<algorithm>
#include<vector>



using namespace std;
long long food[20][20];


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int n;
	long long minimum = 1e9;
	cin >> testCase;

	for (int z = 1; z <= testCase; z++) {
		cin >> n;
		minimum = 1e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> food[i][j];
			}
		}

		for (int i = 1; i < (1 << n); i++) {
			int cnt = 0;
			vector<long long>a;
			vector<long long>b;
			long long sumA = 0;
			long long sumB = 0;
			for (int j = 0; j < n; j++) {
				if (i&(1<<j)) {
					a.push_back(j);
					cnt++;
				}
				else {
					b.push_back(j);
				}
			}
			if (cnt != n / 2)
				continue;

			for (int x = 0; x < (n / 2)-1; x++) {
				for (int y = 1; y < (n / 2); y++) {
					sumA += (food[a[x]][a[y]] + food[a[y]][a[x]]);
					sumB += (food[b[x]][b[y]] + food[b[y]][b[x]]);
				}
			}

			minimum = min(minimum, abs(sumA - sumB));

		}

		cout << "#" << z << " " << minimum << "\n";

	}
	

}