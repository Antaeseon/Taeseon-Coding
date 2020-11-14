#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visited[20001];
vector<int> map[20001];
int maximum = 0;
int cnt = 0;
int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < edge.size(); i++)
    { //양방향으로 이어진 노드 생성
        map[edge[i][0]].push_back(edge[i][1]);
        map[edge[i][1]].push_back(edge[i][0]);
    }

    visited[1] = true; // 초기 시작점인 1은 방문처리
    q.push({1, 0});    // 1로 시작

    while (!q.empty())
    {
        int cur = q.front().first;
        int dep = q.front().second;
        q.pop();

        for (int i = 0; i < map[cur].size(); i++)
        {
            int next = map[cur][i];
            if (!visited[next])
            { // 연결된 노드가 방문을 하지 않았을 때에는 queue에 push
                q.push({next, dep + 1});
                visited[next] = true;
                if (maximum < dep + 1)
                { // 최대값이 바뀐다면 cnt 초기화
                    maximum = dep + 1;
                    cnt = 1;
                }
                else
                { // 최대값이 같은 경우 cnt ++
                    cnt++;
                }
            }
        }
    }
    return cnt;
}