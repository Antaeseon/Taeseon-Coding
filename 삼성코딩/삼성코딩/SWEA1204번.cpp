#include<iostream>


using namespace std;


int main() {
	int testNum;
	int num;
	int inpNum;
	cin >> testNum;
	while (testNum--) {
		int cnt[101] = { 0 };
		int max = 0;
		int index = 0;
		cin >> num;
		for (int i = 0; i < 1000; i++) {
			cin >> inpNum;
			cnt[inpNum]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (cnt[i] >= max)
			{
				max = cnt[i];
				index = i;
			}
		}


		cout << "#" << num << " " << index << "\n";
	}
}