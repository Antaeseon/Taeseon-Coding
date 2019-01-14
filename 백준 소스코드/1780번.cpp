#include<iostream>


using namespace std;

int paper[2200][2200];
int result[3];

void paperNum(int y, int x, int num) {
	int nextNum = num / 3;
	for (int i = y; i < y+num; i++) {
		for (int j = x; j < x+num; j++) {
			if (paper[y][x] != paper[i][j]) {
				for (int k = 0; k < 3; k++) 
					for(int l=0;l<3;l++) paperNum(y + k * nextNum, x + l * nextNum, nextNum);
				return;
			}

		}
	}
	result[paper[y][x]+1]++;
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}

	paperNum(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << "\n";
	}
}