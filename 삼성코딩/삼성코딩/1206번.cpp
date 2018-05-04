#include<cstdio>
#include<algorithm>

using namespace std;

int apart[1005];


int main() {
	int num;
	int cnt;
	for (int kk = 1; kk <= 10; kk++)
	{
		cnt = 0;
		int lmax, rmax;
		scanf("%d", &num);
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &apart[i]);
		}

		for (int i = 0; i < num; i++)
		{
			lmax = max(apart[i - 2], apart[i - 1]);
			rmax = max(apart[i + 2], apart[i + 1]);
			if (lmax <= apart[i] - 1 && rmax <= apart[i] - 1)
				cnt += (apart[i] - max(lmax, rmax));
		}

		printf("#%d %d\n", kk, cnt);
	}
}