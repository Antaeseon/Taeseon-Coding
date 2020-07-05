#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

vector<vector<int>>graph;
int visited[32003];
int indegree[32003];
vector<int>res;
priority_queue< int, vector<int>, greater<int> > pq;

int main() {
	int n, m;
	int a, b;
	cin >> n >> m;

	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			pq.push(i);
	}
	
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			indegree[next]--;
			if (indegree[next] == 0)
				pq.push(next);
		}
	}

}