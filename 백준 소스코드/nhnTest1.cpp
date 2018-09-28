#include <iostream>
#include <vector>
using namespace std;
int number[7];
int main() {
	int inp;
	int temp;
	vector<int>v;
	vector<int>ans;
	for (int i = 0; i < 9; i++) {
		cin >> inp;
		if (number[inp] == 0 && v.size() < 3)
		{
			number[inp] = 1;
			v.push_back(inp);
			continue;
		}
		else if (number[inp] == 1 && v.size() < 3)
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == inp) {
					v.erase(v.begin()+j);
					v.push_back(inp);
				}
			}
		}
		else if (number[inp] == 0) {
			number[inp] = 1;
			temp = v.front();
			number[temp] = 0;
			v.erase(v.begin());
			v.push_back(inp);
			ans.push_back(temp);
		}
		else {
			temp = v.front();

			if (temp == inp) {
				v.erase(v.begin());
				v.push_back(inp);
				continue;
			}

			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == inp) {
					v.erase(v.begin() + j);
					v.push_back(inp);
				}
			}
			ans.push_back(temp);

		}	
	}

	if (ans.empty())
	{
		cout << 0;
		return 0;
	}

	for (auto number : ans)
		cout << number << " ";
	return 0;
}