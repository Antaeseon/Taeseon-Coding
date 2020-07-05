#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int>v;

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	int num;
	int minimum=1e9;
	int ti;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(),cmp);
	
	for (int i = 0; i < n-1; i++) {
		if (minimum > abs(v[i] + v[i + 1])) {
			minimum = abs(v[i] + v[i + 1]);
			ti = i;
		}
	}
	if(v[ti]<v[ti+1])
		cout << v[ti] << " " << v[ti + 1];
	else
		cout << v[ti+1] << " " << v[ti];


	//cout << v[ti] << " " << v[tj] << "\n";
}