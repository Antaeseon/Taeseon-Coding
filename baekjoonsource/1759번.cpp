#include<iostream>
#include<algorithm>


using namespace std;
int L, C;
char pass[16];
char alpha[5] = { 'a','e','i','o','u' };
int visited[16];

bool checkMo(char a) {
	for (int i = 0; i < 5; i++) {
		if (a == alpha[i])
			return true;
	}
	return false;
}

void dfs(int here, int ja, int mo, int depth) {



	if (here == C && ja >= 2 && mo >= 1 && depth == L) {
		for (int i = 0; i < C; i++) {
			if (visited[i] == 1) {
				cout << pass[i];
			}
		}
		cout << endl;
	}
	if (here == C)
		return;

	if (checkMo(pass[here]))
		mo++;
	else
		ja++;
	visited[here] = 1;
	dfs(here + 1, ja, mo, depth + 1);
	visited[here] = 0;
	if (checkMo(pass[here]))
		mo--;
	else
		ja--;
	dfs(here + 1, ja, mo, depth);



}


int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin>>pass[i];
	}
	sort(pass, pass + C);
	dfs(0, 0, 0, 0);
}


