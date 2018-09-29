#include <iostream>
#include <vector>
using namespace std;

int main() {
	int c, p, n;
	int rem;
	int tt = 0;
	vector<int>v;
	cin >> c >> p;
	rem = c;
	for (int i = 0; i < c; i++)
		v.push_back(i + 1);
	
	while (p--) {
		cin >> n;
		rem = c;
		tt = 0;
		while (rem > n + n) {
			rem = rem - 2 * n;
			for (int i = 0; i < n; i++) {
				int ins = v.front();
				v.erase(v.begin());
				v.insert(v.end() - n -tt, ins);
			}
			tt = n + n;

		}
	}

	for (int i=0;i<5;i++)
		cout << v[i] << endl;


	return 0;
}