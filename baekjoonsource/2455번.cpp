#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	int maxi = 0;
	int sum=0;
	int inp, oup;


	do {
		cin >> oup >> inp;
		sum = sum + inp - oup;
		maxi = max(sum, maxi);
	} while (sum);

	cout << maxi << "\n";
}