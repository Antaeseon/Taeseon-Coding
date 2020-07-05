#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int map[1003][1003];


int main() {
	int n, m, x;
	cin >> n >> m >> x;
	int from, to, weight;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			map[i][j] = 1e9;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		map[from][to] = weight;
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		result = max(result, map[i][x] + map[x][i]);
	}

	cout << result << "\n";

}