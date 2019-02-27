#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
deque<int>dq[5];
bool visited[5];

void rotate(int cur, int dir) {
	if (dir == 0)
		return;
	else if (dir == 1) { //시계방향
		int temp = dq[cur].back();
		dq[cur].pop_back();
		dq[cur].push_front(temp);
	}
	else {
		int temp = dq[cur].front();
		dq[cur].pop_front();
		dq[cur].push_back(temp);
	}
}

void gear(int cur, int dir) {
	if (visited[cur])
		return;
	visited[cur] = true;
	if (cur > 1) { //왼쪽으로
		if (dq[cur][6] != dq[cur - 1][2]) {
			gear(cur - 1, (dir*(-1)));
		}
		else
			gear(cur - 1, 0);
	}
	else if (cur < 4) { //오른쪽으로
		if (dq[cur][2] != dq[cur + 1][6]) {
			gear(cur + 1, (dir*(-1)));
		}
		else
			gear(cur + 1, 0);
	}
	rotate(cur, dir);
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int inp;
	int  k;
	int a, b;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> k;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> inp;
				dq[i].push_back(inp);
			}
		}
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			memset(visited, false, sizeof(visited));
			gear(a, b);
		}
		int sum = 0;
		int tt = 1;
		for (int i = 1; i <= 4; i++) {
			if (dq[i][0] == 0) {
				sum += tt;
			}
			tt *= 2;
		}

		cout << "#" << z << " " << sum << "\n";

		for (int i = 0; i <= 4; i++)
			dq[i].clear();
	}
}