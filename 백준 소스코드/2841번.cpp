#include<iostream>
#include<stack>

using namespace std;

stack<int> g[6];

int main() {
	int n, k;
	int a, b;
	int cnt = 0;
	cin >> n >> k;
	while (n--) {
		cin >> a>> b;
		if (g[a].empty()|| g[a].top() < b) {
			g[a].push(b);
			cnt++;
			continue;
		}


		if (g[a].top() > b) {
			while (!g[a].empty()&&g[a].top() >= b) {
				if (g[a].top() == b)
					break;

				g[a].pop();
				cnt++;
			}
			if (!g[a].empty()&&g[a].top() == b)
				continue;
			g[a].push(b);
			cnt++;
		}

	}
	cout << cnt << endl;

}