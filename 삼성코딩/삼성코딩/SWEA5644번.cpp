#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };

struct node {
	int ax=1;
	int ay=1;
	int asum=0;
	int by=10;
	int bx=10;
	int bsum=0;
};


struct mapnode {
	int charge;
	int chNum;
};
bool cmp(mapnode a,mapnode b) {
	return a.charge > b.charge;
};

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		vector<int>amove;
		vector<int>bmove;
		vector<mapnode>map[11][11];
		node person;
		int m, a;
		int x,y, c, p;
		int inp;
		cin >> m >> a;
		for (int i = 0; i < m; i++) {
			cin >> inp;
			amove.push_back(inp);
		}
		for (int i = 0; i < m; i++) {
			cin >> inp;
			bmove.push_back(inp);
		}
		int tempNum = 1;
		for (int i = 0; i < a; i++) {
			cin >> x >> y >> c >> p;
			for (int q = x - c; q <= x + c; q++) {
				for (int w = y - c; w <= y + c; w++) {
					if (q < 1 || q>10 || w < 1 || w>10)
						continue;
					if (abs(x - q) + abs(y - w) > c)
						continue;
					map[q][w].push_back({ p,tempNum++ });
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				if (map[i][j].size() == 0)
					continue;
				sort(map[i][j].begin(), map[i][j].end(),cmp);
			}
		}
		for (int i = 0; i <= m; i++) {
			if ((map[person.ax][person.ay].size() != 0 && map[person.bx][person.by].size() != 0 && (map[person.ax][person.ay][0].chNum == map[person.bx][person.by][0].chNum))) {
				int temp1 = map[person.ax][person.ay][0].charge;
				int temp2 = -1;
				int temp3 = -1;
				int index = 1;
				int maximum = temp1;
				if (map[person.ax][person.ay].size() > 1) {
					temp2 = map[person.bx][person.by][0].charge + map[person.ax][person.ay][1].charge;
				}
				if (map[person.bx][person.by].size() > 1)
					temp3 = map[person.ax][person.ay][0].charge + map[person.bx][person.by][1].charge;
				if (maximum < temp2) {
					maximum = temp2;
					index = 2;
				}
				if (maximum < temp3)
				{
					maximum = temp3;
					index = 3;
				}

				if (index == 1) {
					person.asum += temp1 / 2;
					person.bsum += temp1 / 2;
				}
				else if (index == 2) {
					person.asum += map[person.ax][person.ay][1].charge;
					person.bsum += map[person.bx][person.by][0].charge;
				}
				else {
					person.asum += map[person.ax][person.ay][0].charge;
					person.bsum += map[person.bx][person.by][1].charge;
				}
			}
			else {
				if (map[person.ax][person.ay].size() != 0)
					person.asum += map[person.ax][person.ay][0].charge;
				if (map[person.bx][person.by].size() != 0)
					person.bsum += map[person.bx][person.by][0].charge;
			}
			if (i == m)
				break;

			person.ax += dx[amove[i]];
			person.ay += dy[amove[i]];
			person.bx += dx[bmove[i]];
			person.by += dy[bmove[i]];

		}

		cout << "#" << z << " " << person.asum + person.bsum << "\n";

	}
}