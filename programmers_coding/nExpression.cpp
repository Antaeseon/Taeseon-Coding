#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//초기 minimum값 1e9로 초기화
int minimum = 1e9;

void dfs(int cnt, int sum, int N, int number)
{
    if (cnt > 8) // N이 사용된 수가 8 초과하면 리턴
    {
        return;
    }
    if (sum == number) // 계산한 수가 number와 같으면 현재 cnt값이랑 minimum값 비교
    {
        minimum = min(minimum, cnt);
        return;
    }

    int tempCnt = 0;

    //N ~ NNNNNNNN값 계속해서 + - * / 로 계산
    for (int i = 0; i < 8; i++)
    {
        tempCnt = tempCnt * 10 + N;
        dfs(cnt + i + 1, sum + tempCnt, N, number);
        dfs(cnt + i + 1, sum - tempCnt, N, number);
        dfs(cnt + i + 1, sum * tempCnt, N, number);
        dfs(cnt + i + 1, sum / tempCnt, N, number);
    }
}

int solution(int N, int number)
{
    dfs(0, 0, N, number);
    return minimum == 1e9 ? -1 : minimum;
}
