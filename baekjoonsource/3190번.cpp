#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int map[101][101];
int dx[4] = { 1,0,-1,0 };//동남서북
int dy[4] = { 0,1,0,-1 };

int main() {
	int n, k, l;
	vector<pair<int, int>>q;
	cin >> n;
	cin >> k;
	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> l;
	int y = 1, x = 1;
	q.push_back({ y,x });
	int cnt = 0;
	char inp;
	int move=0;
	int dir = 0;
	bool flag = false;
	int tempmove = 0;
	int index = 1;
	for (int i = 0; i <= l; i++) {
		if(i!=l)
			cin >> move >> inp;
		while (1) {
			cnt++;
			x += dx[dir];
			y += dy[dir];
			for (int k = 0; k < q.size(); k++) {
				int tempY = q[k].first;
				int tempX = q[k].second;
				if (tempY ==y&&tempX == x) {
					cout << cnt << "\n";
					return 0;
				}
			}
			if (!map[y][x]) {
				q.erase(q.begin());
			}
			else
				map[y][x] = 0;
			q.push_back({ y,x });

			if (y <= 0 || y > n || x <= 0 || x > n) {
				cout << cnt << "\n";
				return 0;
			}
			index++;
			if (index-1 == move)
				break;
		}
	
		if (inp == 'D') { //오른쪽
			dir = (dir + 1) % 4;
		}
		else {
			if (dir == 0)
				dir = 3;
			else
				dir = (dir - 1) % 4;
		}
	}


}