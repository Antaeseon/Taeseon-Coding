#include<iostream>
#include<cmath>


using namespace std;

int col[16];
int n;
int num = 0;

bool promising(int a) {
	for (int i = 1; i < a; i++) {
		if (col[i] == col[a] || abs(col[a] - col[i]) == a - i)
			return false;
	}
	return true;
}


void backtrackting(int a) {
	if (promising(a)) {
		if (a == n)
			num++;
		else {
			for (int i = 1; i <= n; i++) {
				col[a+1] = i;
				backtrackting(a + 1);
			}
		}
	}
}


int main() {
	cin >> n;
	backtrackting(0);
	cout << num << endl;
}