#include<iostream>
#include<stack>
#include<string>


using namespace std;

int main() {
	int sum = 0;
	string inp;
	stack<char>s;

	cin >> inp;

	for (int i = 0; i < inp.size(); i++) {
		if (inp[i] == '(') {
			s.push(inp[i]);
		}
		else if (inp[i] == ')') {
			s.pop();
			if (inp[i - 1] == '(') {
				sum += s.size();
			}
			else
				sum++;
		}
	}
	
	cout << sum << endl;
}