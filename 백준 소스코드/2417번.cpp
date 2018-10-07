#include<iostream>
#include<cmath>

using namespace std;


int main() {
	double num;
	cin >> num;

	printf("%lld", (long long)ceil(sqrt(num)));
}