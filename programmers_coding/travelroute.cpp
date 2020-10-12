#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
vector<string> answer;
bool visited[10001];

//가장 먼저 답이 나오면 flag true로 설정
bool flag = false;

void dfs(string cur, int cnt, vector<vector<string>> tickets, vector<string> now)
{
    if (flag) // 이미 경로가 나온 경우 나머지 return
        return;
    if (cnt == tickets.size())
    { //사용한 티켓의 수가 전체 티켓수와 같은 경우
        answer = now;
        flag = true;
        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i])
            continue;

        if (tickets[i][0] == cur)
        { //현재 위치와 티켓의 출발지가 같은 경우 목적지 push
            now.push_back(tickets[i][1]);
            visited[i] = true;
            dfs(tickets[i][1], cnt + 1, tickets, now);
            visited[i] = false;
            now.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());
    vector<string> v;
    v.push_back("ICN"); //시작은 인천에서 한다.
    dfs("ICN", 0, tickets, v);

    return answer;
}