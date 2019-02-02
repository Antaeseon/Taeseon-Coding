#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<deque>
#include<cstring>

using namespace std;
deque<int>dq[5];
bool visited[5];


void rotate(int num,int dir) {
	if (dir == 1) {
		int temp = dq[num].back();
		dq[num].pop_back();
		dq[num].push_front(temp);
	}
	else {
		int temp = dq[num].front();
		dq[num].pop_front();
		dq[num].push_back(temp);
	}
}

void gear(int num, int dir) {
	visited[num] = true;

	if (num - 1 > 0 && !visited[num - 1]) {
		if (dq[num - 1][2] != dq[num][6]) {
			gear(num - 1, dir*-1);
		}
	}

	if (num + 1 < 5 && !visited[num + 1]) {
		if (dq[num][2] != dq[num+1][6]) {
			gear(num + 1, dir*-1);
		}
	}

	rotate(num, dir);
}




int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int sum = 0;
	string inp;
	for (int i = 1; i <= 4; i++) {
		cin >> inp;
		for (int j= 0; j < 8; j++) {
			dq[i].push_back(inp[j] - '0');
		}
	}
	int n;
	cin >> n;
	int top, dir;
	while (n--) {
		cin >> top >> dir;
		memset(visited, false, sizeof(visited));
		gear(top, dir);
	}
	int temp = 1;
	for (int i = 1; i <= 4; i++) {
		sum += dq[i][0]*temp;
		temp *=2;
	}
	cout << sum << "\n";
}
