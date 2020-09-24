#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

bool decimal[10000002] = {
    true,
};
set<int> s;

void dfs(int cur, string alp, string numbers, bool visited[])
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        dfs(cur + 1, alp + numbers[i], numbers, visited);
        visited[i] = false;
    }

    if (alp != "")
    {
        s.insert(stoi(alp));
    }
}

int solution(string numbers)
{
    int answer = 0;
    vector<char> v;
    bool visited[10] = {
        false,
    };
    memset(decimal, true, sizeof(decimal));
    for (int i = 2; i < sqrt(10000002); i++)
    {
        for (int j = i + i; j < 10000002; j += i)
        {
            decimal[j] = false;
        }
    }
    dfs(0, "", numbers, visited);

    for (int t : s)
    {

        if (t == 0 || t == 1 || t > 10000000)
        {
            continue;
        }
        if (decimal[t])
        {
            answer++;
        }
    }

    return answer;
}