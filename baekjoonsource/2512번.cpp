#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int>v;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n,num;
	int total;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cin >> total;
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i] < total / (n - i))
			total -= v[i];
		else
		{
			cout << total / (n - i);
			return 0;
		}
	}
	cout << v[n - 1] << "\n";

}