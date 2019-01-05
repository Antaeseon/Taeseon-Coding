#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	int arr[100];
	int dump;

	for(int k=1;k<=10;k++) {
		cin >> dump;
		for (int i = 0; i < 100; i++) arr[i]=0;
		for (int i = 0; i < 100; i++) cin >> arr[i];

		for (int i = 0; i < dump; i++) {
			sort(arr, arr + 100);

			if (arr[0] + 2 < arr[99]) {
				arr[0]++;
				arr[99]--;
			}
			else {
				break;
			}
		}
		sort(arr, arr + 100);

		cout <<"#"<<k<<" "<< arr[99]-arr[0] << endl;
	}
	
}