#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> res;

    for (int i = 0; i < prices.size() - 1; i++)
    {
        for (int j = i + 1; j < prices.size(); j++) //가격 비교 -> 더 작은수가 나오면 해당 인덱스에서 현재 인덱스 마이너스
        {
            if (prices[i] > prices[j]) //더 작은값이 나온경우
            {
                res.push_back(j - i);
                break;
            }

            if (j == prices.size() - 1) // 더 작은값이 없는 경우
            {
                res.push_back(j - i);
            }
        }
    }
    res.push_back(0); // 마지막 값은 비교할 값이 없기 때문에 0 추가
    return res;
}