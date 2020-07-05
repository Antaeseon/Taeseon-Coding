#include<iostream>


using namespace std;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);

	int N;
	cin >> N;
	
	for(int i=1;i<N;i++){
		for (int j = 0; j < i; j++) cout << "*";
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-i; j++) cout << "*";
		cout << "\n";
	}

}