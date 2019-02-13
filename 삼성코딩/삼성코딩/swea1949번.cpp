#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int map[10][10];
bool visited[10][10];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n;
int k;
int result = 0;



void dfs(int y, int x, int cnt,int ternel,bool chk) {
	result = max(result, cnt);
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
			continue;
		if (!visited[nextY][nextX]) {
			visited[nextY][nextX] = true;
			if (map[nextY][nextX] < map[y][x]) {
				dfs(nextY, nextX, cnt + 1, ternel,chk);
			}
			
			int drill = map[nextY][nextX] - map[y][x] + 1;
			if (drill <= ternel&&drill<=5&&drill>=1&&!chk) {
				map[nextY][nextX]--;
				dfs(nextY, nextX, cnt + 1, ternel-drill,true);
				map[nextY][nextX]++;
			}
			visited[nextY][nextX] = false;
		}
	}
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	cin >> testCase;
	for(int z=1;z<=testCase;z++) {
		cin >> n >> k;;
		int maxHeight=0;
		result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				maxHeight = max(maxHeight, map[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maxHeight) {
					visited[i][j] = true;
					dfs(i, j, 1, k,false);
					memset(visited, false, sizeof(visited));
				}
			}
		}
		cout << "#" << z << " " << result<<"\n";
	}

}