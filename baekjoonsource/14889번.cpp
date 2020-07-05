#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int map[23][23];
int minimum = 1e9;
int n;

void dfs(int cur,vector<int>teamA,vector<int>teamB) {
	int sumA=0, sumB=0;
	if (cur > n &&teamA.size()==n/2&&teamB.size()==n/2) {
		for (int i = 0; i < n / 2 -1; i++) {
			for (int j = i + 1;j< n / 2; j++) {
				sumA += (map[teamA[i]-1][teamA[j]-1] + map[teamA[j]-1][teamA[i]-1]);
			}
		}

		for (int i = 0; i < n / 2 - 1; i++) {
			for (int j = i + 1;j< n / 2; j++) {
				sumB += (map[teamB[i]-1][teamB[j]-1] + map[teamB[j]-1][teamB[i]-1]);
			}
		}
		minimum = min(minimum, abs(sumA - sumB));
		return;
	}
	if (teamA.size() > n / 2 || teamB.size() > n / 2)
		return;
	teamA.push_back(cur);
	dfs(cur + 1, teamA, teamB);
	teamA.pop_back();
	teamB.push_back(cur);
	dfs(cur + 1, teamA, teamB);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	vector<int>teamA;
	vector<int>teamB;


	dfs(1,teamA,teamB);

	cout << minimum << "\n";
}