#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    //인원 수를 오름차순으로 정렬
    sort(people.begin(), people.end());
    int s = 0;                 // 시작 인덱스
    int e = people.size() - 1; // 마지막 인덱스

    // 시작 인덱스가 마지막 인덱스보다 커질때까지 반복
    while (s <= e)
    {

        // 시작과 끝의 합이 인덱스보다 크면 마지막 인덱스 -1
        if (people[s] + people[e] > limit)
        {
            e--;
        }
        else
        {
            s++;
            e--;
        }
        answer++;
    }

    return answer;
}