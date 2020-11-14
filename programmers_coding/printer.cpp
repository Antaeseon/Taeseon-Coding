#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    priority_queue<int> pq;  // 최대순으로 정렬하기 위함
    queue<pair<int, int>> q; // 인덱스와 값 동시에 저장

    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }

    while (!pq.empty())
    { //pq에 내용이 모두 차있는 경우

        while (!q.empty())
        { //q를 순회하며 최대값을 찾는다.
            if (q.front().second == pq.top())
            { //pq와 q의 맨 앞의 값이 같은 경우에는 pop을 해준다.
                answer++;
                if (q.front().first == location)
                {
                    return answer;
                }
                pq.pop();
                q.pop();
                break;
            }
            else
            { // 아닌 경우에는 맨 앞 값을 맨 뒤에 push한다
                int f = q.front().first;
                int b = q.front().second;
                q.pop();
                q.push({f, b});
            }
        }
    }

    return answer;
}