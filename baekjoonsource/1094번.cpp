#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	int cnt = 0;
	int stick = 64;
	int target;

	cin >> target;

	while (target) {
		if (target < stick) {
			stick /= 2;
		}
		else {
			target -= stick;
			stick /= 2;
			cnt++;

		}

	}

	cout << cnt << "\n";
}