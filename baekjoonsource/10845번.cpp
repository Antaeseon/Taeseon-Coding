#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>


using namespace std;

queue<int> q;





int main()
{
	int N,a;
	cin >> N;
	string input;


	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input=="push") {
			cin >> a;
			q.push(a);
		}
		else if (input=="pop") {
			if (q.size() != 0) {
				a = q.front();
				q.pop();
			}
			else
				a = -1;
			cout << a<<endl;
		}
		else if (input == "size") {
			cout << q.size() << endl;
		}
		else if (input == "empty") {
			if (q.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (input == "front") {
			if (q.size() != 0)
				a = q.front();
			else
				a = -1;
			cout << a << endl;
		}
		else if (input == "back") {
			if (q.size() != 0)
				a = q.back();
			else
				a = -1;
			cout << a << endl;
		}
	}
}