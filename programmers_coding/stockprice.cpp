// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}

int main()
{
    //[ 93, 30, 55 ][1, 30, 5]

    vector<int>
        v{95, 90, 99, 99, 80, 99};
    vector<int> w{1, 1, 1, 1, 1, 1};
    vector<int> a = solution(v, w);

    for (auto c : a)
    {
        cout << c << "\n";
    }
}