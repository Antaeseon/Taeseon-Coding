#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

bool chess[7][7];

int main() {
	std::ios::sync_with_stdio(false);
	string inp;
	bool flag = true;;
	vector<pair<int, int>>v;
	for (int i = 0; i < 36; i++) {
		cin >> inp;
		int y = 5-(inp[1] - '1');
		int x = inp[0] - 'A';
		v.push_back({ y,x });
	}





	chess[v[0].first][v[0].second] = true;
	for (int i = 0; i < 36; i++) {

		if (i == 35) {
			if (abs(v[i].first - v[0].first) + abs(v[i].second - v[0].second) != 3 || abs(v[i].first - v[0].first) == 0 || abs(v[i].second - v[0].second) == 0) {
				flag = false;
				break;
			}
			break;
		}
		int y = v[i].first;
		int x = v[i].second;
		int ny = v[i+1].first;
		int nx = v[i + 1].second;

		if (abs(ny - y) + abs(nx - x) != 3||abs(ny-y)==0||abs(nx-x)==0) {
			flag = false;
			break;
		}
		if (chess[ny][nx]) {
			flag = false;
			break;
		}
		chess[ny][nx] = true;

	}
	
	flag ? cout << "Valid\n" : cout << "Invalid\n";


}