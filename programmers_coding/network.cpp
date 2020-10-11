#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool visited[201];
vector<vector<int>> node;

void dfs(int cur, int n)
{
    visited[cur] = true;
    for (int i = 0; i < node[cur].size(); i++)
    {
        int next = node[cur][i];

        if (!visited[next])
        {
            dfs(next, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    node.resize(computers.size());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && computers[i][j])
            {
                node[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, n);
            answer++;
        }
    }

    return answer;
}