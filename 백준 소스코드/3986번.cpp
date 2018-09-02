#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;



int main() {
	int n;
	int l, r;
	int cnt = 0;
	string a;
	cin >> n;
	bool check = true;
	while (n--) {
		cin >> a;
		l = 0, r = 0;
		check = true;
		stack<char>s;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'A') {
				if (!s.empty() && s.top() == a[i])
					s.pop();
				else
					s.push(a[i]);
			}
			else {
				if (!s.empty() && s.top() == a[i])
					s.pop();
				else
					s.push(a[i]);
			}
		

		}

		if (s.empty())
			cnt++;
	}
	cout << cnt << endl;
}

