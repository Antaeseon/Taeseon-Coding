#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstring>

using namespace std;

vector<vector<pair<int,int>>>graph;
int d[20002];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int V, E;
	int K;
	int u, v, w;
	cin >> V >> E;
	cin >> K;
	graph.resize(V + 1);
	memset(d, -1, sizeof(d));

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,K });

	while (pq.size()) {
		int now = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();

		if (d[now] != -1)
			continue;
		d[now] = weight;
		for (auto ii : graph[now]) {
			int next = ii.first;
			int nweight = -ii.second- weight;
			if (d[next] != -1)
				continue;
			pq.push({ nweight,next });
		}

	}

	for (int i = 1; i <= V; i++) {
		if (d[i] == -1)
			cout << "INF\n";
		else {
			cout << d[i] << "\n";
		}
	}


}