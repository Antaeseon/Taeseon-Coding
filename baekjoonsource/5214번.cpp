#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
vector<vector<int>>graph;
bool visited[111111];

struct node {
	int cur;
	int cnt;
};

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n, k, m;
	queue<node>q;
	cin >> n >> k >> m;
	int num;
	int inp;
	int res;



	graph.resize(n + m + 1);
	for (int i = n+1; i < n+m+1; i++) {
		for (int j = 0; j < k; j++) {
			cin >> inp;
			graph[i].push_back(inp);
			graph[inp].push_back(i);
		}
	}
	if (n == 1)
	{
		cout << "1\n";
		return 0;
	}

	visited[1] = true;
	q.push({ 1,0 });

	while (!q.empty()) {
		int tempCur = q.front().cur;
		int tempCnt = q.front().cnt;
		q.pop();


		for (int i = 0; i < graph[tempCur].size(); i++) {
			int next = graph[tempCur][i];
			
			if (visited[next])
				continue;
			if (n!=1&&next == n) {
				cout << (tempCnt+1)/2+1 << "\n";
				return 0;
			}
			visited[next] = true;
			q.push({ next,tempCnt + 1 });
		}
	}

	
	cout << "-1\n";
}