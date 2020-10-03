#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> triangle)
{
    int answer = 0;

    //삼각형 최상위 값으로 dp값 초기화
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            { // 가장 왼쪽에 있는 라인은 이전 left + 현재값
                dp[i][0] = dp[i - 1][0] + triangle[i][0];
            }
            else if (j == triangle[i].size() - 1)
            { // 가장 오른쪽은 이전 right + 현재값
                dp[i][triangle[i].size() - 1] = dp[i - 1][triangle[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1];
            }
            else
            { // 윗 라인 왼쪽 오른쪽 중 큰 값 + 현재값
                dp[i][j] = max(dp[i - 1][j] + triangle[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
            answer = max(answer, dp[i][j]);
        }
    }

    return answer;
}