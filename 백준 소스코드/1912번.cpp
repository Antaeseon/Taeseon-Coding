#include<iostream>
#include<algorithm>

using namespace std;

long long sum[100005];



int main() {
	std::ios::sync_with_stdio(false);
	long long n;
	long long num;
	long long maxi=0;
	long long maxnum = -1e9;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		maxnum = max(maxnum, num);
		sum[i] = num+sum[i-1];

		if (sum[i] < 0)
			sum[i] = 0;
		maxi = max(maxi, sum[i]);

	}
	if (maxnum < 0)
		cout << maxnum;
	else
		cout << maxi << "\n";
}