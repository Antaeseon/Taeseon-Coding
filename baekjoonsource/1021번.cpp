#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;
int n, m;
deque<int>dq;
int storage[55];
int minimum = 1e9;

void dfs(int cur,int cnt) {
	if (dq[0] == storage[cur]) {
		dq.pop_front();
		cur++;
	}
	if (cur == m) {
		minimum =min(minimum,cnt);
		return;
	}

	deque<int>t1 = dq;
	deque<int>t2 = dq;
	int temp1 = 0;
	int temp2 = 0;
	while (storage[cur] != t1[0]) {
		int temp = t1.front();
		t1.pop_front();
		t1.push_back(temp);
		temp1++;
	}
	while (storage[cur] != t2[0]) {
		int temp = t2.back();
		t2.pop_back();
		t2.push_front(temp);
		temp2++;
	}
	
	if (temp1 < temp2) {
		dq = t1;
		dfs(cur, cnt + temp1);
	}
	else {
		dq = t2;
		dfs(cur, cnt + temp2);
	}
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++)
		cin >> storage[i];

	dfs(0, 0);

	cout << minimum << "\n";
}