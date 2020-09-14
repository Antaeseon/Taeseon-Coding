#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = s.length();

    for (int i = 1; i <= s.length(); i++)
    {
        int len = s.length();
        bool chk = false;
        for (int j = 0; j < s.length(); j++)
        {
            int count = 0;
            int k = j + i;
            while (1)
            {
                if (k + i > s.length())
                    break;

                if (s.substr(j, i) == s.substr(k, i))
                {
                    count++;
                }
                else
                {
                    j = k - 1;
                    break;
                }
                j += i;
                k += i;
                if (count == 1)
                {
                    len -= (i - 1);
                }
                else
                {
                    len -= i;
                }

                if (count == 9 || count == 99 || count == 999)
                {
                    len++;
                }
            }
        }
        answer = min(answer, len);
    }
    return answer;
}
