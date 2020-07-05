#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int cnt = 0;
vector<int>A;

void merge(int a, int b) {
	if (a == b)
		return;
	int mid = (a + b) / 2;
	int l = a;
	int r = mid + 1;
	int k = a;
	vector<int>temp;

	while (l <= mid && r <= b) {
		if (A[l] <= A[r])
		{
			temp.push_back(A[l++]);
		}
		else {
			cnt += (mid - l + 1);
			temp.push_back(A[r++]);
		}
		k++;
	}

	if (l <= mid) {
		for (int j = l; j <= mid; j++) {
			temp.push_back(A[j]);
		}
	}
	else {
		for (int j = r; j <= b; j++) {
			temp.push_back(A[j]);
		}
	}

	for (int i = a; i <= b; i++) {
		A[i] = temp[i - a];

	}

}

void divide(int a, int b) {
	int mid = (a + b) / 2;
	if (a < b) {
		divide(a, mid);
		divide(mid + 1, b);
		merge(a, b);
	}
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	int n;
	cin >> n;
	A.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	divide(0, n - 1);

	cout << cnt << "\n";

}