#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long map[101][101];

int solution(int m, int n, vector<vector<int>> puddles)
{

    // puddles 부분을 -1e9로 초기화
    for (int i = 0; i < puddles.size(); i++)
    {
        map[puddles[i][1] - 1][puddles[i][0] - 1] = -1e9;
    }
    //n => 세로 m => 가로

    // 1행부분과 1열부분 1로 초기화 => puddles가 있으면 break처리
    for (int i = 1; i < m; i++)
    {
        if (map[0][i] == -1e9)
            break;
        map[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (map[i][0] == -1e9)
            break;
        map[i][0] = 1;
    }

    // 왼쪽부분과 위쪽부분의 합 계산 후 -이면 둘중 큰부분으로 처리
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (map[i][j] == -1e9)
            {
                continue;
            }

            map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
            if (map[i][j] < 0)
            {
                map[i][j] = max(map[i - 1][j], map[i][j - 1]);
            }
        }
    }

    return map[n - 1][m - 1];
}
