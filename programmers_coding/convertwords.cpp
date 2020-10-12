#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int minimum = 1e9;

void dfs(string cur, string target, int cnt, vector<string> words, map<string, int> &m)
{
    if (cur == target)
    {
        minimum = min(minimum, cnt);
        return;
    }
    for (int i = 0; i < words.size(); i++)
    {
        int t_cnt = 0;
        string next = words[i];

        for (int j = 0; j < cur.size(); j++)
        {
            if (cur[j] == next[j] && m[next] == 1)
            {
                t_cnt++;
            }
        }
        if (t_cnt == target.size() - 1)
        {
            m[next] = 2;
            dfs(next, target, cnt + 1, words, m);
            m[next] = 1;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < words.size(); i++)
    {
        m[words[i]] = 1;
    }
    if (m[target] == 0)
    {
        return 0;
    }

    dfs(begin, target, 0, words, m);

    return minimum;
}

int main()
{
    solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
}