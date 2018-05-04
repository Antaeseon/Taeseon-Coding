#include<cstdio>
#include<algorithm>

using namespace std;

int arr[102][102];


int main()
{
	
	for (int i = 1; i <= 10; i++)
	{
		printf("#%d\n",i);
		for (int j = 1; j <= i; j++) //크기는 1부터 10까지 증가를 한다.
		{
			int num = 1;
			int cct = j;
			int a = 1, b = 0;
			int alpha = 1;
			while (1)
			{
				for (int k = 0; k < cct; k++)
				{
					b += alpha;
					arr[a][b] = num++;
				

				}
				cct--;
				if (cct < 0)
					break;
				for (int k = 0; k < cct; k++)
				{
					a += alpha;
					arr[a][b] = num++;
					
				}

				alpha *= -1;

			}
			
		}
		for (int j = 1;j <= i; j++)
		{
			for (int k = 1; k <= i; k++)
				printf("%d ", arr[j][k]);
			printf("\n");
		}
	}
}