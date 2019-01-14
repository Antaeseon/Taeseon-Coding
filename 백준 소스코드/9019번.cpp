#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct node {
	int num=0;
	string dslr="";
};

int DSLR(int num,int i) {
	if (i == 0) { //D
		num = num * 2 % 10000;
	}
	else if (i == 1) { //S
		num--;
		if (num == -1)
			num = 9999;
	}
	else if (i == 2) { //L
		int front = (num / 1000);
		num = (num % 1000) * 10 + front;
	}
	else { //R
		int last = num % 10;
		num = (num / 10) + (last * 1000);
	}
	return num;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	int a;
	int b;
	node n;
	cin >> testCase;
	while (testCase--) {
		queue<node>q;
		bool visited[10001] = { 0, };
		cin >> a >> b;
		n.num = a;
		n.dslr="";
		q.push(n);
		visited[a] = true;
		while (!q.empty()) {
			int tempNum = q.front().num;
			string tempDslr = q.front().dslr;
			q.pop();
			if (tempNum == b) {
				cout <<tempDslr<< "\n";
				break;
			}

			for (int i = 0; i < 4; i++) {
				int eachNum;
				eachNum = DSLR(tempNum, i);
				if (visited[eachNum])
					continue;
				visited[eachNum] = true;
				n.num = eachNum;
				if (i == 0) {
					n.dslr = tempDslr;
					n.dslr += "D";
				}
				else if (i == 1) {
					n.dslr = tempDslr;
					n.dslr += "S";

				}
				else if (i == 2) {
					n.dslr = tempDslr;
					n.dslr += "L";
				}
				else {
					n.dslr = tempDslr;
					n.dslr += "R";
				}
				q.push(n);
			}
		}
	}
}