#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	string a;
	for (int z = 1; z <= 10; z++) {
		cin >> n;
		cin >> a;
		vector<char>v;	

		for (int i = 0; i < n; i++) {
			if (v.size() == 0) {
				v.push_back(a[i]);
				continue;
			}
			if (a[i] == ')'&&v[v.size()-1]=='(') {
				v.pop_back();
			}
			else if (a[i] == ']'&&v[v.size() - 1] == '[') {
				v.pop_back();
			}
			else if (a[i] == '>'&&v[v.size() - 1] == '<') {
				v.pop_back();
			}
			else if (a[i] == '}'&&v[v.size() - 1] == '{') {
				v.pop_back();
			}
			else
				v.push_back(a[i]);
		}

		v.size() > 0 ? cout << "#" << z << " 0\n" : cout << "#" << z << " 1\n";


	}
}