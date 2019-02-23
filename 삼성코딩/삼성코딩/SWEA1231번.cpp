#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

bool visited[101];
char tr[101];

void dfs(int cur) {
	if (!visited[cur])
		return;

	if (visited[cur * 2]) {
		dfs(cur * 2);
	}
	cout << tr[cur];

	if (visited[cur * 2 + 1]) {
		dfs(cur * 2 + 1);
	}
}


int main() {

	for (int z = 1; z <= 10; z++) {
		int n;
		int a;
		char b;
		int fl;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			tr[a] = b;
			visited[a] = true;
			if (n >= a * 2 + 1) {
				cin >> fl;
				cin >> fl;
			}
			else if (n == a * 2) {
				cin >> fl;
			}
		}
		cout << "#" << z << " ";
		dfs(1);
		cout << "\n";

		memset(visited, false, sizeof(visited));
		memset(tr, 0, sizeof(tr));
	}
}