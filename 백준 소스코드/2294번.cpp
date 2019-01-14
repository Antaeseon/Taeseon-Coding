#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dp[100001]; //i원일 때 사용된 동전의 최소 개수
vector<int>coin;

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int N, K;
	cin >> N >> K;
	coin.resize(N);
	for (int i = 0; i < 100001; i++)
		dp[i] = 1e9;

	for (int i = 0; i < N; i++)
	{
		cin >> coin[i];
	}
	sort(coin.begin(), coin.end());


	for (int i = 0; i < N; i++)
	{
		for (int j = coin[i]; j <= K; j++)
		{

			if (j%coin[i] == 0)
				dp[j] = min(dp[j], j / coin[i]);
			else
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[K] < 1e9)
		cout << dp[K]<<"\n";
	else
		cout << "-1"<<"\n";
}