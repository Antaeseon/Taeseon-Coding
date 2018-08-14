#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N,M;
vector<int> graph[1003];
bool visited[1003];
bool used[1003];

void dfs(int cur) {
	printf("%d ", cur);
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (visited[next] == 0) {
			dfs(next);
		}
	}
}

void bfs(int S) {
	queue<int>q;
	q.push(S);
	used[S] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int i = 0; i <graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (used[next] == 0) {
				q.push(next);
				used[next] = true;
			}
		}
	}
}

int main() {
	int cur;
	int a, b;
	scanf("%d %d %d", &N, &M, &cur);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(cur);
	printf("\n");
	bfs(cur);
}