#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[21];

int solution(string name)
{
    int answer = 0;
    int index = 0;
    int lIndex = 0;
    int rIndex = 0;
    int rPaddIndex = 0;
    int minimum = 0;
    int lMin = 1e9;
    for (int i = 0; i < name.size(); i++)
    {
        int res = name[i] - 'A';
        res = min(res, 26 - res);
        int n = name.size() - i;
        if (i < name.size() / 2)
        {
            if (res != 0)
            {
                lIndex = i;
                if (i != 0)
                {
                    lMin = min(i, lMin);
                }
            }
        }
        else
        {
            if (res != 0)
            {
                rIndex = max(rIndex, n);
                rPaddIndex = i;
            }
        }
        answer += res;
    }

    int sum = 0;
    if (lIndex < rIndex)
    {
        sum = lIndex * 2 + rIndex;
    }
    else
    {
        sum = rIndex * 2 + lIndex;
    }
    cout << lMin << "\n";
    minimum = min(int(name.size() - 1), sum);
    minimum = min(minimum, rPaddIndex);
    if (lMin != 1e9)
        minimum = min(minimum, int(name.size() - lMin));
    // 0 0 1 (3)1 1 1 0 0 0 // 사이즈 9 -인덱스/
    return answer + minimum;
}