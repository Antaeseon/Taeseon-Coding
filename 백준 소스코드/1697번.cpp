#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	int visited[100001] = { 0, };


	while (!q.empty()) {
		int now = q.front().first;
		int current = q.front().second;
		q.pop();

		if (now > 100000)
			continue;
		if (now < 0)
			continue;
		if (visited[now])
			continue;
		if (now == m)
			return current;
		visited[now] = 1;
		q.push({ now + 1,current + 1 });
		q.push({ now -1,current + 1 });
		q.push({ now *2,current + 1 });


	}

}




int main() {
	cin >> n >> m;
	cout<<bfs(n);

}