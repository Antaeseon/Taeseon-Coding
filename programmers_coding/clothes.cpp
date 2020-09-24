#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    int clo[31];
    memset(clo, 1, sizeof(clo));
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < 31; i++)
    {
        clo[i] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        cout << i << " : " << clo[i] << "#\n";
    }

    for (int i = 0; i < lost.size(); i++)
    {
        clo[lost[i]]--;
    }

    for (int i = 0; i < reserve.size(); i++)
    {
        clo[reserve[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        cout << i << " : " << clo[i] << "$\n";
    }

    for (int i = 1; i <= n; i++)
    {
        if (clo[i] > 1 && clo[i - 1] == 0)
        {
            clo[i]--;
            clo[i - 1]++;
        }

        if (clo[i] > 1 && clo[i + 1] == 0)
        {
            clo[i]--;
            clo[i + 1]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (clo[i])
            answer++;
    }
    return answer;
}