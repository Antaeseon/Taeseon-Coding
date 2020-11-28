#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
*/
int dp[10000001];

struct node
{
    int num;
    int cnt;
    vector<int> v;
};

int main()
{
    std::ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    node a;
    queue<node> q;
    a.cnt = 1;
    a.num = n;
    a.v.push_back(n);
    q.push(a);
    for (int i = 0; i < 1000000; i++)
    {
        dp[i] = 1e9;
    }
    while (!q.empty())
    {
        int t_num = q.front().num;
        int t_cnt = q.front().cnt;
        vector<int> t_v = q.front().v;
        if (t_num == 1)
        {
            cout << t_cnt - 1 << "\n";
            for (int i = 0; i < t_v.size(); i++)
            {
                cout << t_v[i] << " ";
            }
            return 0;
        }
        q.pop();

        if (t_num % 3 == 0)
        {
            if (t_cnt + 1 < dp[t_num / 3])
            {
                t_v.push_back(t_num / 3);
                q.push({t_num / 3, t_cnt + 1, t_v});
                dp[t_num / 3] = t_cnt + 1;
                t_v.pop_back();
            }
        }

        if (t_num % 2 == 0)
        {
            if (t_cnt + 1 < dp[t_num / 2])
            {
                t_v.push_back(t_num / 2);
                q.push({t_num / 2, t_cnt + 1, t_v});
                dp[t_num / 2] = t_cnt + 1;
                t_v.pop_back();
            }
        }

        if (t_num - 1 != 0)
        {
            if (t_cnt + 1 < dp[t_num - 1])
            {
                t_v.push_back(t_num - 1);
                q.push({t_num - 1, t_cnt + 1, t_v});
                dp[t_num - 1] = t_cnt + 1;
                t_v.pop_back();
            }
        }
        cout << "\n--------------------\n";

        for (int j = 1; j < 10; j++)
        {
            cout << dp[j] << " ";
        }
        cout << "\n--------------------\n";
    }
}
