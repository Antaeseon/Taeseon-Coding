#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<pair<int,int>>v;
int n;
bool visited[103];

void dfs(int cur, int prev) {
	if (abs(v[cur].first - v[prev].first) + abs(v[cur].second - v[prev].second) > 1000)
		return;
	if (visited[n+1])
		return;
	visited[cur] = true;
	if (cur == 0) {
		for (int i = 1; i < n + 2; i++) {
			dfs(i, 0);
		}
	}
	else {
		for (int i = 0; i < n + 2; i++) {
			if (!visited[i])
				dfs(i,cur);
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int t;
	int a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		dfs(0, 0);
		visited[n + 1] ? cout << "happy\n" : cout << "sad\n";
		memset(visited, false, sizeof(visited));
		v.clear();
	}
}