#include<cstdio>
#include<iostream>

using namespace std;
big num[101][101];

int min(int a, int b) //�ּҰ��� ���ϴ� �Լ��̴�.
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
	scanf("%d %d", &N, &K); //N�� K�� �Է¹޴´�.

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= min(N, K); j++)
		{
			if (j == 0 || j == i)
				num[i][j] = 1; // 0C0�̰ų� nCn�� ��쿡�� 1�� �����Ѵ�.
			else
				num[i][j] = num[i - 1][j] + num[i - 1][j - 1]; //������ ��쿡�� ���Ͱ��� ������ �����Ѵ�.
		}
	}
	
	cout << num[N][K]<<endl;
}