#include<iostream>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) cout << " ";
		for (int j = 0; j < i + 1; j++)cout << "*";
		cout << "\n";
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < i + 1; j++) cout << " ";
		for (int j = 0; j < N - i - 1; j++)cout << "*";
		cout << "\n";
	}

}