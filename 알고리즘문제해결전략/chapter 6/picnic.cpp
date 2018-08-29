#include<iostream>


using namespace std;

int n;
bool areFriends[10][10];
bool take[10];

int countPairings(bool taken[10]) {
	
	
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1)
		return 1;
	int ret = 0;
	for (int pariWith = firstFree + 1; pariWith < n; pariWith++) {
		if (!taken[pariWith] && areFriends[firstFree][pariWith]) {
			taken[firstFree] = taken[pariWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pariWith] = false;
		}
	}
	return ret;
}


int main() {
	int total;
	int num;
	int a, m;
	int c, d;
	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> a >> m;
		n = a;
		for (int j = 0; j < m; j++) {
			cin >> c >> d;
			areFriends[c][d] = true;
			areFriends[d][c] = true;
		}
		num = countPairings(take);
		cout << num << endl;
	}
	
}