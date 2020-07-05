#include<iostream>
#include<vector>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	vector<int>arr;
	int n,s;
	int inp;
	int sum;
	int ret=0;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> inp;
		arr.push_back(inp);
	}

	for (int i = 1; i < (1 <<n); i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				sum += arr[j];
			}
		}

		if (sum == s)
		{
			ret++;
		}
	}

	cout << ret << "\n";
	
}