#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    int inp;
    int min = 1e9;
    int solution = 0;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        v.push_back(inp);
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum;
                sum = v[i] + v[j] + v[k];
                if (sum > m)
                    continue;
                if (abs(m - sum) < min)
                {
                    min = m - sum;
                    solution = sum;
                }
            }
        }
    }
    cout << solution << endl;
}