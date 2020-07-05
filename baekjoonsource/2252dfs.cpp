#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<int>ans;
int visited[32003];

void dfs(int here) {
	if (visited[here] == 1)
		return;

	visited[here] = 1;

	for (int i = 0; i<graph[here].size(); i++) {
		int there = graph[here][i];
		dfs(there);
	}

	ans.push_back(here);
}



int main() {
	int n, m;
	int a, b;
	cin >> n >> m;

	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}



	for (int i = 1; i <= n; i++) {
		dfs(i);
	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}