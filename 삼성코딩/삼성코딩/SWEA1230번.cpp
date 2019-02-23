#include<iostream>
#include<vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	int inp;
	char a;
	int x, y;
	for (int z = 1; z <= 10; z++) {
		vector<int>v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> inp;
			v.push_back(inp);
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == 'I') {
				for (int j = 0; j < y; j++) {
					cin >> inp;
					v.insert(v.begin() + x + j, inp);
				}
			}
			else if (a == 'D') {
				cin >> x >> y;
				v.erase(v.begin() + x, v.begin() + x + y);
			}
			else {
				cin >> y;
				for (int i = 0; i < y; i++) {
					cin >> inp;
					v.push_back(inp);
				}
			}
		}
		cout << "#" << z << " ";
		for (int i = 0; i < 10; i++) {
			if (i == 9) {
				cout << v[i] << "\n";
				break;

			}
			cout << v[i] << " ";
		}
	}
}
