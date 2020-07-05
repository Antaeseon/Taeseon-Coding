#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>


using namespace std;
int A[11][11]; //추가되는 양분의 양
int B[11][11]; //전체 양분

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

struct node {
	int y;
	int x;
	int age;
};
int n, m, k;
bool cmp(node a, node b) {
	return a.age < b.age;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0); //봄에는 나이만큼 양분먹고 나이 1 증가, 양분 부족하면 죽는다. 여름에는 죽은나무 나이/2만큼 양분증가
												  //가을에는 나무 번식 5의배수일때만 주변에 1짜리 나무가 생김 겨울에는 A만큼 양분 추가
	node tree;
	vector<int>forest[11][11];
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			B[i][j] = 5;
		}
	}
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	int a,b,c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		forest[a][b].push_back(c);
	}


	while (k--) {
		int summer[11][11] = { 0, };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (forest[i][j].size()) {
					sort(forest[i][j].begin(), forest[i][j].end());
					for (int z = 0; z < forest[i][j].size(); z++) {
						if (B[i][j] >= forest[i][j][z]) {
							B[i][j] -= forest[i][j][z];
							forest[i][j][z] += 1;
						}
						else {
							summer[i][j] += (forest[i][j][z] / 2);
							forest[i][j].erase(forest[i][j].begin() + z);
							z--;
						}
					}
				}
			}
		}

		/*for (int i = 0; i < forest.size(); i++) {
			int fy = forest[i].y;
			int fx = forest[i].x;
			int fage = forest[i].age;
			if (B[fy][fx] >= fage) {
				B[fy][fx] -= fage;
				forest[i].age = fage+1;
			}
			else {
				summer[fy][fx] += (fage / 2);
				forest.erase(forest.begin() + i);
				i--;
			}
		}*/

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				B[i][j] += summer[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (forest[i][j].size()) {
					for (int z = 0; z < forest[i][j].size(); z++) {
						if (forest[i][j][z] % 5)
							continue;
						for (int kk = 0; kk < 8; kk++) {
							int nextY = i + dy[kk];
							int nextX = j + dx[kk];

							if (nextY >= 1 && nextY <= n && nextX >= 1 && nextX <= n) {
								forest[nextY][nextX].push_back(1);
							}
						}
					}
				}
			}
		}

		/*int tempSize = forest.size();
		for (int i = 0; i < tempSize; i++) {
			if (forest[i].age % 5 == 0) {
				int fy = forest[i].y;
				int fx = forest[i].x;
				for (int height = fy - 1; height < fy + 2; height++) {
					for (int width = fx - 1; width < fx + 2; width++) {
						if (height == fy && width == fx)
							continue;
						if (height >= 1 && height <= n && width >= 1 && width <= n) {
							tree.y = height;
							tree.x = width;
							tree.age = 1;
							forest.push_back(tree);
						}
					}
				}
			}
		}*/
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				B[i][j] += A[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += forest[i][j].size();
		}
	}

	cout << ans << "\n";
}