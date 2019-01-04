#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N - i; j++)cout << " ";
		cout << "*";
		if (i == 0) {
			cout << endl;
			continue;
		}
		for (int j = 0; j < 2 * i-1; j++)cout << " ";
		cout << "*";
		cout << endl;
	}
}