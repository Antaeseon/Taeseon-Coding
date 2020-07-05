#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

vector<vector<int>>graph;
priority_queue<pair<int, int>>pq;
int dis[10001] = { -1, };
int n;

void init(int num, int bridge) {
	for (int i = num + bridge; i <= n; i += bridge) {
		graph[num].push_back(i);
	}
	for (int i = num - bridge; i >= 1; i -= bridge) {
		graph[num].push_back(i);
	}

}




int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	graph.resize(n + 1);
	int inp;
	int start, finish;
	for (int i = 1; i <= n; i++) {
		cin >> inp;
		init(i, inp);
	}
	cin >> start >> finish;

	pq.push({ 0,start });
	memset(dis, -1, sizeof(dis));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dis[cur] != -1)
			continue;
		dis[cur] = cost;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (dis[next] != -1)
				continue;
			pq.push({ -1 - cost,next });
		}
	}

	cout << dis[finish] << "\n";

}


