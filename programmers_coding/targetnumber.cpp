#include <string>
#include <vector>

using namespace std;

vector<int> copy_numbers;
int res = 0;

void dfs(int cur, int sum, int target)
{

    //cur과 numbers의 사이즈가 같아지면 비교 시작
    if (cur == copy_numbers.size())
    {
        if (sum == target)
        {
            res++;
        }
        return;
    }
    //현재값을 더할 때
    dfs(cur + 1, sum + copy_numbers[cur], target);
    //현재값을 뺄 때
    dfs(cur + 1, sum + copy_numbers[cur] * -1, target);
}

int solution(vector<int> numbers, int target)
{
    //전역변수에 저장
    copy_numbers = numbers;
    //dfs로 풀이 (현재 커서, 합, 타겟 숫자)
    dfs(0, 0, target);
    return res;
}