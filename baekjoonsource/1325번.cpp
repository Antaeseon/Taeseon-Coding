#include<iostream>
#include<vector>

using namespace std;

int visited[10001];
int hacking[10001];
int cnt = 0;
vector<int>graph[10001];


void dfs(int node) {
	visited[node] = 1;
	cnt++;

	for (int i = 0; i < graph[node].size(); i++) {
		int nextnode = graph[node][i];
		if (visited[nextnode])
			continue;
		visited[nextnode] = 1;
		dfs(nextnode);
	}
}



int main() {

	std::ios::sync_with_stdio(false),cin.tie(0);
	int n, m;
	int a, b;
	int maximum = 0;
	cin >> n>> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int i = 0; i < 10001; i++)
			visited[i] = 0;
		dfs(i);
		if (cnt > maximum)
			maximum = cnt;
		hacking[i] = cnt;
	}

	for(int i=1;i<=n;i++){
		if (hacking[i] == maximum) {
			cout<< i<<" ";
		}
	}


}