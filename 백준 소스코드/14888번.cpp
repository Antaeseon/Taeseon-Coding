#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int num[102];
int oper[4];
long long maximum = -1e9;
long long minimum = 1e9;
int n;

int calc(int a, int b, int op) {
	if (op == 0) {
		return a + b;
	}
	else if (op == 1) {
		return a - b;
	}
	else if (op == 2) {
		return a * b;
	}
	else {
		if (a < 0) {
			int res;
			a = abs(a);
			res = a / b;
			return -res;
		}
		else {
			return a / b;
		}
	}

}



void dfs(int cur, int op,long long sum)
{
	int temp;
	if (cur == n - 1) {
		maximum = max(maximum, sum);
		minimum = min(minimum, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			temp= calc(sum, num[cur + 1], i);
			dfs(cur + 1, i,temp);
			oper[i]++;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	dfs(0, 0,num[0]);

	cout << maximum << "\n";
	cout << minimum<< "\n";

}