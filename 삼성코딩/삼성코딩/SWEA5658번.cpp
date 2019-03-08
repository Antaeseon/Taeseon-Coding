#include<iostream>
#include<algorithm>
#include<set>
#include<deque>
#include<string>

using namespace std;

long long ch(char a) {
	if (a == '0')
		return 0;
	else if (a == '1')
		return 1;
	else if (a == '2')
		return 2;
	else if (a == '3')
		return 3;
	else if (a == '4')
		return 4;
	else if (a == '5')
		return 5;
	else if (a == '6')
		return 6;
	else if (a == '7')
		return 7;
	else if (a == '8')
		return 8;
	else if (a == '9')
		return 9;
	else if (a == 'A')
		return 10;
	else if (a == 'B')
		return 11;
	else if (a == 'C')
		return 12;
	else if (a == 'D')
		return 13;
	else if (a == 'E')
		return 14;
	else if (a == 'F')
		return 15;

}



int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	string inp;
	int n, k;
	cin >> testCase;
	for (int z = 1; z <= testCase; z++) {
		cin >> n >> k;
		cin >> inp;
		set<long long>s;	
		deque<char>dq;
		for (int i = 0; i < inp.size(); i++) {
			dq.push_back(inp[i]);
		}
		
		for (int i = 0; i < (n/4)-1; i++) {
			for (int j = 0; j < 4; j++) {
				long long tnum=0;
				long long st = (j * (n/4));
				long long temp = 1;
				for (int k = n/4-1; k >=0; k--) {
					tnum += ch(dq[st + k]) * temp;
					temp *= 16;
				}
				s.insert(tnum);
			}
			int f = dq.back();
			dq.pop_back();
			dq.push_front(f);
		}
		
		auto tp = s.end();
		for (int i = 0; i < k; i++)
			tp--;
		cout <<"#"<<z<<" "<< *tp << "\n";


	}

}