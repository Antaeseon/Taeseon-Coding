#include<iostream>
#include<stack>
#include<vector>

using namespace std;




int main() {
	int n;
	int cnt = 0;
	stack<int>c;
	vector<int>pro;
	vector<int>temp;
	vector<char>ans;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >>a;
		pro.push_back(a);
		temp.push_back(i+1);

	}
	c.push(0);
	while (cnt<n) {
		if (c.top() < pro[cnt]) {
			c.push(temp.front());
			ans.push_back('+');
			temp.erase(temp.begin());
		}
		else if (c.top() == pro[cnt]) {
			c.pop();
			ans.push_back('-');
			cnt++;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}