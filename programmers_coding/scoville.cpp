#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; //pq를 이용하여 최소값 정렬

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (pq.top() < K)
    {
        if (pq.size() == 1)
        { //사이즈가 1인경우 결과값을 만족하지 못한다.
            return -1;
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + 2 * b); // 두 수를 pop 하여 계산
        answer++;
    }

    return answer;
}