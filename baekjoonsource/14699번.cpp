#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;
int n, m;
int height[5003];
int indegree[5003];
int res[5003];
vector<int>graph[5003];



int main() {
	int a, b;
	queue<int>q;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &height[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);

		if (height[b] < height[a]) {
			graph[a].push_back(b);
			indegree[b]++;
		}
		else {
			graph[b].push_back(a);
			indegree[a]++;
		}
	}

	for(int i=1;i<=n;i++){
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next:graph[cur]) {
			indegree[next]--;
			if (indegree[next] == 0)
			{
				q.push(next);
			}
			res[next] = max(res[next], res[cur] + 1);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", res[i] + 1);
	}

}