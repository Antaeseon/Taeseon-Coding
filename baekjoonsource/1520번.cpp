#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
int n, m;

int map[503][503];
int visited[503][503] = { 0 };
int dp[503][503];
int wid[4] = { 0,0,1,-1 };
int hei[4] = { -1,1,0,0 };


int dfs(int h, int w) {
	if (h == n - 1 && w == m - 1)
		return 1;
	if (visited[h][w])
		return dp[h][w];

	visited[h][w] = 1;

	for (int i = 0; i < 4; i++) {
		int nh = h + hei[i];
		int nw = w + wid[i];

		if (nh<0 || nh>n - 1 && nw<0 && nw>m - 1)
			continue;
		if (map[nh][nw] >= map[h][w])
			continue;
		dp[h][w] += dfs(nh, nw);
	}

	return dp[h][w];
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", dfs(0, 0));

}