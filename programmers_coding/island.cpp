#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

// 최상위 node 찾기
int find(int num)
{
    if (num == parent[num])
    {
        return num;
    }
    else
    {
        return find(parent[num]);
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    //오름차순으로 가중치 정렬
    sort(costs.begin(), costs.end(), cmp);

    //자기 자신을 최상위 노드로 초기화
    for (int i = 0; i < 101; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < costs.size(); i++)
    {
        int from = find(costs[i][0]);
        int to = find(costs[i][1]);
        int cost = costs[i][2];

        // 두 노드가 다른 집단일 경우 연결처리
        if (from != to)
        {
            parent[to] = from;
            answer += cost;
        }
    }

    return answer;
}