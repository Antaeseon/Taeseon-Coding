#include<iostream>

using namespace std;
int k;
int visited[15];
int lotto[15];


void dfs(int here, int depth) {
	if (here==k&&depth == 6) {
		for (int i = 0; i < k; i++) {
			if (visited[i] == 1)
				cout << lotto[i] << " ";
		}
		cout << endl;
	}
	if (here == k)
		return;
	visited[here] = 1;
	dfs(here + 1, depth + 1);
	visited[here] = 0;
	dfs(here + 1, depth);
	
}


int main() {


	while (true) {
		cin >> k;
		if (k == 0) {
			return 0;
		}

		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);

	}
}