#include<cstdio>
#include<iostream>

using namespace std;
big num[101][101];

int min(int a, int b) //최소값을 구하는 함수이다.
{
	if (a > b)
		return b;
	else
		return a;
}


int main()
{
	 
	int N, K;
	int sum;
	scanf("%d %d", &N, &K); //N과 K를 입력받는다.

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= min(N, K); j++)
		{
			if (j == 0 || j == i)
				num[i][j] = 1; // 0C0이거나 nCn인 경우에는 1을 대입한다.
			else
				num[i][j] = num[i - 1][j] + num[i - 1][j - 1]; //나머지 경우에는 위와같은 공식을 대입한다.
		}
	}
	
	cout << num[N][K]<<endl;
}