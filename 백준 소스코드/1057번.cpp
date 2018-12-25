#include<iostream>
#include<algorithm>


using namespace std;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int cnt = 0;
	int n, a, b;
	cin >> n >> a >> b;
	
	while (1) {
		if (a == b)
			break;
		a= (a+1)/ 2;
		b = (b + 1) / 2;
		cnt++;
	}
	
	cout << cnt << "\n";

}	