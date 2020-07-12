#include<iostream>
#include<algorithm>


using namespace std;

int main() {
	int num[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
		sum += num[i];
	}

	sort(num, num + 9);


	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - num[i] - num[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if(k!=i&&k!=j)
						cout << num[k]<<endl;
				}
				return 0;
			}
		}
	}


}