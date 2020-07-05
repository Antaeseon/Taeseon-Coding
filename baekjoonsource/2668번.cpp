#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;
int n;
int num[102];
bool visited[102];
vector<int>res;

void dfs(int cur) {
	int check[101] = { 0, };
	int next = cur;
	check[cur]++;

	while (1) {
		next = num[next];
		check[next]++;
		if (visited[next])
			break;

		if (check[next] > 2)
			break;
		if (check[next] == 2 && !visited[next]) {
			res.push_back(next);
			visited[next] = true;
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	
	int inp;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		dfs(i);
	}
	sort(res.begin(), res.end());

	cout << res.size() << "\n";
	for (auto op : res)
		cout << op << "\n";
}