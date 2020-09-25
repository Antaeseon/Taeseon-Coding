#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int size = number.size() - k;
    vector<char> v;
    for (int i = 0; i < number.size(); i++)
    {
        char cur = number[i];

        while (!v.empty() && k > 0)
        {
            if (v.back() < cur)
            {
                v.pop_back();
                k--;
            }
            else
            {
                break;
            }
        }
        v.push_back(cur);
    }

    for (int i = 0; i < size; i++)
    {
        answer += v[i];
    }

    return answer;
}