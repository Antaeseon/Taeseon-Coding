#include<cstdio>
#include<algorithm>


using namespace std;
int parent[10000002];
edge input[10000005];

int find(int cur)
{
	if (cur == parent[cur]) return cur;
	return parent[cur] = find(parent[cur]);
}

int merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	parent[b] = a;
	return 1;
}

struct edge {
	int a, b, cost;
	bool operator < (const edge & O)const {
		return this->cost < O.cost;
	}
};

bool cmp(edge &a, edge &b)
{
	return a.cost < b.cost;
}

int main() {
	int v, e;
	int a, b, c;
	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		input[i] = { a,b,c };
	}
	sort(input, input + e);

	int cnt=0;

	for (int i = 0; i < e; i++)
	{
		vector
	}

}