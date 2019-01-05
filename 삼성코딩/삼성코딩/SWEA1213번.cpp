#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int fail_table[101];


void make_table(string pattern) {
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = fail_table[j - 1];
		}
		if (pattern[i] == pattern[j])
			fail_table[i] = ++j;
	}
}

void KMP(string cmpString, string inpString,int num) {
	int cmpStringSize = cmpString.size();
	int inpStringSize = inpString.size();
	int cnt = 0;
	int j = 0;
	for (int i = 1; i < inpStringSize; i++) {
		while (j > 0 && cmpString[j] != inpString[i]) {
			j = fail_table[j - 1];
		}

		if (inpString[i] == cmpString[j]) {
			if (j == cmpStringSize - 1) {
				cnt++;
				j = fail_table[j];
			}
			else {
				j++;
			}
		}

	}

	cout << "#" <<num<<" "<< cnt << endl;;
}



int main() {
	int testNum;
	string cmpString;
	string inpString;
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 101; j++) fail_table[i] = 0;
		cin >> testNum;
		getchar();
		getline(cin, cmpString);
		getline(cin, inpString);

		KMP(cmpString, inpString,i);
	}

	

}