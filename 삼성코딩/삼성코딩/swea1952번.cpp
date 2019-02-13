#include<iostream>
#include<algorithm>

using namespace std;

int price[4];
int month[12];
int result = 1e9;

void dfs(int cur, int fare) {
	if (cur > 11) {
		result = min(result, fare);
		return;
	}
	if (fare > result)
		return;
	else {
		int day1 = month[cur] * price[0];
		int month1 = price[1];
		int month3 = price[2];
		if (day1 < month1)
			dfs(cur + 1, fare + day1);
		else
			dfs(cur + 1, fare + month1);
		dfs(cur + 3, fare + month3);
	}
}

int main() {
	int testCase;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		
		for (int i = 0; i < 4; i++) {
			cin >> price[i];
		}

		for (int i = 0; i < 12; i++) {
			cin >> month[i];
		}
		dfs(0, 0);

		if (result < price[3])
			cout << "#" << z << " " << result << "\n";
		else
			cout << "#" << z << " " << price[3] << "\n";



		result = 1e9;


	}


}