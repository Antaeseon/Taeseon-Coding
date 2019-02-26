#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int map[30][30];
int rmap[30][30];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n, k;
	int testCase;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				rmap[j][i] = map[i][j];
			}
		int cnt = 0;

		//°Á¸Ê
		for (int i = 0; i < n; i++) {
			bool visited[30] = { false, };
			bool flag = true;
			int tmp = map[i][0];
			for (int j = 1; j < n; j++) {
				if (abs(tmp - map[i][j]) > 1)
				{
					flag = false;
					break;
				}
				if (map[i][j] > tmp) {
					if (j - k < 0) {
						flag = false;
						break;
					}
					for (int x = j - k; x < j; x++) {
						if (visited[x]) {
							flag = false;
							break;
						}
						visited[x] = true;
						if (map[i][x] != tmp)
						{
							flag = false;
							break;
						}
					}
					tmp++;
				}
				else if (map[i][j] < tmp) {
					if (j + k >= n) {
						flag = false;
						break;
					}
					for (int x = j ; x < j+k; x++) {
						if (visited[x]) {
							flag = false;
							break;
						}
						visited[x] = true;
						if (map[i][x] != tmp - 1)
						{
							flag = false;
							break;
						}
					}
					j += (k-1);
					tmp--;
				}
				if (!flag)
					break;
			}
			if (flag)
				cnt++;
		}
		//°Á¸Ê

		//¸®¸Ê
		for (int i = 0; i < n; i++) {
			bool visited[30] = { false, };
			bool flag = true;
			int tmp = rmap[i][0];
			for (int j = 1; j < n; j++) {
				if (abs(tmp - rmap[i][j]) > 1)
				{
					flag = false;
					break;
				}
				if (rmap[i][j] > tmp) {
					if (j - k < 0) {
						flag = false;
						break;
					}
					for (int x = j - k; x < j; x++) {
						if (visited[x]) {
							flag = false;
							break;
						}
						visited[x] = true;
						if (rmap[i][x] != tmp)
						{
							flag = false;
							break;
						}
					}
					tmp++;
				}
				else if (rmap[i][j] < tmp) {
					if (j + k >= n) {
						flag = false;
						break;
					}
					for (int x = j ; x < j+k; x++) {
						if (visited[x]) {
							flag = false;
							break;
						}
						visited[x] = true;
						if (rmap[i][x] != tmp - 1)
						{
							flag = false;
							break;
						}
					}
					j += (k-1);
					tmp--;
				}
				if (!flag)
					break;
			}
			if (flag)
				cnt++;
		}
		//¸®¸Ê

		cout << "#" << z << " " << cnt << "\n";

	}

}