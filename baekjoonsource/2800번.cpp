#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int cnt[1000005];


struct node {
	char a;
	int num = 0;
};



int main() {
	string inp;
	string bmb;
	stack<node>s;
	vector<char>v;
	cin >> inp;
	cin >> bmb;

	for (int i = 0; i < inp.size(); i++) {
		node b;
		b.a = inp[i];

		if (s.empty()) {

			if (b.a == bmb[0]) {
				b.num = 1;
			}

			if (b.num == bmb.size())
				continue;
			s.push(b);
			continue;
		}

		if (s.top().num == 0) {
			if (b.a == bmb[0]) {
				b.num = 1;
			}
		}
		else {
			if (b.a == bmb[s.top().num]) {
				b.num = s.top().num + 1;
			}
			else {
				if (b.a == bmb[0]) {
					b.num = 1;
				}
				else
					b.num = 0;
			}
		}
		s.push(b);
		if (b.num == bmb.size()) {
			int cn = b.num;
			while (cn--) {
				s.pop();
			}
		}

	}

	if (!s.empty()) {
		int che = s.size();
		for (int i = 0; i <che; i++) {

			v.push_back(s.top().a);
			s.pop();

		}
		reverse(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++)
			printf("%c", v[i]);
	}
	else {
		printf("FRULA\n");
	}
}