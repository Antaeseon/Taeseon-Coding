#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int N, L;
int result = 0;
int map[102][102];
int reversemap[102][102];


void check(int y) {
	bool visited[102] = { false, };
	int save = 0;
	for (int i = 0; i < N; i++) {
		if (map[y][i] != map[y][save]) {
			if (abs(map[y][i] - map[y][save]) > 1)
				return;
			else if ( map[y][i]-map[y][save] > 0) { // 오르막길
				if (i - L < 0)
					return;
				int temp = i - L;
				for (int j = i - L; j < i;j++) {
					
					if (visited[j]||map[y][temp]!=map[y][j])
						return;
					visited[j] = true;
				}
			}
			else if (map[y][i] - map[y][save] < 0) { // 내리막길
				int temp = i;
				for (int j = i; j < i + L; j++) {
					if (visited[j] || map[y][temp] != map[y][j])
						return;
					visited[j] = true;
				}
				i = i + L-1;
			}
			save = i;
		}
	}
	result++;
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			reversemap[j][i] = map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		check(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = reversemap[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		check(i);
	}

	cout << result << "\n";
	


}