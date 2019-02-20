#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>

using namespace std;
int map[12][12];
int res[12][12];
bool visited[12][12];
int maximum = 0;
int N, M, C; // 크기 벌통개수 최대 양 

void dfs(int y, int x, int plus,int sum,int ssum) {
	if (plus == M) {
		maximum = max(maximum, ssum);
		return;
	}

	if (sum + map[y][x + plus] <= C) {
		dfs(y, x, plus + 1, sum + map[y][x + plus], ssum + map[y][x + plus] * map[y][x + plus]);
		dfs(y, x, plus + 1, sum, ssum);
	}
	else {
		dfs(y, x, plus + 1, sum, ssum);
	}



}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int tmaximum = 0;
	int ty;
	int tx;
	cin >> testCase;

	for (int z = 1; z <= testCase; z++) {
		cin >> N >> M >> C;
		tmaximum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				int sum = 0;
				int ssum = 0;
				for (int k = j; k < j + M; k++) {
					sum += map[i][k];
					ssum += map[i][k] * map[i][k];
				}

				if (sum <= C) {
					res[i][j] = ssum;
					if (ssum > tmaximum) {
						tmaximum = ssum;
						ty = i;
						tx = j;
					}

				}
				else {
					maximum = 0;
					dfs(i, j, 0, 0,0);
					res[i][j] = maximum;
					if (maximum > tmaximum) {
						tmaximum = maximum;
						ty = i;
						tx = j;
					}
				}


			}
		}

		int smaximum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				if (i == ty && tx - M < j&&j < tx + 1)
					continue;
				smaximum = max(smaximum, res[i][j]);
			}
		}


		cout << "#" << z << " " << tmaximum + smaximum << "\n";


	}
}