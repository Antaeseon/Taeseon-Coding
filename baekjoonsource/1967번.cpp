#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


int res = 0;
int endP=0;
bool visited[10003];
vector<vector<pair<int, int>>>tr;

void dfs(int cur, int length) {
	if (visited[cur])
		return;
	visited[cur] = true;

	if (res < length) {
		res = length;
		endP = cur;
	}

	for (int i = 0; i < tr[cur].size();i++) {
		dfs(tr[cur][i].first, tr[cur][i].second + length);
	}
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);

	int num;
	int a, b, w;
	cin >> num;
	tr.resize(num + 1);
	for (int i = 0; i < num - 1; i++) {
		cin >> a >> b >> w;
		tr[a].push_back({ b,w });
		tr[b].push_back({ a,w });
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));

	res = 0;
	dfs(endP, 0);

	cout << res << "\n";
}