#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int dw[4] = { 1,-1,0,0 };
int dh[4] = { 0,0,1,-1 };
int map[11][11];
int visited[11][11];
struct node {
	int w;
	int h;
};
int main() {
	int num;
	node n;
	int cnt;
	vector<int>v;
	queue<node>q;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			int cnt = 1;
			if (map[i][j] == 1 && !visited[i][j])
			{
				n.h = i;
				n.w = j;
				q.push(n);
				visited[i][j] = 1;
				while (!q.empty())
				{
					int cw = q.front().w;
					int ch = q.front().h;

					for (int i = 0; i < 4; i++) {
						n.w = cw + dw[i];
						n.h = ch + dh[i];

						if (n.w<1 || n.w>num || n.h<1 || n.h>num)
							continue;

						if (map[n.h][n.w] && !visited[n.h][n.w])
						{
							visited[n.h][n.w] = 1;
							cnt++;
							q.push(n);
						}

					}
					q.pop();

				}
				v.push_back(cnt);

			}
		}

	}
	if (v.empty()) {
		cout << 0 << endl;
		return 0;
	}

	sort(v.begin(), v.end());
	for (auto num : v)
		cout << num << " ";
	return 0;
}