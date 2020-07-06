#include <bits/stdc++.h>

using namespace std;

int arr[11][11];
bool visited[11][11];
int minimum = 1e9;
int sak[6] = {0, 5, 5, 5, 5, 5};

void dfs(int y, int x, int tot)
{
	if (x >= 10)
	{
		dfs(y + 1, 0, tot);
		return;
	}

	if (y == 10)
	{
		minimum = min(minimum, tot);
		return;
	}

	if (arr[y][x] == 0)
	{
		dfs(y, x + 1, tot);
		return;
	}

	for (int size = 1; size <= 5; size++)
	{
		if (sak[size] == 0 || y+size>10||x+size>10)
			continue;

		int tempCnt = 0;

		for (int nY = y; nY < y + size; nY++)
		{
			for (int nX = x; nX < x + size; nX++)
			{
				if (arr[nY][nX] == 1)
					tempCnt++;
			}
		}

		if (tempCnt == size * size)
		{
			for (int nY = y; nY < y + size; nY++)
			{
				for (int nX = x; nX < x + size; nX++)
				{
					arr[nY][nX] = 0;
				}
			}

			sak[size]--;
			tot++;
			dfs(y, x + size, tot);
			for (int nY = y; nY < y + size; nY++)
			{
				for (int nX = x; nX < x + size; nX++)
				{
					arr[nY][nX] = 1;
				}
			}
			sak[size]++;
			tot--;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false), cin.tie(0);
	int inp;
	int totalOne = 0;
	int sak[6] = {
		0,
	};
	bool visited[11][11];

	for (int i = 1; i <= 5; i++)
	{
		sak[i] = 5;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> inp;
			arr[i][j] = inp;
			if (inp == 1)
				totalOne++;
		}
	}

	dfs(0, 0, 0);

	minimum!=1e9?cout << minimum << "\n" : cout<<"-1\n";
}