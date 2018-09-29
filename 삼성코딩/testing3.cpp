#include <iostream>
#include<algorithm>
using namespace std;
int price[1003];
int day;
int maxi=0;
void dfs(int cur, int sum,int pr,int coin) {

	if (cur == day)
	{
		maxi = max(maxi, sum);

		return;
	}
	

	if (coin == 0) // »ê°Ô ¾øÀ» ¶§
	{
		dfs(cur + 1, sum, 0,0); //±×³É ³Ñ±è
		dfs(cur + 1, sum, price[cur],1); // »ï
	}
	else //»ê°Ô ÀÖÀ» ¶§
	{
		dfs(cur + 1, sum, pr,coin); // ±×³É³Ñ±è
		dfs(cur + 1, sum, pr + price[cur],coin+1); //»ï
		dfs(cur + 1, sum+coin*price[cur]-pr - 1, 0,0); // ÆÊ
	}


}



int main() {
	cin >> day;
	for (int i = 0; i < day; i++)
		cin >> price[i];
	
	dfs(0, 0,0,0);
	cout << maxi << endl;
	return 0;
}