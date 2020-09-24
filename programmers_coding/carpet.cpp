#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int sum = brown + yellow;

    for (int c = 1; c <= sum / 2; c++)
    {
        if (sum % c == 0)
        {
            int w = sum / c;
            if (c * w - (c - 2) * (w - 2) == brown)
            {
                answer.push_back(w);
                answer.push_back(c);
                break;
            }
        }
    }
    return answer;
}