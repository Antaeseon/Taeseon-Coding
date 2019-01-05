#include<iostream>


using namespace std;

int graph[102][102];

int ladder_search(int target) {
	int y = 1;
	int x = target;
	int cnt = 0;
	while (y != 100) {
		if (graph[y][x - 1] == 1) {
			while (graph[y][x - 1]) {
				cnt++;
				x--;
			}
			cnt++;
			y++;
		}
		else if (graph[y][x + 1] == 1) {
			while (graph[y][x + 1])
			{
				cnt++;
				x++;
			}
			cnt++;
			y++;
		}
		else {
			cnt++;
			y++;
		}
	}

	return cnt;
}




int main() {
	int y, x;
	int target;
	int testCase;
	int cnt = 0;
	int result;
	int minimum;
	int index;
	for (int t = 1; t <= 10; t++) {
		cin >> testCase;
		minimum = 1e9;
		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 102; j++) {
				graph[i][j] = 0;
			}
		}


		for (int i = 1; i < 101; i++) {
			for (int j = 1; j < 101; j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 1; i < 101; i++) {
			if (graph[1][i] == 1) {
				target = i;
				result = ladder_search(target);
				if (minimum > result) {

					minimum = result;
					index = i;
				}

			}
		}
		cout << "#" << testCase << " " << index-1 << endl;;

	}

}