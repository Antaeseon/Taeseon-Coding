#include<iostream>
#include<stack>
#include<string>


using namespace std;



int main() {
	string inp;
	int temp=0;
	int sum = 0;
	int mul = 1;
	//int a = 0,b = 0;
	cin >> inp;
	stack<char> pcs;

	for (int i = 0; i < inp.size(); i++) {
		if (inp[i] == '(') {
			mul *= 2;
			//a++;
			pcs.push(inp[i]);

			if (i + 1 < inp.size() && inp[i + 1] == ')')
				sum += mul;

		}
		else if (inp[i] == '[') {
			mul *= 3;
			//b++;
			pcs.push(inp[i]);
			if (i + 1 < inp.size() && inp[i + 1] == ']')
				sum += mul;

		}
		else if (inp[i] == ')') {
			if (pcs.empty()||pcs.top()=='[') {
				sum = 0;
				break;
			}	
			//a--;
			pcs.pop();
			mul /= 2;
		}
		else {
			if (pcs.empty()||pcs.top()=='(') {
				sum = 0;
				break;
			}
			//b--;
			pcs.pop();
			mul /= 3;
		}
	}

	if (!pcs.empty())
		sum = 0;

	cout << sum << endl;

}