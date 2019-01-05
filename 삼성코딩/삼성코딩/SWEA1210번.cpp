#include<iostream>


using namespace std;

int graph[102][102];

int ladder_search(int target) {
	int y = 100;
	int x = target;

	while (y != 1) {
		if (graph[y - 1][x] == 1) {
			y--;
		}
		else if(graph[y][x-1]==1){
			while (graph[y][x - 1])
				x--;
			y--;
		}
		else if (graph[y][x + 1] == 1) {
			while (graph[y][x + 1])
				x++;
			y--;
		}
	}

	return x;
}




int main() {
	int y, x;
	int target;
	int testCase;
	int cnt = 0;
	int result;
	for(int t=1;t<=10;t++){
		cin >> testCase;
		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 102; j++) {
				graph[i][j]=0;
			}
		}


		for (int i = 1; i < 101; i++) {
			for (int j = 1; j < 101; j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 1; i < 101; i++) {
			if (graph[100][i] == 2) {
				target = i;
				result = ladder_search(target);
				break;
			}
		}
		cout << "#" << testCase << " " << result << endl;;

	}

}