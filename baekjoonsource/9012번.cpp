#include<iostream>
#include<string>
#include<stack>



using namespace std;


bool checking(string str) {
	stack <int> s;
	int len = str.size();
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else {
			if (!s.empty()) {
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	if (!s.empty())
		return false;

	return true;
	
}



int main() {
	string inp;
	string out;
	bool ch;
	int num;
	cin >> num;
	while (num--) {
		cin >> inp;
		ch = checking(inp);
		if (ch)
			out = "YES";
		else
			out = "NO";
		cout << out << endl;

	}
}