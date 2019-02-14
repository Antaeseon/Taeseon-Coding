#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;
string a;
int b;
int maximum=0;
void dfs(int cur,int cnt) {
	bool flag = false;
	if (cur == a.size())
		return;
	if (cnt==b) {
		maximum = max(maximum, stoi(a));
		return;
	}	

	for (int i = cur + 1; i < a.size(); i++) {
		if (a[cur] <= a[i]&&cnt<b) {
			swap(a[cur], a[i]);
			dfs(cur + 1,cnt+1);
			dfs(cur, cnt + 1);
			swap(a[cur], a[i]);
			dfs(cur + 1 , cnt);
			flag = true;
		}
	}
	if (!flag)
		dfs(cur + 1, cnt);


}

int main() {
	int testCase;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> a >> b;
		maximum = 0;
		dfs(0, 0);
		cout << "#" << z << " " << maximum << "\n";
	}
}