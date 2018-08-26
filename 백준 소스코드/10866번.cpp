#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	int arr[1003];
	int num;
	int inp;
	queue<int> q;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M-1; j++) {
			num = q.front();
			q.pop();
			q.push(num);
		}
		num = q.front();
		q.pop();
		arr[i] = num;
	}

	cout << "<";

	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			cout << arr[i];
		}
		else {
			cout << arr[i] << ", ";
		}
	}
	cout << ">";

}