#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int a, b, n, m;
int visited[100003];

int nextNum(int i, int cur) {
	switch (i)
	{
	case 0:
		return cur + a;
	case 1:
		return cur + b;
	case 2:
		return cur * a;
	case 3:
		return cur * b;
	case 4:
		return cur - a;
	case 5:
		return cur - b;
	case 6:
		return -(cur * a);
	case 7:
		return -(cur * b);
	case 8:
		return cur + 1;
	case 9:
		return cur - 1;
	}

}

struct node {
	int num;
	int cnt = 0;
};



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> a >> b >> n >> m;
	queue<node>q;
	node tr;
	int result = 0;
	tr.num = n;
	q.push(tr);
	visited[n] = 1;
	while (!q.empty())
	{
		int tempCur = q.front().num;
		int tempCnt = q.front().cnt;
		q.pop();
		if (tempCur == m) {
			result = tempCnt;
			break;
		}


		tr.cnt = tempCnt + 1;
		for (int i = 0; i < 10; i++) {
			tr.num = nextNum(i, tempCur);
			if (tr.num < 0 || tr.num>100000)
				continue;
			if (visited[tr.num])
				continue;
			visited[tr.num] = 1;
			q.push(tr);
		}
	}

	cout << result<<"\n";
}