#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	string inp;
	int cnt = 0;
	while (1) {
		cin >> inp;
		bool flag = true;
		bool blockCheck[2] = { false, };
		cnt++;
		if (inp == "0")
			break;
		for (int i = 0; i < inp.size(); i++) {
			if (inp[i] == '1') {
				if (!blockCheck[0]) {
					blockCheck[0] = true;
				}
				else {
					cout << cnt << ". NOT" << "\n";
					flag = false;
					break;
				}
			}
			else if (inp[i] == '2') {
				if (!blockCheck[1]) {
					blockCheck[1] = true;
				}
				else {
					cout << cnt << ". NOT" << "\n";
					flag = false;
					break;
				}
			}
		}
		if (!flag)
			continue;


		if (inp[0] != '1'||inp[inp.size() - 1] != '2')
		{
			cout <<cnt<< ". NOT" << "\n";
			continue;
		}

		for (int i = 0; i < inp.size() - 1; i++) {
			if (inp[i] == '1') {
				if (inp[i+1]=='2'||inp[i + 1] == '3' || inp[i + 1] == '6' || inp[i + 1] == '7' || inp[i + 1] == '8')
				{
					flag = false;
					break;
				}
			}

			else if (inp[i] == '3') {
				if (inp[i+1]=='2'||inp[i+1]=='3'||inp[i + 1] == '6' || inp[i + 1] == '7' || inp[i + 1] == '8') {
					flag = false;
					break;
				}
			}

			else if (inp[i] == '4') {
				if (inp[i + 1] == '5' || inp[i + 1] == '6' || inp[i + 1] == '7' || inp[i + 1] == '8') {
					flag = false;
					break;
				}
			}

			else if (inp[i] == '5') {
				if (inp[i + 1] != '8') {
					flag = false;
					break;
				}
			}


			else if (inp[i] == '6') {
				if (inp[i + 1] == '7' || inp[i + 1] == '8' || inp[i + 1] == '4' || inp[i + 1] == '5') {
					flag = false;
					break;
				}
			}
			else if (inp[i] == '7') {
				if (inp[i + 1] != '8') {
					flag = false;
					break;
				}
			}
			else if (inp[i] == '8') {
				if (!(inp[i + 1] == '6' || inp[i + 1] == '7')) { //6이나 7이 아니면 true
					flag = false;
					break;
				}
			}
		}
		
		flag ? cout << cnt << ". VALID" << "\n" : cout << cnt << ". NOT" << "\n";


	}
}