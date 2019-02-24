#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;

vector<vector<int>>map(20,vector<int>(20,0));
int minimum = 1e9;
int n, w, h;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


struct node {
	int y;
	int x;
	int num;
};



void dfs(int cur,int xLine,vector<vector<int>>v) {
	queue<node>q;
	node N;
	int cy;
	for (int i = 0; i <= h; i++) {
		if (i == h)
			return;

		if (v[i][xLine] != 0) {
			N.y = i;
			N.x = xLine;
			N.num = v[i][xLine];
			v[i][xLine] = 0;
			q.push(N);
			break;
		}
	}

	while (!q.empty()) {
		int yy = q.front().y;
		int xx = q.front().x;
		int nnum = q.front().num;
		q.pop();
		for (int i = 1; i < nnum; i++) {
			for (int j = 0; j < 4; j++) {
				int nextY = yy + i * dy[j];
				int nextX = xx + i * dx[j];
				if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w)
					continue;
				if (v[nextY][nextX] == 1) {
					v[nextY][nextX] = 0;
				}
				else if (v[nextY][nextX] > 1) {
					v[nextY][nextX] = 0;
					N.y = nextY;
					N.x = nextX;
					N.num = v[nextY][nextX];
					q.push(N);
				}


			}
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = h - 1; j > 0; j--) {
			if (v[j][i] == 0) {
				if (v[j - 1][i] != 0) {
					swap(v[j][i], v[j - 1][i]);
					continue;
				}
				
				int temp = j-1;
				while (temp>=0&&v[temp][i] == 0) {
					temp--;
					if (temp < 0)
						break;
					if (v[temp][i] != 0) {
						swap(v[temp][i], v[j][i]);
						break;
					}
					/*
					for (int i = 0; i < w; i++)
				   {
					  for (int j = h - 1; h >= 0; h--)
					  {
						 if (map[i][j] != 0) tmp++;
						 else {
							tmp = 0;
							map[i + tmp][j] = map[i][j];
							map[i][j] = 0;
						 }
					  }
				   }
					*/

				}

			}
		}
	}
	int tnum = 0;
	if (cur == n) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (v[i][j] != 0) {
					tnum++;
				}
			}
		}
		minimum = min(minimum, tnum);

		return;
	}



	for (int i = 0; i < w; i++) {
		dfs(cur + 1, i, v);
	}


}






int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> n >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < w; i++) {
			dfs(1, i, map);
		}

		cout << "#" << z << " " << minimum << "\n";
		minimum = 1e9;

	}
}