#include<iostream>
#include<stack>
#include<string>

using namespace std;
stack <int> s;



int main() {
	int num;
	int st;
	string inp;
	cin >> num;

	while (num--) {
		cin >> inp;

		if (inp == "push") {
			cin >> st;
			s.push(st);
		}
		else if (inp == "pop") {
			if (!s.empty()) {
				st = s.top();
				s.pop();
				cout << st << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (inp == "size") {
			cout << s.size();
		}
		else if (inp == "empty") {
			cout << s.empty()<<endl;
		}
		else if (inp == "top") {
			if (!s.empty()) {
				cout << s.top() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
	}
	
}