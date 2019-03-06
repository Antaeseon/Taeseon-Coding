#include<iostream>
#include<list>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	list<char>lt;
	string a;
	int n;
	char inp;
	cin >> a;
	for (int i = 0; i < a.size(); i++)
		lt.push_back(a[i]);
	cin >> n;
	auto index = lt.end();

	for (int i = 0; i < n; i++) {
		cin >> inp;
		if (inp == 'L') {
			if (index !=lt.begin())
				index--;
		}
		else if (inp == 'D') {
			if (index != lt.end())
				index++;
		}
		else if (inp == 'B') {
			if (index != lt.begin()) {
				index = lt.erase(--index);
			}
		}
		else
		{
			cin >> inp;
			lt.insert(index, inp);
		}
	}
	for (auto op:lt)
		cout << op;
}