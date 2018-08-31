#include<iostream>
#include<queue>

using namespace std;

 vector<int>relative[102];
int visited[102];

struct node {
	int a;
	int depth;
};

int main() {
	int n;
	int p1, p2;
	int m;
	int a, b;
	node person;
	queue<node>q;
	cin >> n;
	cin >> p1 >> p2;
	cin >> m;
	person.a = p1;
	person.depth = 0;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		relative[a].push_back(b);
		relative[b].push_back(a);
	}
	visited[p1] = 1;
	q.push(person);
	while (!q.empty()) {
		a = q.front().a;
		for (int i = 0; i < relative[a].size(); i++) {
			int next = relative[a][i];
			if (!visited[next]) {
				visited[next] = 1;
				person.a = next;
				person.depth = q.front().depth + 1;
				q.push(person);

				if (next == p2) {
					cout << person.depth<<endl;
					return 0;
				}
			}
		}

		q.pop();
	}

	cout << "-1" << endl;
}