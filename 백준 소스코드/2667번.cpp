#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char graph[30][30];
int visited[30][30];
int visitnum[100];
vector<int>answer;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int num = 0;
int n;
vector<int>v;

void dfs(int a,int b) {
	visited[a][b] = 1;
	visitnum[num]++;
	int tempa, tempb;
	for (int i = 0; i < 4; i++) {
		tempa = a + dx[i];
		tempb = b + dy[i];

		if (tempa >= 0 && tempa < n&&tempb >= 0 && tempb < n
			&&visited[tempa][tempb] == 0 && graph[tempa][tempb] == '1') {
			visited[tempa][tempb] = 1;
			dfs(tempa, tempb);
		}
	}
}


int main() {
	cin >>n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == '1' && visited[i][j] == 0) {
				num++;
				v.push_back(0);
				dfs(i, j);
			}
		}
	}

	cout << num << endl;
	for (int i = 1; i <=num; i++) {
		answer.push_back(visitnum[i]);
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < num; i++) {
		cout << answer[i] << endl;
	}
}