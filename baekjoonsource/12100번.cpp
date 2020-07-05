#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int maximum = 0;
void move(int dir,vector<vector<int>> & temp) {
	if (dir == 1) {//µ¿
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x > 0; x--) {
				if (temp[y][x] == 0) {
					int tempX = x - 1;
					while (tempX >= 0&&!temp[y][tempX])
						tempX--;
					if(tempX>=0)
						swap(temp[y][tempX], temp[y][x]);
				}
			}
		}
	}

	else if (dir == 2) {//¼­
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N-1; x++) {
				if (temp[y][x] == 0) {
					int tempX = x + 1;
					while (tempX <= N-1 && !temp[y][tempX])
						tempX++;
					if (tempX <= N-1)
						swap(temp[y][tempX], temp[y][x]);
				}
			}
		}
	}

	else if (dir == 3) {//³²
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y > 0; y--) {
				if (temp[y][x] == 0) {
					int tempY = y - 1;
					while (tempY >= 0&& !temp[tempY][x])
						tempY--;
					if (tempY >= 0)
						swap(temp[tempY][x], temp[y][x]);
				}
			}
		}
	}

	else {//ºÏ
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N-1; y++) {
				if (temp[y][x] == 0) {
					int tempY = y + 1;
					while (tempY <= N-1 && !temp[tempY][x])
						tempY++;
					if (tempY <= N-1)
						swap(temp[tempY][x], temp[y][x]);
				}
			}
		}
	}
}

void merge(int dir, vector<vector<int>> & temp) { //1 µ¿ 2 ¼­ 3 ³² 4 ºÏ
	if (dir == 1) {//µ¿
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x > 0; x--) {
				if (temp[y][x] == temp[y][x - 1])
				{
					temp[y][x] = 2 * temp[y][x - 1];
					temp[y][x - 1] = 0;

				}
			}
		}
	}
	else if (dir == 2) {//¼­
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N - 1; x++) {
				if (temp[y][x] == temp[y][x+1]) {
					temp[y][x] = 2 * temp[y][x + 1];
					temp[y][x + 1] = 0;
				}
			}
		}

	}
	else if (dir == 3) {//³²
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y > 0; y--) {
				if (temp[y][x] ==temp[y-1][x]) {
					temp[y][x] = 2*temp[y][x];
					temp[y - 1][x] = 0;
				}
			}
		}

	}
	else {//ºÏ
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N - 1; y++) {
				if (temp[y][x] == temp[y +1][x]) {
					temp[y][x] = 2 * temp[y][x];
					temp[y + 1][x] = 0;
				}
			}
		}
	}
}


void dfs(int cnt,int dir, vector<vector<int>> temp) { //1 µ¿ 2 ¼­ 3 ³² 4 ºÏ
	if (dir != 0) {
		move(dir, temp);
		merge(dir, temp);
		move(dir, temp);
	}


	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maximum = max(maximum, temp[i][j]);
			}
		}

		return;
	}


	dfs(cnt + 1, 1, temp);
	dfs(cnt + 1, 2, temp);
	dfs(cnt + 1, 3, temp);
	dfs(cnt + 1, 4, temp);

}

int main() {
	cin >> N;
	vector<vector<int> > map(21, vector<int>(21, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0, map);
	cout << maximum << "\n";
}