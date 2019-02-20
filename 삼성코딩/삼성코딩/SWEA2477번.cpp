#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
int a[11];
int b[11];
int time[11];
int res[11][11];

struct node {
	int num;
	int aNum;
	int bNum;
	int t;
};


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int testCase;
	cin >> testCase;

	for (int z = 1; z <= testCase; z++) {
		int N, M, K, A, B;
		queue<node>aWait;
		queue<node>bWait;
		queue<node>ashop[11];
		queue<node>bshop[11];
		int res[11][11] = { 0, };
		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++)
			cin >> a[i];
		for (int i = 1; i <= M; i++)
			cin >> b[i];
		for (int i = 1; i <= K; i++)
			cin >> time[i];
		
		int t = 0;
		int total = 0;
		while (1) {
			for (int i = 1; i <= K; i++) { //도착해서 큐 안으로
				if (time[i] == t) {
					aWait.push({ i,0,0,0 });
				}
			}

			for (int i = 1; i <= N; i++) { // a 상태변화
				if (ashop[i].size()!=0) {
					if (ashop[i].front().t == 0) {
						node tmp;
						tmp.num = ashop[i].front().num;
						tmp.aNum = i;
						bWait.push(tmp);
						ashop[i].pop();
					}
				}
			}

			for (int i = 1; i <= M; i++) { // b 상태변화
				if (bshop[i].size() != 0) {
					if (bshop[i].front().t == 0) {
						res[bshop[i].front().aNum][bshop[i].front().bNum]+=bshop[i].front().num;
						total++;
						bshop[i].pop();
					}
				}

			}


			for (int i = 1; i <= N; i++) { // 도착 후 a로
				if (aWait.empty())
					break;
				if (ashop[i].size() == 0)
				{
					node tmp;
					tmp.num = aWait.front().num;
					tmp.aNum = i;
					tmp.t = a[i];
					ashop[i].push(tmp);
					aWait.pop();
				}
			}


			for (int i = 1; i <= M; i++) { // a 후 b로
				if (bWait.empty())
					break;
				if (bshop[i].size() == 0) {
					node tmp;
					tmp.num = bWait.front().num;
					tmp.aNum = bWait.front().aNum;
					tmp.bNum = i;
					tmp.t = b[i];
					bshop[i].push(tmp);
					bWait.pop();
				}
			}

			for (int i = 1; i <= N; i++) {
				if (ashop[i].empty())
					continue;
				ashop[i].front().t -= 1;
			}
			for (int i = 1; i <= M; i++) {
				if (bshop[i].empty())
					continue;
				bshop[i].front().t -= 1;
			}

			t++;


			if (total == K)
				break;

		}

		cout << res[A][B] << "\n";

	}
	
}