#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> m;
int minimum = 1e9;

void dfs(string cur, string target, int cnt, vector<string> words)
{
    if (cur == target)
    {
        minimum = min(minimum, cnt);
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        bool flag = false;

        for (int j = 0; j < cur.size(); j++)
        {
            string next = words[i];
            if (cur[j] == next[j] && m[next] == 1)
            {
                m[next] = 2;
                dfs(next, target, cnt + 1, words);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    for (int i = 0; i < words.size(); i++)
    {
        m[words[i]] = 1;
    }
    if (m[begin] == 0)
    {
        return 0;
    }

    dfs(begin, target, 0, words);

    return answer;
}