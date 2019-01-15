#include<iostream>
#include<algorithm>

using namespace std;

int inp[16][2];
int n;
int maxPay = 0;

void paying(int pay, int now) {
	if (now >= n) {
		maxPay = max(maxPay, pay);
		return;
	}
	if(now+inp[now][0]<=n)
		paying(pay + inp[now][1], now + inp[now][0]);

	paying(pay, now + 1);

}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int a, b;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		inp[i][0] = a;
		inp[i][1] = b;
	}


	paying(0, 0);

	cout << maxPay << "\n";
}
