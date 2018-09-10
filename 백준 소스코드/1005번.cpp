#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main() {
	int n;


	scanf("%d", &n);
	int a, b;
	while (n--) {
		int tm, edge, w;
		queue<int>q;
		vector<int>graph[1004];
		int time[1005] = { 0 };
		int pre[1004] = { 0 };
		int result[1003] = { 0 };
		scanf("%d %d", &tm, &edge);
		for (int i = 1; i <= tm; i++) {
			scanf("%d", &time[i]);
		}
		for (int i = 0; i < edge; i++) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			pre[b]++;
		}

		scanf("%d", &w);

		for (int i = 1; i <= tm; i++) {
			if (!pre[i])
				q.push(i);
		}

		while (pre[w] > 0) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i];
				result[next] = max(result[next], result[cur] + time[cur]);
				if (--pre[next] == 0)
					q.push(next);
			}
		}

		printf("%d\n", result[w] + time[w]);


	}
}