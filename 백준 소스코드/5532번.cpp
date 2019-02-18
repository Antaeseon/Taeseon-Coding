#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int maxA, maxB;
	if (a%c != 0) {
		maxA = a / c + 1;
	}
	else
		maxA = a / c;

	if (b%d != 0) {
		maxB = b / d + 1;
	}
	else
		maxB = b / d;

	cout << l - max(maxA, maxB) << "\n";

}