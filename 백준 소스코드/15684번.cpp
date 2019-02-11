#include<iostream>
#include<algorithm>

using namespace std;
int n, m, h; //세로줄 가로선 개수 높이
int ladder[12][33];
int minimum = 1e9;

bool find() {
	for (int i = 1; i <= n; i++) {
		int temp = i;
		int height = 1;
		while (height<=h) {
			if (ladder[temp][height] == 1)
				temp++;
			else if (ladder[temp - 1][height] == 1)
				temp--;
			height++;
		}
		if (temp != i)
			return false;
	}
	return true;
}


void dfs(int lad,int location,int cnt) {
	if (cnt >= minimum)
		return;
	if (find()) {
		minimum = cnt;
		return;
	}
	if (cnt == 3)
		return;

	for (int i = location; i <= h; i++,lad=1) {
		for (int j = lad; j < n; j++) {
			if (ladder[j][i]) {
				j++;
				continue;
			}
			ladder[j][i] = 1;
			dfs(j + 2, i, cnt + 1);
			ladder[j][i] = 0;
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ladder[b][a] = 1; //b는 세로줄 a는 그어진 가로줄 위치 b에서 b+1로 a줄에서 그어짐
	}

	dfs(1, 1,0);
	if (minimum > 3) {
		cout << "-1\n";
	}
	else
		cout << minimum << "\n";
}