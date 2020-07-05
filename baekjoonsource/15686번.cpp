#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
struct node {
	int y;
	int x;
};

int map[52][52];
int dis[102][15];
int n, m;
int minimum = 1e9;
vector<node>home;
vector<node>chicken;


void dfs(int cur,vector<int>include,int size) {
	if (include.size() > m)
		return;
	if (cur == size) {
		if (include.size() < m)
			return;
		if (include.size() == m) {
			int sum = 0;
			for (int i = 0; i <home.size(); i++) {
			int tempmin = 1e9;
				for (int j = 0; j < m; j++) {
					tempmin = min(tempmin, dis[i][include[j]]);
				}
				sum += tempmin;
			}
			minimum = min(minimum, sum);
		}
		return;
	}

	include.push_back(cur);
	dfs(cur + 1, include,size);
	include.pop_back();
	dfs(cur + 1, include,size);
}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	node edge;
	vector<int>emp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				edge.y = i;
				edge.x = j;
				home.push_back(edge);
			}
			if (map[i][j] == 2) {
				edge.y = i;
				edge.x = j;
				chicken.push_back(edge);
			}
		}
	}

	for (int i = 0; i < home.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			int disY = abs(home[i].y - chicken[j].y);
			int disX = abs(home[i].x - chicken[j].x);
			dis[i][j] = disY + disX;
		}
	}

	dfs(0, emp,chicken.size());
	cout << minimum << "\n";
}