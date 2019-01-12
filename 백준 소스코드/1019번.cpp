#include<iostream>

using namespace std;

int mul = 1;
int arr[10] = { 0, };

void calc(int num) {
	while (num) {
		arr[num%10]+=mul;
		num /= 10;
	}
}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	int start = 1;
	int end = n;
	int temp;
	while (start <= end) {
		while (start % 10 != 0 && start <= end) {
			calc(start++);
		}
		if (start > end)
			break;
		while (end % 10 != 9 && start <= end) {
			calc(end--);
		}
		if (start > end)
			break;

		start /= 10;
		end /= 10;
		temp = (end - start + 1)*mul;
		for (int i = 0; i < 10; i++)
			arr[i] += temp;
		mul *= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

}