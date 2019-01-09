#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	string temp;
	map<string,string>map;
	vector<string>inp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		inp.push_back(temp);
		map[temp] = to_string(i);
	}
	

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (map.find(temp) != map.end()) {
			cout << "´ä"<<stoi(map[temp])+1<<"\n";
		}
		else {
			int tempInt = stoi(temp);
			cout << "´ä" << inp[tempInt-1]<<"\n";
		}
	}

}