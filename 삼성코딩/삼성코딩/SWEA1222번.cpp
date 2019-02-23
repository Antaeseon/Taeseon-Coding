#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	string s;
	map<string, int>notIn;
	map<string, int>In;
	notIn["+"] = 1;
	notIn["-"] = 1;
	notIn["*"] = 2;
	notIn["/"] = 2;
	notIn["("] = 3;
	In["+"] = 1;
	In["-"] = 1;
	In["*"] = 2;
	In["/"] = 2;
	In["("] = 0;
	for (int z = 1; z <= 10; z++) {
		cin >> n;
		cin >> s;
		vector<string>res;
		vector<string>v;
		for (int i = 0; i <= n; i++) {
			if (i == n) {
				while (!v.empty()) {
					res.push_back(v[v.size() - 1]);
					v.pop_back();
				}
				break;
			}
			string a = "";
			a += s[i];
			if (a == "+" || a == "-" || a == "*" || a == "/" || a == "(") {
				if (v.size() == 0) {
					v.push_back(a);
					continue;
				}
				if (notIn[a] > In[v[v.size() - 1]]) {
					v.push_back(a);
				}
				else {
					while (v.size()!=0&&notIn[a] < In[v[v.size() - 1]]) {
						if (v.size() == 0)
							break;
						res.push_back(v[v.size() - 1]);
						v.pop_back();
					}
					v.push_back(a);
				}
			}
			else if (a == ")") {
				while (v[v.size() - 1] != "(") {
					if (v.size() == 0)
						break;
					res.push_back(v[v.size() - 1]);
					v.pop_back();
				}
				v.pop_back();
			}
			else {
				res.push_back(a);
			}
		}
		long long sum = 0;
		vector<int>vv;
		for (int i = 0; i < res.size(); i++) {
			if (res[i].size() > 1 || (res[i] >= "1" && res[i] <= "9"))
				vv.push_back(stoi(res[i]));
			else {
				int b = vv[vv.size() - 1];
				vv.pop_back();
				int a = vv[vv.size() - 1];
				vv.pop_back();
				if (res[i] == "+") {
					vv.push_back(a + b);
				}
				else if (res[i] == "-") {
					vv.push_back(a - b);
				}
				else if (res[i]== "*") {
					vv.push_back(a*b);
				}
				else if (res[i] == "/") {
					vv.push_back(a / b);
				}
			}
		}
		cout <<"#"<<z<<" "<< vv[0]<<"\n";
	}
}
