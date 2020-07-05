#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<vector<int>>graph;
int visited[101];

void dfs(int cur, int flag) {
	if (visited[cur]!=0)
		return;
	visited[cur] = flag;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		dfs(next, -flag);
	}
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	int a, b;
	queue<int>q;
	vector<int>teamA;
	vector<int>teamB;
	cin >> n;
	graph.resize(n+1);
	
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			graph[i].push_back(b);
			graph[b].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		dfs(i,1);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i]==1)
			teamA.push_back(i);
		else
			teamB.push_back(i);
	}


	sort(teamA.begin(), teamA.end());
	sort(teamB.begin(), teamB.end());

	cout << teamA.size()<<"\n";
	for (int i = 0; i < teamA.size(); i++)
		cout << teamA[i] << " ";
	cout <<"\n"<< teamB.size()<<"\n";
	for (int i = 0; i < teamB.size(); i++)
		cout << teamB[i] << " ";

}