#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n, m;
int a, b;
queue<int>q;
vector<int>ans;
vector<vector<int>> graph;
int indegree[32003];

void bfs() {
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	}

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			indegree[next]--;

			if (indegree[next] == 0) {
				q.push(next);
				ans.push_back(next);
			}

		}
	}
}



int main() {

	cin >> n >> m;
	graph.resize(n + 1);

	bfs();
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<<" ";
	}

}