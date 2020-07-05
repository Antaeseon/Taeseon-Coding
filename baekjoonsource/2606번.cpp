#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int visited[103];

int main() {
	vector<vector<int>> graph;
	queue<int>q;
	int n;
	int k;
	int num = 0;
	int a, b;
	cin >> n >> k;
	graph.resize(n+1);

	for(int i=0;i<k;i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (visited[next] == 0) {
				q.push(next);
				num++;
				visited[next] = 1;
			}
		}
	}
	cout << num << endl;
}
