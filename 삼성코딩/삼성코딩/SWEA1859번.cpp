#include<iostream>
#include<vector>

using namespace std;

vector<int>inpNum;




int main() {
	int totalIndex;
	int localIndex;
	int inp;
	int cnt = 1;
	int result,price;
	cin >> totalIndex;
	while (totalIndex--) {
		cin >> localIndex;
		price = 0;
		result = 0;
		for (int i = 0; i < localIndex; i++) {
			cin >> inp;
			inpNum.push_back(inp);
		}

		price = inpNum[localIndex - 1];

		for (int i = localIndex - 2; i >= 0; i--) {
			if (price > inpNum[i]) {
				result += (price - inpNum[i]);
			}
			else {
				price = inpNum[i];
			}
		}



		cout <<"#"<<cnt++<<" "<< result << "\n";
		inpNum.clear();
	}
}