#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 0;
    int cnt = 0;
    vector<pair<int, int>> bridgeQ; // 다리 위에 올라와있는 큐 <경과시간, 무게>
    queue<int> waitQ;               // 대기하고 있는 트럭

    for (int i = 0; i < truck_weights.size(); i++)
    {
        waitQ.push(truck_weights[i]);
    }
    bridgeQ.push_back({0, truck_weights[0]});
    weight -= truck_weights[0];
    waitQ.pop();
    while (cnt < truck_weights.size()) // 도착한 트럭의 수가 시작 트럭 수보다 작으면 반복
    {
        time++;
        for (int i = 0; i < bridgeQ.size(); i++)
        { // 브릿지에 있는 시간 +1
            bridgeQ[i].first++;
        }

        if (bridgeQ[0].first > bridge_length) // 맨 앞에 있는 트럭의 경과 시간이 length보다 길면 erase
        {
            cnt++;
            weight += bridgeQ[0].second;
            bridgeQ.erase(bridgeQ.begin());
        }

        if (!waitQ.empty() && weight >= waitQ.front()) // waitQ의 맨앞 길이가 더 짧다면 pop처리
        {
            bridgeQ.push_back({1, waitQ.front()});
            weight -= waitQ.front();
            waitQ.pop();
        }
    }

    return time;
}
