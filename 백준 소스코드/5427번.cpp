#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
char map[1002][1002];
bool visited[1002][1002] = { 0, };

struct node {
	int y;
	int x;
	int cnt=0;
};

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int w, h;
	cin >> testCase;
	while (testCase--) {
		cin >> w >> h;
		queue<node>person;
		queue<node>fire;
		bool success = false;
		node pn;
		node fn;
		for (int i = 0; i <= h; i++) {
			for (int j = 0; j <= w; j++)
				visited[i][j] = false;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@')
				{
					pn.y = i;
					pn.x = j;
					visited[i][j] = true;
					person.push(pn);
				}
				if (map[i][j] == '*')
				{
					fn.y = i;
					fn.x = j;
					visited[i][j] = true;
					fire.push(fn);
				}
			}
		}

		while (!person.empty()) {

			int fireSize = fire.size();

			for (int i = 0; i < fireSize; i++) {
				for (int j = 0; j < 4; j++) {
					fn.y= fire.front().y + dy[j];
					fn.x = fire.front().x + dx[j];
					if (fn.y < 0 || fn.y >= h || fn.x < 0 || fn.x >= w)
						continue;

					if (map[fn.y][fn.x] == '.' && !visited[fn.y][fn.x]) {
						map[fn.y][fn.x] = '*';
						visited[fn.y][fn.x] = true;
						fire.push(fn);
					}
					if (map[fn.y][fn.x] == '@'&&visited[fn.y][fn.x])
					{
						map[fn.y][fn.x] = '*';
						visited[fn.y][fn.x] = true;
						fire.push(fn);
					}
				}
				fire.pop();
			}

			int personSize = person.size();
			int tempCnt = person.front().cnt;
			for (int i = 0; i < personSize; i++) {
				if (person.front().y == 0 || person.front().y == h - 1 || person.front().x == 0 || person.front().x == w - 1) {
					cout << tempCnt + 1 << "\n";
					success = true;
					break;
				}

				for (int j = 0; j < 4; j++) {
					pn.y = person.front().y + dy[j];
					pn.x = person.front().x + dx[j];
					pn.cnt = tempCnt + 1;
					if (pn.y < 0 || pn.y >= h || pn.x < 0 || pn.x >= w)
						continue;

					if (map[pn.y][pn.x] == '.' && !visited[pn.y][pn.x]) {
						pn.cnt = person.front().cnt + 1;
						map[pn.y][pn.x] = '@';
						visited[pn.y][pn.x] = true;
						person.push(pn);
					}
				}
				person.pop();
			}
			if (success)
				break;
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
					cout << map[i][j];
				cout << "\n";
			}
		}


		if (!success)
			cout << "IMPOSSIBLE" << "\n";
	}

}