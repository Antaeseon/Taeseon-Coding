#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
int n, m;
vector<int>v;
vector<int> map[1003];
int temp[1003];
int indegree[1003];



int main() {
	int k;
	queue<int>q;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &temp[i]);
		}

		for (int i = 0; i < k - 1; i++) {
			map[temp[i]].push_back(temp[i + 1]);
			indegree[temp[i + 1]]++;
		}
	}


	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			v.push_back(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();

		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i];
			indegree[next]--;

			if (indegree[next] == 0) {
				q.push(next);
				v.push_back(next);
			}
		}

		q.pop();
	}


	if (v.size() != n) {
		printf("0\n");
		return 0;
	}


	for (int i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}


}